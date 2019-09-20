#ifndef CLIENTBITCOINSINGLETON_H
#define CLIENTBITCOINSINGLETON_H

#include <string>
#include <experimental/filesystem>

#include <bitcoinapi/bitcoinapi.h>

#include "../lib/cpp-properties/include/Properties.h"
#include "../lib/cpp-properties/include/PropertiesParser.h"

namespace spyCBlockRPC {

    class ConfiguratorSingleton
    {
        public:
            static ConfiguratorSingleton& getInstance()
            {
                static ConfiguratorSingleton SINGLETON;

                return SINGLETON;
            }

            std::string getDirLogTest() const;

            std::string getDirDatatest() const;

            std::string getUser() const;

            std::string getPassword() const;

            std::string getHost() const;

            int getPort() const;

    private:

            const std::string USER = "USER";
            const std::string PASS = "PASS";
            const std::string HOST = "HOST";
            const std::string PORT = "PORT";
            const std::string DIR_LOG_TEST = "DIR_LOG_TEST";
            const std::string DIR_DATA_TEST = "DIR_DATA_TEST";

            ConfiguratorSingleton();

            cppproperties::Properties config = cppproperties::PropertiesParser::Read(this->getRootPath() + "/conf-rpc.properties");
            std::string dirLogTest;
            std::string dirDatatest;

            inline std::string getRootPath(){
                return std::experimental::filesystem::current_path();
            }


    };

}

#endif // CLIENTBITCOINSINGLETON_H
