#include <glog/logging.h>

#include "DecodeRawTransaction.h"

using namespace std;

void spyCBlockRPC::DecodeRawTransaction::doCommand(spyCBlockRPC::WrapperInformations &wrapper, BitcoinAPI &bitcoinApi)
{
  string hashPreviousTx = wrapper.getHashPreviousTx();
  LOG(INFO) << "The previus hash is: " << hashPreviousTx;
  bool coinbase = false;
  if(hashPreviousTx.empty())
  {
    coinbase = true;
    LOG(INFO) << "Coinbase transaction";
  }

  if(!coinbase)
  {
    getrawtransaction_t txInfo = bitcoinApi.getrawtransaction(hashPreviousTx, 1);
    decoderawtransaction_t txRaw = bitcoinApi.decoderawtransaction(txInfo.hex);
    uint64_t nOutpoint = wrapper.getNOutpoint();
    LOG(INFO) << "OutPoint I will find is: " << nOutpoint;
    for(vout_t txOut : txRaw.vout)
    {
      if(txOut.n == nOutpoint)
      {
        LOG(WARNING) << "Findend transaction output";
        wrapper.setFrom(txOut.scriptPubKey.hex);
        break;
      }
    }
  }

}
