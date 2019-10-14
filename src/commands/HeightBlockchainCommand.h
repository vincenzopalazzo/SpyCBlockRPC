// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.tx

#ifndef HEIGHTBLOCKCHAINCOMMAND_H
#define HEIGHTBLOCKCHAINCOMMAND_H

#include "IRPCCommand.h"

namespace spyCBlockRPC
{
    class HeightBlockchainCommand : public IRPCCommand
    {
        public:

            void doCommand(WrapperInformations &wrapper, BitcoinAPI &bitcoinApi) override;
    };

}


#endif // HEIGHTBLOCKCHAINCOMMAND_H
