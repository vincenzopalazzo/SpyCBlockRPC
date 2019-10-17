// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.tx

#ifndef DECODEBLOCKATINDEXCOMMAND_H
#define DECODEBLOCKATINDEXCOMMAND_H

#ifdef NDEBUG
#define ASSERT(condition, message) 0
#else
#define ASSERT(condition, message)\
   (!(condition)) ?\
      (std::cerr << "Assertion failed: (" << #condition << "), "\
      << "function " << __FUNCTION__\
      << ", file " << __FILE__\
      << ", line " << __LINE__ << "."\
      << std::endl << message << std::endl, abort(), 0) : 1
#endif

#include "IRPCCommand.h"

namespace spyCBlockRPC
{
    class DecodeBlockAtIndexCommand : public IRPCCommand
    {
        public:

            void doCommand(WrapperInformations &wrapper, BitcoinAPI &bitcoinApi) override;

    };


}
#endif // DECODEBLOCKATINDEXCOMMAND_H
