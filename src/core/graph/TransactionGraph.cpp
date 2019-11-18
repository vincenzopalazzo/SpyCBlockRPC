// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.txt

#include <glog/logging.h>

#include "TransactionGraph.h"
#include "../../commands/RPCCommandMediator.h"
#include "WrapperInformations.h"

using namespace std;
using namespace spyCBlockRPC;

TransactionGraph::TransactionGraph() : ITransactionGraph()
{}

//TODO test this informations
void TransactionGraph::serialize(ofstream &stream)
{
  LOG(INFO) << "************ Serialization this information ************\n";
  //Not serialize the transaction many to many
  if(this->to.size() == 1 || this->from.size() == 1){
      string serializeTransaction;

      //Serialization informations input
      for(auto valueFrom : this->from)
      {
         serializeTransaction += valueFrom;
      }

      //
      //Serialization information link
      //
      for (auto iterator = linkInformations.begin(); iterator != linkInformations.end();  ++iterator)
      {
        serializeTransaction += (delimitator + *iterator);
      }

      //
      //serializzation information output
      //
      for(auto value : this->to)
      {
         serializeTransaction += (delimitator +(value));
         LOG(INFO) << serializeTransaction;
         stream << serializeTransaction << "\n";
       }
    }else {
      LOG_IF( ERROR, true) << "MANY to MANY address";
    }
}

void TransactionGraph::buildTransaction(WrapperInformations &wrapper)
{
  string scriptSing = wrapper.getFrom();
  LOG(WARNING) << "Script sing: "  << scriptSing;
  string scriptPubKey = wrapper.getTo();
  LOG(WARNING) << "Script public key: " << scriptPubKey;

  //TODO This is necessary?
  /*this->linkInformations.insert(wrapper.getLinkInformationsBlock().begin(),
                                wrapper.getLinkInformationsBlock().end());

  this->linkInformations.insert(wrapper.getLinkInformationsTransaction().begin(),
                                wrapper.getLinkInformationsTransaction().end());*/

  LOG(WARNING) << "Information size: " << linkInformations.size();

  this->delimitator = wrapper.getDelimitator();
  LOG(INFO) << "Delimitator: " << delimitator;

  RPCCommandMediator::getInstance().doCommand(RPCCommandMediator::getInstance().DECODE_SCRIPT_COMMAND, wrapper);

  this->from = wrapper.getFromIdWallets();
  this->to = wrapper.getToIdWallets();

  this->linkInformations.insert(wrapper.getLinkInformationsBlock().begin(),
                                wrapper.getLinkInformationsBlock().end());

  this->linkInformations.insert(wrapper.getLinkInformationsTransaction().begin(),
                                wrapper.getLinkInformationsTransaction().end());

  LOG(INFO) << "Numbar information link: " << linkInformations.size();
}
