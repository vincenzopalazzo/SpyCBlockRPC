// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.tx

#ifndef ITRANSACTIONGRAPH_H
#define ITRANSACTIONGRAPH_H

#include <fstream>

#include "WrapperInformations.h"

namespace spyCBlockRPC
{
    class ITransactionGraph
    {
        public:

            virtual void serialize(std::ofstream &stream) = 0;

            virtual void buildTransaction(WrapperInformations &wrapper) = 0;

    };

}


#endif // ITRANSACTIONGRAPH_H
