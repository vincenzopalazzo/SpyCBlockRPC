// Copyright (c) 2018-2019 Vincenzo Palazzo vicenzopalazzodev@gmail.com
// Distributed under the Apache License Version 2.0 software license,
// see https://www.apache.org/licenses/LICENSE-2.0.txt

#include <gtest/gtest.h>
#include <glog/logging.h>

#include "../src/core/graph/ITransactionGraph.h"
#include "../src/core/graph/TransactionGraph.h"
#include "../src/core/graph/WrapperInformations.h"
#include "../src/ConfiguratorSingleton.h"
#include "../src/commands/RPCCommandMediator.h"

using namespace spyCBlockRPC;
using namespace std;

//This transaction is real because is my tx
TEST(decode_raw_transaction_test, execute_command_decode_raw_tx_coinbase)
{
  string pathMockRoot = ConfiguratorSingleton::getInstance().getDirDatatest() + "/";
  string pathLogRoot = ConfiguratorSingleton::getInstance().getDirLogTest() + "/";

  FLAGS_minloglevel = 0;
  FLAGS_logtostderr = true;
  google::SetLogDestination(google::GLOG_ERROR, pathLogRoot.append("execute_command_decode_raw_tx.log").c_str());

  WrapperInformations wrapper;
  //Insert inside the wrapper the information coinbase
  //Thi si the reference transaction
  //https://blockstream.info/tx/bd28376c31d39233c7ab832515e1b68808678319232034bb5a98a997b05ae418
  //I take the previeus hash to this reference https://www.blockchain.com/btc/address/1Peysn8vEPV1emkfRQ8rh3tiR1vDnb7Cxw
  wrapper.setHashPreviousTx("0000000000000000000000000000000000000000000000000000000000000000");
  wrapper.setNOutpoint(5000000000);

  wrapper.addInformationLink("bd28376c31d39233c7ab832515e1b68808678319232034bb5a98a997b05ae418");

  BitcoinAPI api(ConfiguratorSingleton::getInstance().getUser(),
                       ConfiguratorSingleton::getInstance().getPassword(),
                       ConfiguratorSingleton::getInstance().getHost(),
                       ConfiguratorSingleton::getInstance().getPort());

  DecodeRawTransaction decodeRawTx;

  try
  {
    decodeRawTx.doCommand(wrapper, api);
  } catch (BitcoinException btcEx) {
    FAIL() << btcEx.getMessage();
  }

  ASSERT_EQ(wrapper.getFrom(), "Coinbase");
}

//This transaction is real because is my tx
TEST(decode_script_command_test, decode_raw_tx_execute_command_other_tx)
{
  string pathMockRoot = ConfiguratorSingleton::getInstance().getDirDatatest() + "/";
  string pathLogRoot = ConfiguratorSingleton::getInstance().getDirLogTest() + "/";

  FLAGS_minloglevel = 0;
  FLAGS_logtostderr = true;
  google::SetLogDestination(google::GLOG_ERROR, pathLogRoot.append("decode_raw_tx_execute_command_other_tx.log").c_str());

  WrapperInformations wrapper;
  //Insert inside the wrapper the information coinbase
  //Thi si the reference transaction
  //https://blockstream.info/tx/bd28376c31d39233c7ab832515e1b68808678319232034bb5a98a997b05ae418
  //I take the previeus hash to this reference https://www.blockchain.com/btc/address/1Peysn8vEPV1emkfRQ8rh3tiR1vDnb7Cxw
  wrapper.setHashPreviousTx("d86e8dae82c2d17bed80a8b98d0a524c0b3851060747ae17322115ab69831adb");
  wrapper.setNOutpoint(1);
  wrapper.setTo("a9149bf9d68af78d22c3040a4714c928c6ba9481519887");

  wrapper.addInformationLink("bd28376c31d39233c7ab832515e1b68808678319232034bb5a98a997b05ae418");

  BitcoinAPI api(ConfiguratorSingleton::getInstance().getUser(),
                       ConfiguratorSingleton::getInstance().getPassword(),
                       ConfiguratorSingleton::getInstance().getHost(),
                       ConfiguratorSingleton::getInstance().getPort());

  DecodeRawTransaction decodeRawTx;

  try
  {
    decodeRawTx.doCommand(wrapper, api);
  } catch (BitcoinException btcEx) {
    FAIL() << btcEx.getMessage();
  }

  ASSERT_EQ(wrapper.getFrom(), "76a914379f09aa1c9a447ee664b40b31a1d27825577a3d88ac");
}
