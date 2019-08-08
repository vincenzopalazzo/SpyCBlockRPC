#ifndef DECODEBLOCKATINDEXCOMMAND_H
#define DECODEBLOCKATINDEXCOMMAND_H

#include "IRPCCommand.h"

namespace spyCBlockRPC {

    class DecodeBlockAtIndexCommand : IRPCCommand {

        public:
            void doCommand(WrapperInformations &wrapper, BitcoinAPI &bitcoinApi) override;

    };


}
#endif // DECODEBLOCKATINDEXCOMMAND_H
