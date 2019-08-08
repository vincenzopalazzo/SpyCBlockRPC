#ifndef DECODERAWTRANSACTION_H
#define DECODERAWTRANSACTION_H

#include "IRPCCommand.h"

namespace spyCBlockRPC
{
    class DecodeRawTransaction : IRPCCommand
    {
        public:

          void doCommand(WrapperInformations &wrapper, BitcoinAPI &bitcoinApi) override;

          std::string toBtc(std::uint64_t &satoshi);

        private:
          const std::string HASH_COINBASE = "0000000000000000000000000000000000000000000000000000000000000000";
    };

}
#endif // DECODERAWTRANSACTION_H
