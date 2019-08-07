#ifndef DECODERAWTRANSACTION_H
#define DECODERAWTRANSACTION_H

#include "IRPCCommand.h"

namespace spyCBlockRPC
{
    class DecodeRawTransaction : IRPCCommand
    {
        public:

          void doCommand(WrapperInformations &wrapper, BitcoinAPI &bitcoinApi) override;
    };

}
#endif // DECODERAWTRANSACTION_H
