#include "WrapperInformations.h"

using namespace spyCBlockRPC;
using namespace std;

//getter and setter

std::string WrapperInformations::getFrom() const
{
    return from;
}

void WrapperInformations::setFrom(const std::string &value)
{
    from = value;
}

std::string WrapperInformations::getTo() const
{
    return to;
}

void WrapperInformations::setTo(const std::string &value)
{
    to = value;
}

std::vector<std::string> WrapperInformations::getLinkInformations() const
{
    return linkInformations;
}

void WrapperInformations::setLinkInformations(const std::vector<std::string> &value)
{
    linkInformations = value;
}

std::vector<std::string> WrapperInformations::getFromIdWallets() const
{
  return fromIdWallets;
}

std::vector<std::string> WrapperInformations::getToIdWallets() const
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

std::string WrapperInformations::getDelimitator() const
{
  return delimitator;
}

void WrapperInformations::setDelimitator(const std::string &value)
{
  delimitator = value;
}

std::string WrapperInformations::getHashPreviousTx() const
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
