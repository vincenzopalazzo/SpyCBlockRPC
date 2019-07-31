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
