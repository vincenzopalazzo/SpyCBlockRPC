// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.txt

#include <glog/logging.h>

#include "WrapperInformations.h"
#include "../../DefinitionMacro.h"

using namespace spyCBlockRPC;
using namespace std;



void WrapperInformations::addInformationLink(const string &information)
{
  assertf(!information.empty(), "The information parameter is empity, this is an wrong condition");

  this->linkInformationsTransactions.insert(information);
}

void WrapperInformations::addInformationLink(WrapperInformations::TypeInsert typeInsert, const string &information)
{
  assertf(!information.empty(), "The information parameter is empity, this is an wrong condition");

  if(typeInsert == TypeInsert::BLOCK){
      this->linkInformationsBlocks.emplace(information);
  }else if(typeInsert == TypeInsert::TRANSACTION){
      this->linkInformationsTransactions.emplace(information);
  }
}

void WrapperInformations::clean()
{
  //Swap the vectors.
  this->linkInformationsTransactions.clear();
  this->linkInformationsBlocks.clear();
  //TODO This is unecessary?
  //this->toIdWallets.clear();
  //this->fromIdWallets.clear();
}

void WrapperInformations::clean(TypeInsert typeInsert)
{
  //Swap the vectors.
  if(typeInsert == TypeInsert::BLOCK){
    this->linkInformationsBlocks.clear();
  }else if(typeInsert == TypeInsert::TRANSACTION){
    this->linkInformationsTransactions.clear();
  }
  //TODO This is unecessary?
 // this->toIdWallets.clear();
  //this->fromIdWallets.clear();
}


//getter and setter
const std::string& WrapperInformations::getFrom() const
{
    return from;
}

void WrapperInformations::setFrom(const std::string &value)
{
    from = value;
}

const std::string& WrapperInformations::getTo() const
{
    return to;
}

void WrapperInformations::setTo(const std::string &value)
{
    to = value;
}

const std::set<std::string>& WrapperInformations::getLinkInformationsTransaction()
{
  return linkInformationsTransactions;
}

const std::set<string>& WrapperInformations::getLinkInformationsBlock()
{
  return linkInformationsBlocks;
}


void WrapperInformations::setLinkInformations(const std::set<std::string> &value)
{
  linkInformationsTransactions = value;
}

const std::vector<std::string>& WrapperInformations::getFromIdWallets() const
{
  return fromIdWallets;
}

const std::vector<std::string>& WrapperInformations::getToIdWallets() const
{
  return toIdWallets;
}

void WrapperInformations::setToIdWallets(const std::vector<std::string> &value)
{
  toIdWallets = value;
}

void WrapperInformations::setFromIdWallets(const std::vector<std::string> &value)
{
  fromIdWallets = value;
}

const std::string& WrapperInformations::getDelimitator() const
{
  return delimitator;
}

void WrapperInformations::setDelimitator(const std::string &value)
{
  delimitator = value;
}

const std::string& WrapperInformations::getHashPreviousTx() const
{
    return hashPreviousTx;
}

void WrapperInformations::setHashPreviousTx(const std::string &value)
{
    hashPreviousTx = value;
}

uint64_t WrapperInformations::getNOutpoint() const
{
    return nOutpoint;
}

void WrapperInformations::setNOutpoint(const uint64_t &value)
{
    nOutpoint = value;
}

int WrapperInformations::getHeightBlockchain() const
{
    return heightBlockchain;
}

void WrapperInformations::setHeightBlockchain(int value)
{
    heightBlockchain = value;
}

int WrapperInformations::getStartBlock() const
{
    return startBlock;
}

void WrapperInformations::setStartBlock(int value)
{
  startBlock = value;
}
