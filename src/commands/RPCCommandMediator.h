#ifndef RPCCOMMANDMEDIATOR_H
#define RPCCOMMANDMEDIATOR_H

#include <map>
#include <string>

#include <bitcoinapi/bitcoinapi.h>

#include "IRPCCommand.h"
#include "DecodeScriptCommand.h"
#include "DecodeRawTransaction.h"
#include "DecodeBlockAtIndexCommand.h"
#include "../ConfiguratorSingleton.h"

//TODO add an personal exception
namespace spyCBlockRPC
{
  class RPCCommandMediator
  {

    public:
       const std::string DECODE_SCRIPT_COMMAND = "DECODE_SCRIPT_COMMAND";

       const std::string DECODE_RAW_TX_COMMAND = "DECODE_RAW_TX_COMMAND";

       const std::string DECODE_BLOCKS_COMMAND = "DECODE_BLOCKS_COMMAND";

      inline static RPCCommandMediator& getInstance()
      {
        static RPCCommandMediator SINGLETON;

        return SINGLETON;
      }

      inline void doCommand(std::string keyCommand, WrapperInformations &wrapper)
      {
        if(keyCommand.empty())
        {
            // create exception
            return;
        }

        if(keyCommand == DECODE_SCRIPT_COMMAND)
        {
          decodeScript.doCommand(wrapper, bitcoinApi);
          return;
        }

        if(keyCommand == DECODE_RAW_TX_COMMAND)
        {
          decodeRawTx.doCommand(wrapper, bitcoinApi);
        }

        if(keyCommand == DECODE_BLOCKS_COMMAND)
        {
          DecodeBlockAtIndexCommand decodeBlock;
          decodeBlock.doCommand(wrapper, bitcoinApi);
        }

        //Throws an exeption
        return;
      }

      inline void closeConnectionWithNode(){
        bitcoinApi.stop();
      }

  private:

      RPCCommandMediator() : bitcoinApi(ConfiguratorSingleton::getInstance().getUser(),
                                        ConfiguratorSingleton::getInstance().getPassword(),
                                        ConfiguratorSingleton::getInstance().getHost(),
                                        ConfiguratorSingleton::getInstance().getPort()){}

      //Commands
      DecodeScriptCommand decodeScript;

      DecodeRawTransaction decodeRawTx;

      //Bitcoin api
      BitcoinAPI bitcoinApi;

  };

}

#endif // RPCCOMMANDMEDIATOR_H
