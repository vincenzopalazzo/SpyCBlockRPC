#ifndef DECODESCRIPTCOMMAND_H
#define DECODESCRIPTCOMMAND_H

#include "IRPCCommand.h"

namespace spyCBlockRPC {

    class DecodeScriptCommand : IRPCCommand
    {
        public:

          void doCommand(WrapperInformations &wrapper) override;
    };
}

#endif // DECODESCRIPTCOMMAND_H
