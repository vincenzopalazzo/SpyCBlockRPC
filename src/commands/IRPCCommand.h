// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.tx

#ifndef IRPCCOMMAND_H
#define IRPCCOMMAND_H

#include <iostream>
#include <string>

#include <bitcoinapi/bitcoinapi.h>

#include "../core/graph/WrapperInformations.h"

namespace spyCBlockRPC
{
  class IRPCCommand
  {
    public:

      virtual void doCommand(WrapperInformations &wrapper, BitcoinAPI &bitcoinApi) = 0;

  };
}

#endif // IRPCCOMMAND_H
