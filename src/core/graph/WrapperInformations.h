// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.tx

#ifndef WRAPPERINFORMATIONS_H
#define WRAPPERINFORMATIONS_H

#include <string>
#include <vector>
#include <set>

namespace spyCBlockRPC
{
    class WrapperInformations
    {

        public:

            enum class TypeInsert
            {
              BLOCK,
              TRANSACTION
            };

            const std::string& getFrom() const;

            void setFrom(const std::string &value);

            const std::string& getTo() const;

            void setTo(const std::string &value);

            const std::set<std::string>& getLinkInformationsTransaction();

            const std::set<std::string>& getLinkInformationsBlock();

            void setLinkInformations(const std::set<std::string> &value);

            //Before this used single set for store information and it have a bug
            //the bug was the impossibility to chaoise the value to remove
            //and example if I must serialize the transaction with block informations
            //when I goes call the clen() method the information of the block doesn't loger exist
            [[deprecated]] void addInformationLink(const std::string &information);

            void addInformationLink(TypeInsert typeInsert, const std::string &information);

            const std::vector<std::string>& getFromIdWallets() const;

            const std::vector<std::string>& getToIdWallets() const;

            void setToIdWallets(const std::vector<std::string> &value);

            void setFromIdWallets(const std::vector<std::string> &value);

            const std::string& getDelimitator() const;

            void setDelimitator(const std::string &value);

            const std::string& getHashPreviousTx() const;

            void setHashPreviousTx(const std::string &value);

            uint64_t getNOutpoint() const;

            void setNOutpoint(const uint64_t &value);

            int getHeightBlockchain() const;

            void setHeightBlockchain(int value);

            int getStartBlock() const;

            void setStartBlock(int value);

            void clean();

            void clean(TypeInsert typeInsert);

    private:

            std:: string hashPreviousTx;

            uint64_t nOutpoint;

            std::string from;

            std::vector<std::string> fromIdWallets;

            std::string to;

            std::vector<std::string> toIdWallets;

            std::set<std::string> linkInformationsTransactions;

            std::set<std::string> linkInformationsBlocks;

            std::string delimitator;

            int heightBlockchain = -1;

            int startBlock = 1; //Because the RPC not considered the Gensis block

            void addInformationTo(std::set<std::string> &informationSet, std::string &information);
    };

}

#endif // WRAPPERINFORMATIONS_H
