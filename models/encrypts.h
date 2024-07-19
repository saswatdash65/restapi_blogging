#pragma once
#include <memory>

using namespace std;

namespace drogon_model {
    namespace blogweb {
        string encrypt_password(shared_ptr<string> &password);
    }
}
