// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.txt

#ifndef SPYCBLOCKRPCEXCEPTION_H
#define SPYCBLOCKRPCEXCEPTION_H

#include <string>
#include <stdexcept>

namespace spyCBlockRPC
{

    class SpyCBlockRPCException : public std::runtime_error
    {
      public:

          SpyCBlockRPCException(const std::string &cause) throw() : std::runtime_error(cause){};
    };
}

#endif // SPYCBLOCKRPCEXCEPTION_H
