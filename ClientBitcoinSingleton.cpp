#include <glog/logging.h>

#include "ClientBitcoinSingleton.h"

using namespace std;
using namespace cppproperties;
using namespace spyCBlockRPC;

spyCBlockRPC::ClientBitcoinSingleton::ClientBitcoinSingleton()
{
  this->config = PropertiesParser::Read(this->getRootPath() + "/conf-rpc.properties");

  string user = config.GetProperty(USER);
  string pass = config.GetProperty(PASS);
  string ip = config.GetProperty(HOST);
  int port = stoi(config.GetProperty(PORT));
  LOG(ERROR) << "Configuartion bitcoin rpc"
             << "\nusername: " << user
             << "\npassword: " << pass
             << "\nip: " << ip
             << "\nport: " << port;

  this->dirLogTest = config.GetProperty(DIR_LOG_TEST);
  this->dirDatatest = config.GetProperty(DIR_DATA_TEST);
  LOG(INFO) << "The dir for log test is: " << dirLogTest
            << " and the data dir is: " << dirDatatest;

  bitcoinApi = BitcoinAPI{user, pass, ip, port};

}

std::string ClientBitcoinSingleton::getDirDatatest() const
{
  return dirDatatest;
}

std::string ClientBitcoinSingleton::getDirLogTest() const
{
  return dirLogTest;
}

BitcoinAPI ClientBitcoinSingleton::getBitcoinApi() const
{
  return bitcoinApi;
}
