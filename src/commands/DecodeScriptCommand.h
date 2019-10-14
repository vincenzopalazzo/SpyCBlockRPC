// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.tx
#ifndef DECODESCRIPTCOMMAND_H
#define DECODESCRIPTCOMMAND_H

#include "IRPCCommand.h"

namespace spyCBlockRPC
{
    class DecodeScriptCommand : public IRPCCommand
    {
        public:

          DecodeScriptCommand();

          void doCommand(WrapperInformations &wrapper, BitcoinAPI &bitcoinApi) override;
    };
}

#endif // DECODESCRIPTCOMMAND_H
