#ifndef RPCCOMMANDMEDIATOR_H
#define RPCCOMMANDMEDIATOR_H

#include <map>
#include <string>
#include <bits/shared_ptr.h>

#include "IRPCCommand.h"

namespace spyCBlockRPC
{
  class RPCCommandMediator
  {

    public:
      RPCCommandMediator();


    private:

      const std::string DECODE_SCRIPT_COMMAND = "DECODE_SCRIPT_COMMAND";

      std::map<std::string, IRPCCommand> commands;

  };

}

#endif // RPCCOMMANDMEDIATOR_H
