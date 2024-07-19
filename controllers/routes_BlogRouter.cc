#include "routes_BlogRouter.h"
#include "Articles.h"
#include <json/json.h>
#include <drogon/orm/Mapper.h>
#include <drogon/orm/DbClient.h>
#include <vector>

using namespace api::v1::blog;
using namespace std;
using namespace drogon_model::blogweb;
using namespace drogon::orm;

void handleErrorResponce(HttpStatusCode code, const string &error,
                        AdviceCallback callback) {
    HttpResponsePtr res;
    res->setStatusCode(code);
    Json::Value error_resp;
    error_resp["error"] = error;
    callback(res->newHttpJsonResponse(error_resp));
}

void BlogRouter::get_bulk(const HttpRequestPtr &req,
                    function<void (const HttpResponsePtr &)> &&callback) const {
    
    DbClientPtr client = drogon::app().getFastDbClient();
    Mapper<Articles> mp(client);
    mp.findAll([&](vector<Articles> articles) {
        Json::Value posts;
        for (const Articles &article : articles) 
            posts.append(article.toJson());
        HttpResponsePtr res;
        res->setStatusCode(drogon::k200OK);
        callback(res->newHttpJsonResponse(posts));
    }, [&](const DrogonDbException &e) {
        handleErrorResponce(k500InternalServerError, "Failed to fetch posts", callback);
    });
}

void BlogRouter::get_post(const HttpRequestPtr &req, 
                        function<void (const HttpResponsePtr &)> &&callback, 
                        string &&id) const {

    DbClientPtr client = drogon::app().getFastDbClient();
    Mapper<Articles> mp(client);
    const Articles post = mp.findOne(Criteria("id", CompareOperator::EQ, id));

    if (&post != nullptr) {
        HttpResponsePtr res;
        callback(res->newNotFoundResponse());
        return;
    }

    HttpResponsePtr res;
    res->setStatusCode(drogon::k200OK);
    callback(res->newHttpJsonResponse(post.toJson()));
}

void BlogRouter::post_blog(const HttpRequestPtr &req,
                        function<void (const HttpResponsePtr &)> &&callback) const {
    
    string userid = req->getHeader("Authorization");
    Json::Value blog = req->getJsonObject().get();
    blog["authorid"] = userid;
    if (userid.empty()) {
        handleErrorResponce(k400BadRequest, "No user id provided!", callback);
        return;
    }
    userid = userid.substr(7, userid.length() - 1);

    DbClientPtr client = drogon::app().getFastDbClient();
    Mapper<Articles> mp(client);
    Articles new_post = Articles(blog);

    mp.insert(new_post, [&](const Articles post) {
        Json::Value message;
        message["id"] = post.getValueOfAuthorid();
        HttpResponsePtr res;
        res->setStatusCode(drogon::k201Created);
        callback(res->newHttpJsonResponse(message));
    }, [&](const DrogonDbException &e) {
        handleErrorResponce(k500InternalServerError, "Failed to publish post", callback);
    });
}

void BlogRouter::update_blog(const HttpRequestPtr &req,
                        function<void (const HttpResponsePtr &)> &&callback) const {
    
    Json::Value updated_post = req->getJsonObject().get();
    Json::Value updated_;
    string userid = req->getHeader("Authorization");
    userid = userid.substr(7, userid.length() - 1);
    updated_["title"] = updated_post["title"].asString();
    updated_["content"] = updated_post["content"].asString();

    if (userid.empty() || updated_["title"].asString().empty() || updated_["content"].asString().empty()) {
        handleErrorResponce(k400BadRequest, "Missing required fields", callback);
        return;
    }

    DbClientPtr client = drogon::app().getFastDbClient();
    Mapper<Articles> mp(client);
    Json::Value::Members members;

    mp.updateBy(updated_.getMemberNames(), 
    Criteria("authorId", CompareOperator::EQ, userid) && Criteria("id", CompareOperator::EQ, updated_post["id"].asString()),
    updated_["title"].asString(), updated_["content"].asString());

    HttpResponsePtr res;
    res->setStatusCode(drogon::k201Created);
    res->setContentTypeCodeAndCustomString(drogon::CT_TEXT_PLAIN, "updated post");
    callback(res);
}