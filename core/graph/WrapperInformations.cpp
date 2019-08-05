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
