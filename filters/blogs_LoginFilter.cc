#include "blogs_LoginFilter.h"
#include <json/json.h>
#include <jwt-cpp/jwt.h>

using namespace drogon;
using namespace api::v1::blog;
using namespace jwt;
using namespace std;

void LoginFilter::doFilter(const HttpRequestPtr &req,
                         FilterCallback &&fcb,
                         FilterChainCallback &&fccb)
{
    const string auth = req->getHeader("Authorization");
    if (!auth.empty()) {
        string token = auth.substr(7, auth.length() - 1);
        decoded_jwt decoded = decode(token);

        verifier ver = verify().allow_algorithm(algorithm::hs256{"your-secret-public-key"});
        try
        {
            ver.verify(decoded);
        }
        catch(const exception &e)
        {
            Json::Value msg;
            msg["message"] = "You are not logged in";
            HttpResponsePtr res = HttpResponse::newHttpJsonResponse(msg);
            res->setStatusCode(k401Unauthorized);
            fcb(res);
            return;
        }
        
        fccb();
    }

    //Check failed
    Json::Value msg;
    msg["message"] = "Unauthorized";
    auto res = HttpResponse::newHttpJsonResponse(msg);
    res->setStatusCode(k401Unauthorized);
    fcb(res);
}
