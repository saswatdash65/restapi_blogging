#include <drogon/drogon.h>
using namespace drogon;
int main() {
    //Set HTTP listener address and port
    app().addListener("0.0.0.0", 5555);
    //Load config file
    app().loadConfigFile("./config.json");
    //drogon::app().loadConfigFile("../config.yaml");
    //Run HTTP framework,the method will block in the internal event loop

    app().setThreadNum(4);
    app().run();

    
    return 0;
}
