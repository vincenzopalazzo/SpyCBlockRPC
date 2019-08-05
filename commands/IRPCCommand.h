#ifndef IRPCCOMMAND_H
#define IRPCCOMMAND_H

#include <iostream>
#include <string>

#include "../core/graph/WrapperInformations.h"

namespace spyCBlockRPC
{
  class IRPCCommand
  {
    public:

      virtual void doCommand(WrapperInformations &wrapper) = 0;

  };
}

#endif // IRPCCOMMAND_H
