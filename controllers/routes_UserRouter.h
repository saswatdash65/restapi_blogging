#pragma once

#include <drogon/HttpController.h>

using namespace drogon;
using namespace std;

namespace api
{
  namespace v1
  {
    namespace user
    {
      struct User {
        string name;
        string email;
        string password;
      };

      class UserRouter : public drogon::HttpController<UserRouter>
      {
        public:
          METHOD_LIST_BEGIN
          METHOD_ADD(UserRouter::newUser, "/signup", Post, "api::v1::CORSMiddleware");
          METHOD_ADD(UserRouter::login, "/signin", Post, "api::v1::CORSMiddleware");
          METHOD_LIST_END

          void newUser(const HttpRequestPtr &req,
                      function<void (const HttpResponsePtr &res)> &&callback) const;
          void login(const HttpRequestPtr &req,
                      function<void (const HttpResponsePtr &res)> &&callback) const;
      };
    }
  }
}
