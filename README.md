Blog website backend
====================

This is the backend of a medium like website made with C++

Features:
- Create, Delete and Update blog posts
- Sign up and login as a user

## Requirements to run
- C++ standerd 17
- CMake version >= 3.5
- Drogon Framework
- Libraries: Trantor, OpenSSL, jwt-cpp

Run the following commands to clone and run the server in local environment

    git clone https://github.com/saswatdash65/restapi_blogging.git
    cd restapi_blogging
    mkdir build
    cmake -B build
    cd build
    make
    ./blog_server
