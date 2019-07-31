#ifndef WRAPPERINFORMATIONS_H
#define WRAPPERINFORMATIONS_H

#include<string>
#include <vector>

namespace spyCBlockRPC {

    class WrapperInformations
    {

        public:

            std::string getFrom() const;
            void setFrom(const std::string &value);

            std::string getTo() const;
            void setTo(const std::string &value);

            std::vector<std::string> getLinkInformations() const;
            void setLinkInformations(const std::vector<std::string> &value);

        private:

            std::string from;

            std::string to;

            std::vector<std::string> linkInformations;

    };

}

#endif // WRAPPERINFORMATIONS_H
