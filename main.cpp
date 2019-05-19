#include <iostream>

#include <PropertiesParser.h>
#include <glog/logging.h>
#include <bitcoinapi/bitcoinapi.h>
#include "Properties.h"

using namespace std;
using namespace cppproperties;

int main() {
    google::InitGoogleLogging("0");
    FLAGS_minloglevel = 0;
    FLAGS_logtostderr = true;

    Properties configuartion = PropertiesParser::Read("/home/vincenzo/Github/SpyCBlockRPC/bitcoinrpc.properties");
    LOG(INFO) << "The username of module rpc: "  << configuartion.GetProperty("user");
    LOG(INFO) << "The password for the module rpc: " << configuartion.GetProperty("password");
    LOG(INFO) << "The ip for the module rpc: " << configuartion.GetProperty("address");
    LOG(INFO) << "The port for the module rpc: " << configuartion.GetProperty("port");

    string user = configuartion.GetProperty("user");
    string pass = configuartion.GetProperty("password");
    string ip = configuartion.GetProperty("address");
    int port = stoi(configuartion.GetProperty("port"));
    LOG(INFO) << "The conversion to string into int " << configuartion.GetProperty("port") << "=" << port;

    try{
        BitcoinAPI btc(user, pass, ip, port);
        int numbarBlock = btc.getblockcount();
        LOG(WARNING) << "The height bitcoin-core is: " << numbarBlock;
    }catch (BitcoinException e){
        LOG(ERROR) << "The exception generate is: " << e.what();
    }
    return 0;
}