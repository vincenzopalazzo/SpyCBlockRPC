// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.tx

#ifndef DECODEBLOCKATINDEXCOMMAND_H
#define DECODEBLOCKATINDEXCOMMAND_H

#include "IRPCCommand.h"
#include "../DefinitionMacro.h"

namespace spyCBlockRPC
{
    class DecodeBlockAtIndexCommand : public IRPCCommand
    {
        public:

            void doCommand(WrapperInformations &wrapper, BitcoinAPI &bitcoinApi) override;

    };


}
#endif // DECODEBLOCKATINDEXCOMMAND_H
