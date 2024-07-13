#include <drogon/HttpMiddleware.h>

using namespace drogon;

namespace api {
    namespace v1 {
        class CORSMiddleware: public HttpMiddleware<CORSMiddleware> {
            public:
            CORSMiddleware();

            inline void invoke(const HttpRequestPtr &req,
                            MiddlewareNextCallback &&nextCallBack,
                            MiddlewareCallback &&callback) override;
        };
    }
}