/**
 *
 *  api_v1_blog_LoginFilter.h
 *
 */

#pragma once

#include <drogon/HttpFilter.h>
using namespace drogon;
namespace api
{
  namespace v1
  {
    namespace blog
    {
      class LoginFilter : public HttpFilter<LoginFilter>
      {
        public:
          LoginFilter() {}
          void doFilter(const HttpRequestPtr &req,
                        FilterCallback &&fcb,
                        FilterChainCallback &&fccb) override;
      };
    }
  }
}
