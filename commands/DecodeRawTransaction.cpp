#include <glog/logging.h>

#include "DecodeRawTransaction.h"

using namespace std;

void spyCBlockRPC::DecodeRawTransaction::doCommand(spyCBlockRPC::WrapperInformations &wrapper, BitcoinAPI &bitcoinApi)
{
  string hashPreviousTx = wrapper.getHashPreviousTx();
  LOG(INFO) << "The previus hash is: " << hashPreviousTx;
  bool coinbase = false;
  if(hashPreviousTx == HASH_COINBASE)
  {
    coinbase = true;
    LOG(INFO) << "Coinbase transaction";
    wrapper.setFrom("Coinbase");
  }

  if(!coinbase)
  {
    LOG(INFO) << "No coinbase transaction";
    getrawtransaction_t txInfo = bitcoinApi.getrawtransaction(hashPreviousTx, 1);
    decoderawtransaction_t txRaw = bitcoinApi.decoderawtransaction(txInfo.hex);
    uint64_t nOutpoint = wrapper.getNOutpoint();
    string btcValue = toBtc(nOutpoint);
    LOG(INFO) << "OutPoint I will find is: " << nOutpoint;
    /*
    for(vout_t txOut : txRaw.vout)
    {
      LOG(INFO) << "RPC value bitcoin -> " << txOut.value;
      LOG(INFO) << "RPC value converted bitcoin -> " << toSatoshi(txOut.value);
      LOG(INFO) << "WRAPPER value bitcoin -> " << nOutpoint;
      if(toSatoshi(txOut.value) == static_cast<long>(nOutpoint))
      {
        LOG(WARNING) << "Findend transaction output";
        wrapper.setFrom(txOut.scriptPubKey.hex);
        break;
      }
    }*/
    vout_t txOut = txRaw.vout.at(nOutpoint);
    LOG(ERROR) << "VALUE -> " << txOut.value;
    wrapper.setFrom(txOut.scriptPubKey.hex);
   }
}


string spyCBlockRPC::DecodeRawTransaction::toBtc(uint64_t &satoshi)
{
  auto s = to_string(satoshi);

  if (s.length() < 8) {
    // Prefix with 0s
    s.insert(0, (8 - s.length()), '0');
    s.insert(0, "0.", 2);
  } else if (s.length() == 8) {
    s.insert(0, "0.", 2);
  } else {
    // Insert a '.' in the right place
    s.insert(s.length() - 8, 1, '.');
  }
  return s;
}

long spyCBlockRPC::DecodeRawTransaction::toSatoshi(double &btc)
{
  return btc * 100000000;
}
