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

TEST(serialization_mock_test, serialization_with_wrapper_mock)
{
  string pathMockRoot = ConfiguratorSingleton::getInstance().getDirDatatest() + "/";
  string pathLogRoot = ConfiguratorSingleton::getInstance().getDirLogTest() + "/";

  FLAGS_minloglevel = 0;
  FLAGS_logtostderr = true;
  google::SetLogDestination(google::GLOG_ERROR, pathLogRoot.append("serialization_with_wrapper_mock.log").c_str());

  WrapperInformations wrapper;
  wrapper.setHashPreviousTx("0000000000000000000000000000000000000000000000000000000000000000");
  wrapper.setNOutpoint(0);
  wrapper.setTo("4104678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5fac");

  wrapper.addInformationLink("5000000000");
  wrapper.addInformationLink("4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b");
  wrapper.addInformationLink("1231006505");

  wrapper.setDelimitator("|");

  TransactionGraph transaction;
  try
  {
    transaction.buildTransaction(wrapper);
  } catch (BitcoinException ex) {
    FAIL() << ex.getMessage();
  }

  EXPECT_EQ(wrapper.getFromIdWallets().size(), 1);
  EXPECT_EQ(wrapper.getFromIdWallets().size(), 1); //Coinbase
  ASSERT_EQ(wrapper.getFromIdWallets().at(0), "Coinbase");
  ASSERT_EQ(wrapper.getToIdWallets().at(0), "1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa");

  ofstream saveTransaction(pathMockRoot + "satoshi_transaction_serialization_graph.txt");

  LOG(WARNING) << "Save on: " << pathMockRoot + "satoshi_transaction_serialization_graph.txt";
  transaction.serialize(saveTransaction);

  saveTransaction.close();
}

TEST(serialization_mock_test, witness_serialization_many_to_may_adress_wrapper_mock)
{
  string pathMockRoot = ConfiguratorSingleton::getInstance().getDirDatatest() + "/";
  string pathLogRoot = ConfiguratorSingleton::getInstance().getDirLogTest() + "/";

  FLAGS_minloglevel = 0;
  FLAGS_logtostderr = true;
  google::SetLogDestination(google::GLOG_ERROR, pathLogRoot.append("not_serialization_many_to_may_adress_wrapper_mock.log").c_str());

  WrapperInformations wrapper;

  wrapper.setHashPreviousTx("9913f14389a73b1e90261abbe9fabeef61720374e30ea65119f5f1d1aa292da2");
  wrapper.setNOutpoint(0);

 // wrapper.setFrom("001444ea678cf84c5c17497b3fd974ed370f89a314f9");

  wrapper.setTo("76a914cfe29ef5b750cdf45ea3e148f3a607a2ae3fd7df88ac");

  wrapper.addInformationLink("1175411976");
  wrapper.addInformationLink("056d8c9f0c9cc0ba0aad4facc0eb72b985fada892d6b3689107f3153d0b7b177");
  wrapper.addInformationLink("1231006505");

  wrapper.setDelimitator(" ");

  TransactionGraph transaction;
  try
  {
    transaction.buildTransaction(wrapper);
  } catch (BitcoinException ex) {
    FAIL() << ex.getMessage();
  }

  ASSERT_EQ(wrapper.getFromIdWallets().at(0), "3CRAKZdSrHY5cBPCxBncXRRJDKCGF5saMa");
  ASSERT_EQ(wrapper.getToIdWallets().at(0), "1KxCMcF5HV4DaZrrrPiTPXA44Bzxj8ZFQn");

  ofstream saveTransaction(pathMockRoot + "another_transaction_serialization_graph.txt");

  LOG(WARNING) << "Save on: " << pathMockRoot + "another_transaction_serialization_graph.txt";
  transaction.serialize(saveTransaction);

  saveTransaction.close();
}

TEST(serialization_mock_test, witness_serialization_many_to_may_adress_wrapper_mock_two_tx)
{
  string pathMockRoot = ConfiguratorSingleton::getInstance().getDirDatatest() + "/";
  string pathLogRoot = ConfiguratorSingleton::getInstance().getDirLogTest() + "/";

  FLAGS_minloglevel = 0;
  FLAGS_logtostderr = true;
  google::SetLogDestination(google::GLOG_ERROR, pathLogRoot.append("witness_serialization_many_to_may_adress_wrapper_mock_two_tx.log").c_str());

  WrapperInformations wrapper;

  wrapper.setHashPreviousTx("9913f14389a73b1e90261abbe9fabeef61720374e30ea65119f5f1d1aa292da2");
  wrapper.setNOutpoint(0);

  wrapper.setTo("76a914cfe29ef5b750cdf45ea3e148f3a607a2ae3fd7df88ac");

  wrapper.addInformationLink("1175411976");
  wrapper.addInformationLink("056d8c9f0c9cc0ba0aad4facc0eb72b985fada892d6b3689107f3153d0b7b177");
  wrapper.addInformationLink("1231006505");

  wrapper.setDelimitator("|");

  TransactionGraph transaction;
  try
  {
    transaction.buildTransaction(wrapper);
  } catch (BitcoinException ex) {
    FAIL() << ex.getMessage();
  }

  ASSERT_EQ(wrapper.getFromIdWallets().at(0), "3CRAKZdSrHY5cBPCxBncXRRJDKCGF5saMa");
  ASSERT_EQ(wrapper.getToIdWallets().at(0), "1KxCMcF5HV4DaZrrrPiTPXA44Bzxj8ZFQn");

  ofstream saveTransaction(pathMockRoot + "witness_serialization_many_to_may_adress_wrapper_mock_two_tx.txt");

  LOG(WARNING) << "Save on: " << pathMockRoot + "another_transaction_serialization_graph.txt";
  transaction.serialize(saveTransaction);

  wrapper.setHashPreviousTx("0000000000000000000000000000000000000000000000000000000000000000");
  wrapper.setNOutpoint(0);
  wrapper.setTo("4104678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5fac");

  wrapper.addInformationLink("5000000000");
  wrapper.addInformationLink("4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b");
  wrapper.addInformationLink("1231006505");

  try
  {
    transaction.buildTransaction(wrapper);
  } catch (BitcoinException ex) {
    FAIL() << ex.getMessage();
  }

  EXPECT_EQ(wrapper.getFromIdWallets().size(), 1);
  EXPECT_EQ(wrapper.getFromIdWallets().size(), 1); //Coinbase
  ASSERT_EQ(wrapper.getFromIdWallets().at(0), "Coinbase");
  ASSERT_EQ(wrapper.getToIdWallets().at(0), "1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa");

  LOG(WARNING) << "Save on: " << pathMockRoot + "another_transaction_serialization_graph.txt";
  transaction.serialize(saveTransaction);

  saveTransaction.close();
}

int main(int argc, char **argv) {
    google::InitGoogleLogging(argv[0]);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
