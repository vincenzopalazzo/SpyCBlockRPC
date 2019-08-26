#include <glog/logging.h>

#include "TransactionGraph.h"
#include "../../commands/RPCCommandMediator.h"
#include "WrapperInformations.h"

using namespace std;
using namespace spyCBlockRPC;

//TODO test this informations
void TransactionGraph::serialize(ofstream &stream)
{
  LOG(INFO) << "************ Serialization this information ************\n";
  //Not serialize the transaction many to many
  if(this->to.size() == 1 || this->from.size() == 1)
  {
    string serializeTransaction;
       //Serialization informations input
       for(int i = 0; i < static_cast<int>(this->from.size()); i++)
       {
         unsigned long value = static_cast<unsigned long>(i);
         //if(value == this->from.size() - 1)
         //{
          // serializeTransaction += from.at(value);
         //}else{
           serializeTransaction += from.at(value);
         //}
         //Serialization information link
         for(string &information: this->linkInformations)
         {
           serializeTransaction += (delimitator + information);
         }
         //serializzation information output
         for(int i = 0; i < static_cast<int>(this->to.size()); i++)
         {
            unsigned long value = static_cast<unsigned long>(i);
            //if(value == this->from.size() - 1)
            //{
             // serializeTransaction += from.at(value);
           // }else{
              serializeTransaction += (delimitator + to.at(value));
            //}
            LOG(INFO) << serializeTransaction;
            stream << serializeTransaction << "\n";
         }
      }
    }
}

void TransactionGraph::buildTransaction(WrapperInformations &wrapper)
{
  string scriptSing = wrapper.getFrom();
  LOG(WARNING) << "Script sing: "  << scriptSing;
  string scriptPubKey = wrapper.getTo();
  LOG(WARNING) << "Script public key: " << scriptPubKey;

  this->linkInformations = wrapper.getLinkInformations();
  LOG(WARNING) << "Information size: " << linkInformations.size();

  this->delimitator = wrapper.getDelimitator();
  LOG(INFO) << "Delimitator: " << delimitator;

  RPCCommandMediator::getInstance().doCommand(RPCCommandMediator::getInstance().DECODE_SCRIPT_COMMAND, wrapper);

 // RPCCommandMediator::getInstance().closeConnectionWithNode(); this command close the bitcoind

  this->from = wrapper.getFromIdWallets();
  this->to = wrapper.getToIdWallets();

  this->linkInformations = wrapper.getLinkInformations();
  LOG(INFO) << "Numbar information link: " << linkInformations.size();
}

void TransactionGraph::addLinkInformation(string &information)
{
  if(information.empty())
  {
      LOG(ERROR) << "Information empty, information not valid";
      return; //try to throws an exception
  }
  this->linkInformations.emplace_back(information);
}
