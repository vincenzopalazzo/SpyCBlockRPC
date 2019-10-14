// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.tx

#ifndef RPCCOMMANDMEDIATOR_H
#define RPCCOMMANDMEDIATOR_H

#ifdef NDEBUG
#define ASSERT(condition, message) 0
#else
#define ASSERT(condition, message)\
   (!(condition)) ?\
      (std::cerr << "Assertion failed: (" << #condition << "), "\
      << "function " << __FUNCTION__\
      << ", file " << __FILE__\
      << ", line " << __LINE__ << "."\
      << std::endl << message << std::endl, abort(), 0) : 1
#endif

#include <map>
#include <string>
#include <memory>

#include <bitcoinapi/bitcoinapi.h>

#include "IRPCCommand.h"
#include "DecodeScriptCommand.h"
#include "DecodeRawTransaction.h"
#include "DecodeBlockAtIndexCommand.h"
#include "../ConfiguratorSingleton.h"

using Commands = std::map<std::string, std::shared_ptr<spyCBlockRPC::IRPCCommand>>;


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
        ASSERT(!keyCommand.empty(), "The key command is empty");

        auto iterator = commands.find(keyCommand);
        std::shared_ptr<IRPCCommand> commandSelected = iterator->second;

        ASSERT(iterator != commands.end(), "The key command " + keyCommand + " not found");

        commandSelected->doCommand(wrapper, bitcoinApi);
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

      //I can use the referent of the command without the map because I must be rapid in the find.
      //But the command maps is cooler and it about this choice the big if-then-else clause inside the method do command is bad
      //so, the computation time of the method map.find() = O(log(n)) for this lot of map is equal to O(1)
      Commands commands = {
        {DECODE_BLOCKS_COMMAND, std::shared_ptr<IRPCCommand>(new DecodeBlockAtIndexCommand())},
        {DECODE_RAW_TX_COMMAND, std::shared_ptr<IRPCCommand>(new DecodeRawTransaction())},
        {DECODE_SCRIPT_COMMAND, std::shared_ptr<IRPCCommand>(new DecodeScriptCommand())}
      };

      //Bitcoin api
      BitcoinAPI bitcoinApi;

  };

}

#endif // RPCCOMMANDMEDIATOR_H
