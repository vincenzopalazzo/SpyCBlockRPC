#ifndef CLIENTBITCOINSINGLETON_H
#define CLIENTBITCOINSINGLETON_H

#include <string>
#include <experimental/filesystem>

#include <bitcoinapi/bitcoinapi.h>

#include "lib/cpp-properties/include/Properties.h"
#include "lib/cpp-properties/include/PropertiesParser.h"

namespace spyCBlockRPC {

    class ClientBitcoinSingleton
    {
        public:
            static ClientBitcoinSingleton& getInstance()
            {
                static ClientBitcoinSingleton SINGLETON;

                return SINGLETON;
            }

            BitcoinAPI getBitcoinApi() const;

            std::string getDirLogTest() const;

            std::string getDirDatatest() const;

    private:

            const std::string USER = "USER";
            const std::string PASS = "PASS";
            const std::string HOST = "HOST";
            const std::string PORT = "PORT";
            const std::string DIR_LOG_TEST = "DIR_LOG_TEST";
            const std::string DIR_DATA_TEST = "DIR_DATA_TEST";

            ClientBitcoinSingleton();

            cppproperties::Properties config;
            std::string dirLogTest;
            std::string dirDatatest;

            BitcoinAPI bitcoinApi{"", "", "", 8332}; //TODO chanhe this resolve the problem, I don't want inizialize it with this code
            //BitcoinAPI bitcoinApi;

            inline std::string getRootPath(){
                return std::experimental::filesystem::current_path();
            }


    };

}

#endif // CLIENTBITCOINSINGLETON_H
