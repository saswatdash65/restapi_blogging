#include "routes_BlogRouter.h"
#include "Articles.h"
#include "Users.h"
#include <json/json.h>
#include <drogon/orm/Mapper.h>
#include <drogon/orm/DbClient.h>
#include <trantor/utils/Logger.h>
#include <vector>

using namespace api::v1::blog;
using namespace std;
using namespace drogon_model::blogweb;
using namespace drogon::orm;

void BlogRouter::get_bulk(const HttpRequestPtr &req,
                    function<void (const HttpResponsePtr &)> &&callback) const {
    
    DbClientPtr client = drogon::app().getFastDbClient();
    Mapper<Articles> mp(client);
    mp.findAll([&](vector<Articles> articles) {
        Json::Value posts;
        for (const Articles &article : articles) 
            posts.append(article.toJson());
        HttpResponsePtr res;
        callback(res->newHttpJsonResponse(posts));
    }, (const exception &e) -> {
        LOG_ERROR << e.what();
        HttpResponsePtr res;
        callback(res->newInternalErrorResponse("Failed to fetch posts"));
    });
}

void BlogRouter::get_post(const HttpRequestPtr &req, 
                        function<void (const HttpResponsePtr &)> &&callback, 
                        string &&id) const {

    DbClientPtr client = drogon::app().getFastDbClient();
    Mapper<Articles> mp(client);
    const Articles post = mp.findOne(Criteria("id", CompareOperator::EQ, id));

    if (!post) {
        HttpResponsePtr res;
        callback(res->newNotFoundResponse());
        return;
    }

    HttpResponsePtr res;
    callback(res->newHttpJsonResponse(post.toJson()));
}

void BlogRouter::post_blog(const HttpRequestPtr &req,
                        function<void (const HttpResponsePtr &)> &&callback) const {
    
    string userid = req->getHeader("Authorization");
    Json::Value blog = req->getJsonObject().get();
    blog["authorid"] = userid;
    if (userid.empty()) {
        HttpResponsePtr res;
        callback(res->newBadRequestResponse("No user ID provided"));
        return;
    }
    userid = userid.substr(7, userid.length() - 1);

    DbClientPtr client = drogon::app().getFastDbClient();
    Mapper<Articles> mp(client);
    Articles new_post = Articles(blog);

    mp.insert(new_post, [&](const Articles post) {
        Json::Value message;
        message["id"] = post.getAuthorid();
        HttpResponsePtr res;
        callback(res->newHttpJsonResponse(message));
    }, [](const exception &e) {
        LOG_ERROR << e.what();
        HttpResponsePtr res;
        callback(res->newInternalServerErrorResponse("Failed to insert post"));
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

    if (userid.empty() || title.empty() || content.empty()) {
        HttpResponsePtr res;
        callback(res->newBadRequestResponse("Missing required fields"));
        return;
    }

    DbClientPtr client = drogon::app().getFastDbClient();
    Mapper<Articles> mp(client);
    Json::Value::Members members();

    mp.updateBy(updated_.getMemberNames(), 
    Criteria("authorId", CompareOperator::EQ, userid) && Criteria("id", CompareOperator::EQ, updated_post["id"].asString()),
    updated_["title"].asString, updated_["content"].asString);

    HttpResponsePtr res;
    res->setContentTypeCodeAndCustomString(drogon::CT_TEXT_PLAIN, "updated post")
    callback(res)
}