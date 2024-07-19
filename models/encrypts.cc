#include "encrypts.h"
#include <memory>
#include <openssl/sha.h>
#include <iomanip>

using namespace std;

string drogon_model::blogweb::encrypt_password(shared_ptr<string> &password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, (*password).c_str(), (*password).size());
    SHA256_Final(hash, &ctx);

    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        ss << hex << setw(2) << setfill('0') << static_cast<int>(hash[i]);

    *password = ss.str();
    return *password;
}