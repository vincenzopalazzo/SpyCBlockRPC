#ifndef IRPCCOMMAND_H
#define IRPCCOMMAND_H

#include <string>

namespace spyCBlockRPC
{
  class IRPCCommand
  {
    public:
      virtual std::string doCommand(std::string& input) = 0;
  };
}

#endif // IRPCCOMMAND_H
