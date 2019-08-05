#ifndef RPCCOMMANDMEDIATOR_H
#define RPCCOMMANDMEDIATOR_H

#include <map>
#include <string>

#include "IRPCCommand.h"
#include "DecodeScriptCommand.h"

namespace spyCBlockRPC
{
  class RPCCommandMediator
  {

    public:
       const std::string DECODE_SCRIPT_COMMAND = "DECODE_SCRIPT_COMMAND";

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
          decodeScript.doCommand(wrapper);
          return;
        }

        //Throws an exeption
        return;
      }

    private:

      RPCCommandMediator(){}

      DecodeScriptCommand decodeScript;



  };

}

#endif // RPCCOMMANDMEDIATOR_H
