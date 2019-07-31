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

    private:

            const std::string USER = "USER";
            const std::string PASS = "PASS";
            const std::string HOST = "HOST";
            const std::string PORT = "PORT";

            ClientBitcoinSingleton();

            cppproperties::Properties config;

            BitcoinAPI bitcoinApi{"", "", "", 1}; //TODO chanhe this

            inline std::string getRootPath(){
                return std::experimental::filesystem::current_path();
            }


    };

}

#endif // CLIENTBITCOINSINGLETON_H
