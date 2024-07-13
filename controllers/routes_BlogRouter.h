#pragma once

#include <drogon/HttpController.h>

using namespace drogon;
using namespace std;

namespace api
{
  namespace v1 
  {
    namespace blog 
    {
      struct blog_post {
        string title;
        string content;
        string authorId;
      };

      class BlogRouter : public drogon::HttpController<BlogRouter>
      {
        public:
          METHOD_LIST_BEGIN
          METHOD_ADD(BlogRouter::get_bulk, "/bulk", Get, "api::v1::CORSMiddleware", "api::v1::blog::LoginFilter");
          METHOD_ADD(BlogRouter::get_post, "/?id={id}", Get, "api::v1::CORSMiddleware", "api::v1::blog::LoginFilter");
          METHOD_ADD(BlogRouter::post_blog, "/", Post, "api::v1::CORSMiddleware", "api::v1::blog::LoginFilter");
          METHOD_ADD(BlogRouter::update_blog, "/", Put, "api::v1::CORSMiddleware", "api::v1::blog::LoginFilter");
          METHOD_LIST_END

          void get_bulk(const HttpRequestPtr &req, 
                        function<void (const HttpResponsePtr &)> &&callback) const;
          void get_post(const HttpRequestPtr &req, 
                        function<void (const HttpResponsePtr &)> &&callback, 
                        string &&id) const;
          void post_blog(const HttpRequestPtr &req,
                        function<void (const HttpResponsePtr &)> &&callback) const;
          void update_blog(const HttpRequestPtr &req,
                        function<void (const HttpResponsePtr &)> &&callback) const;
      };
    }
    
  }
}
