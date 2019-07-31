#include <bitcoinapi/bitcoinapi.h>

#include "DecodeScriptCommand.h"
#include "../ClientBitcoinSingleton.h"

using namespace spyCBlockRPC;
using namespace std;

std::string spyCBlockRPC::DecodeScriptCommand::doCommand(std::string &input)
{
  BitcoinAPI bitcoinApi = ClientBitcoinSingleton::getInstance().getBitcoinApi();
  decodescript_t respose = bitcoinApi.decodescript(input);
  //The inpurt can be n and not one
  return "TODO LOOK in this class";
}
