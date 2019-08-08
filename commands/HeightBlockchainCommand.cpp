#include <glog/logging.h>

#include "HeightBlockchainCommand.h"

void spyCBlockRPC::HeightBlockchainCommand::doCommand(spyCBlockRPC::WrapperInformations &wrapper, BitcoinAPI &bitcoinApi)
{
   int count = bitcoinApi.getblockcount();
   LOG(INFO) << "Height blockchain: " << count;

   wrapper.setHeightBlockchain(count);
}
