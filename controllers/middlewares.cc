#include "middlewares.h"
#include <jwt-cpp/jwt.h>

using namespace drogon;
using namespace std;
using namespace jwt;

namespace api {
    namespace v1 {

            CORSMiddleware::CORSMiddleware() {}

            inline void CORSMiddleware::invoke(const HttpRequestPtr &req,
                            MiddlewareNextCallback &&nextCallBack,
                            MiddlewareCallback &&callback) {
                
                const string origin = req->getHeader("origin");
                if (origin.find("www.mydomain.com") == string::npos)
                {
                    callback(HttpResponse::newNotFoundResponse(req));
                    return;
                }
                nextCallBack([callback = move(callback), origin](const HttpResponsePtr &resp) {
                    resp->addHeader("Access-Control-Allow-Origin", origin);
                    resp->addHeader("Access-Control-Allow-Credentials","true");
                    callback(resp);
                });
            }
    }
}