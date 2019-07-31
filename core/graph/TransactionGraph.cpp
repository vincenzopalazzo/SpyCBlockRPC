#include <glog/logging.h>

#include "TransactionGraph.h"

using namespace spyCBlockRPC;
using namespace std;


void TransactionGraph::serialize(fstream &stream)
{
  //TODO call dao for serialize this information
}

void TransactionGraph::buildTransaction(WrapperInformations &wrapper)
{
  string scriptSing = wrapper.getFrom();
  LOG(WARNING) << "Script sing: "  << scriptSing;
  string scriptPubKey = wrapper.getTo();
  LOG(WARNING) << "Script public key: " << scriptPubKey;

  this->linkInformations = wrapper.getLinkInformations();
  LOG(WARNING) << "Information size: " << linkInformations.size();

  //TODO convert the script to is wallet
}
