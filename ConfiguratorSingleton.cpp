#include <glog/logging.h>
#include "ConfiguratorSingleton.h"

using namespace std;
using namespace cppproperties;
using namespace spyCBlockRPC;

spyCBlockRPC::ConfiguratorSingleton::ConfiguratorSingleton()
{

  LOG(ERROR) << "Configuartion bitcoin rpc"
             << "\nusername: " << config.GetProperty(USER)
             << "\npassword: " << config.GetProperty(PASS)
             << "\nhost: " << config.GetProperty(HOST)
             << "\nport: " << config.GetProperty(PORT);

  this->dirLogTest = config.GetProperty(DIR_LOG_TEST);
  this->dirDatatest = config.GetProperty(DIR_DATA_TEST);
  LOG(INFO) << "The dir for log test is: " << dirLogTest
            << " and the data dir is: " << dirDatatest;
}

std::string ConfiguratorSingleton::getDirDatatest() const
{
  return dirDatatest;
}

string ConfiguratorSingleton::getUser() const
{
  return config.GetProperty(USER);
}

string ConfiguratorSingleton::getPassword() const
{
  return config.GetProperty(PASS);
}

string ConfiguratorSingleton::getHost() const
{
  return config.GetProperty(HOST);
}

int ConfiguratorSingleton::getPort() const
{
  return stoi(config.GetProperty(PORT));
}

std::string ConfiguratorSingleton::getDirLogTest() const
{
  return dirLogTest;
}

