// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.txt

#include <glog/logging.h>

#include "HeightBlockchainCommand.h"

void spyCBlockRPC::HeightBlockchainCommand::doCommand(spyCBlockRPC::WrapperInformations &wrapper, BitcoinAPI &bitcoinApi)
{
   int count = bitcoinApi.getblockcount();
   LOG(INFO) << "Height blockchain: " << count;
   wrapper.setHeightBlockchain(count);
}
