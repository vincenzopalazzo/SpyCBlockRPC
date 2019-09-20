#include <iostream>
#include <string>
#include <glog/logging.h>
#include <bitcoinapi/bitcoinapi.h>
#include <fstream>

#include "commands/RPCCommandMediator.h"

using namespace std;
using namespace spyCBlockRPC;

int main() {
    google::InitGoogleLogging("2");
    FLAGS_minloglevel = 2;
    FLAGS_logtostderr = false;

    try
    {

      WrapperInformations wrapper;
      wrapper.setDelimitator("|-|");

      RPCCommandMediator::getInstance().doCommand(RPCCommandMediator::getInstance().DECODE_BLOCKS_COMMAND, wrapper);

    }catch (BitcoinException e){
        LOG(ERROR) << "The exception generate is: " << e.getMessage();
    }
    return 0;
}

