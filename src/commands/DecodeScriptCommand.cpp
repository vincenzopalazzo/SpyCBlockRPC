// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.txt

#include <bitcoinapi/bitcoinapi.h>
#include <glog/logging.h>

#include "DecodeScriptCommand.h"
#include "RPCCommandMediator.h"
#include "../ConfiguratorSingleton.h"
#include "../SpyCBlockRPCException.h"

using namespace spyCBlockRPC;
using namespace std;

DecodeScriptCommand::DecodeScriptCommand() : IRPCCommand()
{}

void DecodeScriptCommand::doCommand(WrapperInformations &wrapper, BitcoinAPI &bitcoinApi)
{
  try {
    DecodeRawTransaction decodeRawTxCommand;
    decodeRawTxCommand.doCommand(wrapper, bitcoinApi);

    string scriptSig = wrapper.getFrom();
    string scriptPubKey = wrapper.getTo();

    decodescript_t respose;

    vector<string> addressesInput;
    if(scriptSig != "Coinbase"){
      respose = bitcoinApi.decodescript(scriptSig);
      addressesInput = respose.addresses;
      LOG(WARNING) << "P2P script inside the ScriptSing: " << respose.p2sh;
    }else{
        addressesInput.emplace_back(scriptSig);
    }

    LOG(INFO) << "The input address are/is: " << addressesInput.size();
    wrapper.setFromIdWallets(addressesInput);
    respose = bitcoinApi.decodescript(scriptPubKey);
    vector<string> adressesOutput = respose.addresses;
    LOG(INFO) << "The output address are: " << adressesOutput.size();
    wrapper.setToIdWallets(adressesOutput);
  } catch (BitcoinException btcEx) {
    throw SpyCBlockRPCException(btcEx.getMessage());
  }

}
