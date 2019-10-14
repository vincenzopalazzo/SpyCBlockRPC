// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.tx

#ifndef TRANSACTIONGRAPH_H
#define TRANSACTIONGRAPH_H

#include <vector>
#include <string>

#include "ITransactionGraph.h"

namespace spyCBlockRPC
{
    class TransactionGraph : public ITransactionGraph
    {
        public:

          TransactionGraph();

          void serialize(std::ofstream &stream) override;

          void buildTransaction(WrapperInformations &wrapper) override;

        private:

          std::vector<std::string> from;

          std::vector<std::string> to;

          std::set<std::string> linkInformations;

          std::string delimitator;

    };

}

#endif // TRANSACTIONGRAPH_H
