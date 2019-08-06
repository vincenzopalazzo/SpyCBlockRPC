#include <bitcoinapi/bitcoinapi.h>
#include <glog/logging.h>

#include "DecodeScriptCommand.h"
#include "../ConfiguratorSingleton.h"

using namespace spyCBlockRPC;
using namespace std;

void DecodeScriptCommand::doCommand(WrapperInformations &wrapper, BitcoinAPI &bitcoinApi)
{

  string scriptSig = wrapper.getFrom();
  string scriptPubKey = wrapper.getTo();
  //decodescript_t respose = bitcoinApi.decodescript(scriptSig);
  //BitcoinAPI client = ClientBitcoinSingleton::getInstance().getBitcoinApi();
  decodescript_t respose = bitcoinApi.decodescript(scriptSig);
  //The inpurt can be n and not one
  vector<string> addressesInput;
  if(respose.addresses.empty())
  {
    //Coinbase
    addressesInput.emplace_back("Coinbase");
  }else{
    addressesInput = respose.addresses;
  }

  LOG(ERROR) << "P2P script inside the ScriptSing: " << respose.p2sh;

  LOG(INFO) << "The input address are: " << addressesInput.size();
  wrapper.setFromIdWallets(addressesInput);
  respose = bitcoinApi.decodescript(scriptPubKey);
  //respose = bitcoinApi.decodescript(scriptPubKey);
  vector<string> adressesOutput = respose.addresses;
  LOG(INFO) << "The output address are: " << adressesOutput.size();
  wrapper.setToIdWallets(adressesOutput);
  return;
}
