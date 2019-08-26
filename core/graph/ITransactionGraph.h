#ifndef ITRANSACTIONGRAPH_H
#define ITRANSACTIONGRAPH_H

#include <fstream>

#include "WrapperInformations.h"

namespace spyCBlockRPC {

    class ITransactionGraph
    {
        public:

            virtual void serialize(std::ofstream &stream) = 0;

            virtual void buildTransaction(WrapperInformations &wrapper) = 0;

            virtual void addLinkInformation(std::string &information) = 0;

    };

}


#endif // ITRANSACTIONGRAPH_H
