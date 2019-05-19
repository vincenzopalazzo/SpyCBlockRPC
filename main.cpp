#include <iostream>
#include <string>
#include <limits.h>
#include <unistd.h>
#include <experimental/filesystem>

#include <PropertiesParser.h>
#include <glog/logging.h>
#include <bitcoinapi/bitcoinapi.h>
#include <fstream>
#include "Properties.h"
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

using namespace std;
using namespace cppproperties;
using namespace rapidjson;

void saveBlock(blockinfo_t &blockinfo);
string rootPath();

const string SCRIPT_OUTPUT_GENESIS_BLOCK = "4104678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5fac";
const string ORIGINAL_ADRESS = "1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa";

int main() {
    google::InitGoogleLogging("0");
    FLAGS_minloglevel = 0;
    FLAGS_logtostderr = true;


    Properties configuartion = PropertiesParser::Read(rootPath() + "/bitcoinrpc.properties");
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

        string hashGenesisBlock = btc.getblockhash(0);
        LOG(INFO) << "The hash genesis block is: " << hashGenesisBlock;

        blockinfo_t block = btc.getblock(hashGenesisBlock);
        saveBlock(block);

        //------ Test get script ------
        decodescript_t script = btc.decodescript(SCRIPT_OUTPUT_GENESIS_BLOCK);
        LOG(INFO) << "Numbar adredd into script: " << script.addresses.size();
        LOG(INFO) << "First address is: " << script.addresses.at(0);
        LOG(INFO) << "Is equal to " << ORIGINAL_ADRESS;

    }catch (BitcoinException e){
        LOG(ERROR) << "The exception generate is: " << e.what();
    }
    return 0;
}

string rootPath(){
    return experimental::filesystem::current_path();
}

void saveBlock(blockinfo_t &blockinfo){

    StringBuffer stringBuffer;
    Writer<StringBuffer> writer(stringBuffer);

    writer.String("Height");
    writer.Int(blockinfo.height);
    writer.String("Hash");
    writer.String(blockinfo.hash.c_str());
    writer.String("merkleroot");
    writer.String(blockinfo.merkleroot.c_str());
    writer.String("ntx");
    writer.Int(blockinfo.tx.size());
    writer.String("nonce");
    writer.Int(blockinfo.nonce);
    writer.String("previushash");
    writer.String(blockinfo.previousblockhash.c_str());
    ofstream stream(rootPath() + "/storage/genesisBlockRpc.json");
    stream << stringBuffer.GetString();
}