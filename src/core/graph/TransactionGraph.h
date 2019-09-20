#ifndef TRANSACTIONGRAPH_H
#define TRANSACTIONGRAPH_H

#include <vector>
#include <string>

#include "ITransactionGraph.h"

namespace spyCBlockRPC {

    class TransactionGraph : ITransactionGraph
    {
        public:

          void serialize(std::ofstream &stream) override;

          void buildTransaction(WrapperInformations &wrapper) override;

        private:

          std::vector<std::string> from;

          std::vector<std::string> to;

          std::vector<std::string> linkInformations;

          std::string delimitator;

    };

}

#endif // TRANSACTIONGRAPH_H
