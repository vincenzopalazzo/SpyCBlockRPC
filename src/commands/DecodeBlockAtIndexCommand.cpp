// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.txt

#include <fstream>

#include <glog/logging.h>

#include "DecodeBlockAtIndexCommand.h"
#include "DecodeScriptCommand.h"
#include "HeightBlockchainCommand.h"
#include "../ConfiguratorSingleton.h"
#include "../core/graph/TransactionGraph.h"
#include "../SpyCBlockRPCException.h"
#include "../DefinitionMacro.h"

using namespace std;

//
// This command is only used inside the main, for simple testing and a simple demo
//
void spyCBlockRPC::DecodeBlockAtIndexCommand::doCommand(spyCBlockRPC::WrapperInformations &wrapper, BitcoinAPI &bitcoinApi)
{

  HeightBlockchainCommand heightCommand;
  heightCommand.doCommand(wrapper, bitcoinApi);

  int height = wrapper.getHeightBlockchain();
  assertf(height != -1, "Height blockchain not inizializate")

  int actualBlock = wrapper.getStartBlock();
  LOG(INFO) << "Attual block get information blockchain: " << actualBlock;
  //ofstream stream(ConfiguratorSingleton::getInstance().getDirDatatest() + "/graph-to" + to_string(actualBlock) + "-from-" + to_string(actualBlock + 10));
  int fileIndex = actualBlock;
  string nameFile = ConfiguratorSingleton::getInstance().getDirDatatest() + "/address-tx-"+ to_string(fileIndex) + ".txt";
  LOG(WARNING) << "Name file: " << nameFile;
  ofstream stream(nameFile);
  //int saveActualValue = actualBlock;
  int blocksReaded = 0;
  int limit = 20000;
  //for (int i = 0; i < saveActualValue + 100; i++)
  try {

    while(blocksReaded < height)
    {
        if(blocksReaded == limit){
          LOG(WARNING) << "Hit limit " << limit;
          limit *= 2;
          LOG(WARNING) << "Now limit is " << limit;
          fileIndex++;
          stream.close();
          nameFile = ConfiguratorSingleton::getInstance().getDirDatatest() + "/address-tx-"+ to_string(fileIndex) + ".txt";
          LOG(WARNING) << "Name file: " << nameFile;
          stream.open(nameFile);
        }
        LOG(WARNING) << "Block numbar: " << actualBlock;
        string hash = bitcoinApi.getblockhash(actualBlock);
        LOG(INFO) << "hash is: " << hash;

        blockinfo_t block = bitcoinApi.getblock(hash);

        wrapper.addInformationLink(WrapperInformations::TypeInsert::BLOCK, "Block hash:" + hash);

        for(string &hashTxId : block.tx)
        {
            LOG(INFO) << "Hash is: " << hashTxId;
            getrawtransaction_t rawTx = bitcoinApi.getrawtransaction(hashTxId, 1);



            vector<string> informationsLink;


            for(vin_t txIn : rawTx.vin)
            {

                LOG(INFO) << "Hash txInput " << txIn.txid;
                if(txIn.txid.empty()){
                    LOG(INFO) << "Coinbase tx";
                    wrapper.setHashPreviousTx("0000000000000000000000000000000000000000000000000000000000000000");
                }else{
                    LOG(INFO) << "Not coinbase tx";
                    wrapper.setHashPreviousTx(txIn.txid);
                }

                LOG(INFO) << "Index txInput " << txIn.n;
                wrapper.setNOutpoint(txIn.n);

                for (vout_t txOut : rawTx.vout)
                {
                  //add information link of the rawTx
                  wrapper.addInformationLink(WrapperInformations::TypeInsert::TRANSACTION, "Transaction hash: " + hashTxId);
                  if(rawTx.vin.size() > 1 && rawTx.vout.size() > 1){
                     wrapper.addInformationLink(WrapperInformations::TypeInsert::TRANSACTION, "isManyToMany");
                  }
                  //add information link inputTx

                  LOG(INFO) << "Script output hex: " << txOut.scriptPubKey.hex;
                  wrapper.setTo(txOut.scriptPubKey.hex);
                  wrapper.addInformationLink(WrapperInformations::TypeInsert::TRANSACTION, to_string(txOut.value));

                  wrapper.addInformationLink(WrapperInformations::TypeInsert::TRANSACTION, to_string(rawTx.time));

                  TransactionGraph transactionGraph;

                  transactionGraph.buildTransaction(wrapper);

                  transactionGraph.serialize(stream);
                  wrapper.clean(WrapperInformations::TypeInsert::TRANSACTION);
                }
            }

            wrapper.setStartBlock(actualBlock++);
            blocksReaded++;
        }
        wrapper.clean(WrapperInformations::TypeInsert::BLOCK);
      }

  } catch (BitcoinException btcEx) {
    throw SpyCBlockRPCException(btcEx.getMessage());
  }

}
