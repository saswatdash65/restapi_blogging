#include "routes_UserRouter.h"
#include "Users.h"
#include "encrypts.h"
#include <drogon/orm/DbClient.h>
#include <drogon/orm/Exception.h>
#include <drogon/orm/Mapper.h>
#include <json/json.h>
#include <jwt-cpp/jwt.h>
#include <vector>

using namespace api::v1::user;
using namespace std;
using namespace drogon::orm;
using namespace drogon_model::blogweb;
using namespace drogon;
using namespace jwt;

void handleErrorResponce(HttpStatusCode code, const string &error,
                        AdviceCallback &&callback) {
    HttpResponsePtr res;
    res->setStatusCode(code);
    Json::Value error_resp;
    error_resp["error"] = error;
    callback(res->newHttpJsonResponse(error_resp));
}

void UserRouter::newUser(const HttpRequestPtr &req,
          function<void (const HttpResponsePtr &)> &&callback) const {
     
    DbClientPtr client = app().getFastDbClient();
    Mapper<Users> mp(client);

    Json::Value body = req->getJsonObject().get();
    if (!body.isMember("username") || !body["username"].isString() ||
        !body.isMember("password") || !body["password"].isString() ||
        !body.isMember("email") || !body["email"].isString()) {
        
        handleErrorResponce(k400BadRequest, "Invalid input", callback);
        return;
    }

    Users new_user(body);
    new_user.setPassword(body["password"].asString());
    try {
        mp.insert(new_user);
    } catch (const UniqueViolation &e) {

        handleErrorResponce(k409Conflict, "Username or email already exists", callback);
        return;
    } catch (const InternalError &e) {

        handleErrorResponce(k500InternalServerError, "Internal server Error", callback);
        return;
    } catch (const ArgumentError &e) {
        handleErrorResponce(k400BadRequest, "Invalid input", callback);
        return;
    }
    
    builder token = create()
        .set_payload_claim("id", new_user.getValueOfId())
        .sign(algorithm::hs256{"your_public_secret_key"});
    Json::Value jwt_res;
    jwt_res["token"] = token.encoded();

    HttpResponsePtr res;
    res->setStatusCode(k201Created);
    callback(res->newHttpJsonResponse(jwt_res));    
}

void UserRouter::login(const HttpRequestPtr &req,
          function<void (const HttpResponsePtr &)> &&callback) const {

    DbClientPtr client = app().getFastDbClient();
    Mapper<Users> mp(client);

    Json::Value body = req->getJsonObject().get();
    if (!body.isMember("password") || !body["password"].isString() ||
        !body.isMember("email") || !body["email"].isString()) {
        
        handleErrorResponce(k400BadRequest, "invalid request", callback);
        return;
    }
    try {
        Users login_user = mp.findOne(Criteria("email", CompareOperator::EQ, body["email"]));
        string pass = encrypt_password(shared_ptr<string>(*body["password"].asString()));
        if (login_user.getValueOfPassword() != pass) 
            throw invalid_argument("");
    } catch (const exception &e) {
        handleErrorResponce(k403Forbidden, "Wrong email or password", callback);
        return;
    }
    
    builder new_token = create()
        .set_payload_claim("id", login_user.getValueOfId())
        .sign(algorithm::hs256{"your_public_secret_key"});
    Json::Value jwt_res;
    jwt_res["jwt"] = new_token.encoded();

    HttpResponsePtr res;
    res->setStatusCode(k200OK);
    callback(res->newHttpJsonResponse(jwt_res));
}