// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.tx

#ifndef DECODERAWTRANSACTION_H
#define DECODERAWTRANSACTION_H

#include "IRPCCommand.h"

namespace spyCBlockRPC
{
    class DecodeRawTransaction : public IRPCCommand
    {
        public:

          void doCommand(WrapperInformations &wrapper, BitcoinAPI &bitcoinApi) override;

          std::string toBtc(std::uint64_t &satoshi);

          long toSatoshi(double &btc);

        private:

          const std::string HASH_COINBASE = "0000000000000000000000000000000000000000000000000000000000000000";
    };

}
#endif // DECODERAWTRANSACTION_H
