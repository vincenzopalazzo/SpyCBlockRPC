#ifndef HEIGHTBLOCKCHAINCOMMAND_H
#define HEIGHTBLOCKCHAINCOMMAND_H

#include "IRPCCommand.h"

namespace spyCBlockRPC{

    class HeightBlockchainCommand : IRPCCommand
    {
        public:
            void doCommand(WrapperInformations &wrapper, BitcoinAPI &bitcoinApi) override;
    };

}


#endif // HEIGHTBLOCKCHAINCOMMAND_H
