#ifndef ITRANSACTIONGRAPH_H
#define ITRANSACTIONGRAPH_H

#include <fstream>

#include "WrapperInformations.h"

namespace spyCBlockRPC {

    class ITransactionGraph
    {
        public:

            virtual void serialize(std::fstream &stream) = 0;

            virtual void buildTransaction(WrapperInformations &wrapper) = 0;

    };

}


#endif // ITRANSACTIONGRAPH_H
