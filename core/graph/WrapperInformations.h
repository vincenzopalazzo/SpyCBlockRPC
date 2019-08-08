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

            std::vector<std::string> getFromIdWallets() const;

            std::vector<std::string> getToIdWallets() const;

            void setToIdWallets(const std::vector<std::string> &value);

            void setFromIdWallets(const std::vector<std::string> &value);

            std::string getDelimitator() const;

            void setDelimitator(const std::string &value);

            std::string getHashPreviousTx() const;

            void setHashPreviousTx(const std::string &value);

            uint64_t getNOutpoint() const;

            void setNOutpoint(const uint64_t &value);

            int getHeightBlockchain() const;

            void setHeightBlockchain(int value);

            int getStartBlock() const;

            void setStartBlock(int value);

    private:

            std:: string hashPreviousTx;

            uint64_t nOutpoint;

            std::string from;

            std::vector<std::string> fromIdWallets;

            std::string to;

            std::vector<std::string> toIdWallets;

            std::vector<std::string> linkInformations;

            std::string delimitator;

            int heightBlockchain = -1;

            int startBlock = 1; //Because the RPC not considered the Gensis block
    };

}

#endif // WRAPPERINFORMATIONS_H
