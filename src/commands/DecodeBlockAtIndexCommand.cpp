#include <fstream>

#include <glog/logging.h>

#include "DecodeBlockAtIndexCommand.h"
#include "DecodeScriptCommand.h"
#include "HeightBlockchainCommand.h"
#include "../ConfiguratorSingleton.h"
#include "../core/graph/TransactionGraph.h"

using namespace std;

void spyCBlockRPC::DecodeBlockAtIndexCommand::doCommand(spyCBlockRPC::WrapperInformations &wrapper, BitcoinAPI &bitcoinApi)
{
  HeightBlockchainCommand heightCommand;
  heightCommand.doCommand(wrapper, bitcoinApi);

  int height = wrapper.getHeightBlockchain();
  LOG_IF(ERROR, height == -1) << "Height blockchain not inizializate";

  int attualBlock = wrapper.getStartBlock();
  LOG(INFO) << "Attual block get information blockchain: " << attualBlock;
  ofstream stream(ConfiguratorSingleton::getInstance().getDirDatatest() + "/graph-to" + to_string(attualBlock) + "-from-" + to_string(attualBlock + 10));
  int iteration = attualBlock + 119972;
  for (int i = 0; i < (iteration) && attualBlock <= height; i++)
  {
      LOG(ERROR) << "Block numbar: " << attualBlock;
      string hash = bitcoinApi.getblockhash(attualBlock);
      LOG(INFO) << "hash is: " << hash;

      blockinfo_t block = bitcoinApi.getblock(hash);

      for(string &hashTxId : block.tx)
      {
          LOG(INFO) << "Hash is: " << hashTxId;
          getrawtransaction_t rawTx = bitcoinApi.getrawtransaction(hashTxId, 10);

          vector<string> informationsLink;

          informationsLink.emplace_back(hash);
          informationsLink.emplace_back(hashTxId);

          if(rawTx.vin.size() > 1 && rawTx.vout.size() > 1)
          {
            informationsLink.emplace_back("isManyToMany");
          }

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
                  LOG(INFO) << "Script output hex: " << txOut.scriptPubKey.hex;
                wrapper.setTo(txOut.scriptPubKey.hex);
                informationsLink.emplace_back(to_string(txOut.value));

                informationsLink.emplace_back(to_string(rawTx.time));

                wrapper.setLinkInformations(informationsLink);

                TransactionGraph transactionGraph;

                transactionGraph.buildTransaction(wrapper);

                transactionGraph.serialize(stream);

              }
          }

      }

      wrapper.setStartBlock(attualBlock++);
    }
}
