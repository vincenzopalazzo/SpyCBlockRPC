// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.txt

#include <iostream>
#include <string>
#include <glog/logging.h>
#include <bitcoinapi/bitcoinapi.h>
#include <fstream>

#include "commands/RPCCommandMediator.h"
#include "SpyCBlockRPCException.h"

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

    }catch (SpyCBlockRPCException ex){
        LOG(ERROR) << "The exception generate is: " << ex.what();
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

