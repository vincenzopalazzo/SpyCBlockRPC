// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.txt

#include <glog/logging.h>

#include "DecodeRawTransaction.h"

using namespace std;

void spyCBlockRPC::DecodeRawTransaction::doCommand(spyCBlockRPC::WrapperInformations &wrapper, BitcoinAPI &bitcoinApi)
{
  string hashPreviousTx = wrapper.getHashPreviousTx();
  LOG(INFO) << "The previus hash is: " << hashPreviousTx;
  bool coinbase = false;
  if(hashPreviousTx == HASH_COINBASE){
    coinbase = true;
    LOG(INFO) << "Coinbase transaction";
    wrapper.setFrom("Coinbase");
  }

  if(!coinbase){
    LOG(INFO) << "No coinbase transaction";
    getrawtransaction_t txInfo = bitcoinApi.getrawtransaction(hashPreviousTx, 1); // the 1 number is for create an verbose result.
    uint64_t nOutpoint = wrapper.getNOutpoint();
    string btcValue = toBtc(nOutpoint);
    LOG(INFO) << "OutPoint I will find is: " << nOutpoint;
    vout_t txOut = txInfo.vout.at(nOutpoint);
    LOG(WARNING) << "VALUE -> " << txOut.value;
    wrapper.setFrom(txOut.scriptPubKey.hex);
   }
}


string spyCBlockRPC::DecodeRawTransaction::toBtc(uint64_t &satoshi)
{
  string s = to_string(satoshi);

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
  return static_cast<long>(btc * 100000000);
}
