#ifndef DECODESCRIPTCOMMAND_H
#define DECODESCRIPTCOMMAND_H

#include "IRPCCommand.h"

namespace spyCBlockRPC {

    class DecodeScriptCommand : IRPCCommand
    {
        public:
            std::string doCommand(std::string &input) override;
    };
}

#endif // DECODESCRIPTCOMMAND_H
