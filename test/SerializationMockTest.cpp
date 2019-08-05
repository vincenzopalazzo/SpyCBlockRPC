#include <gtest/gtest.h>
#include <glog/logging.h>

#include "../core/graph/ITransactionGraph.h"
#include "../core/graph/TransactionGraph.h"
#include "../core/graph/WrapperInformations.h"
#include "../ClientBitcoinSingleton.h"
#include "../commands/RPCCommandMediator.h"

using namespace spyCBlockRPC;
using namespace std;

TEST(serialization_mock_test, serialization_with_wrapper_mock)
{
  string pathMockRoot = ClientBitcoinSingleton::getInstance().getDirDatatest() + "/";
  string pathLogRoot = ClientBitcoinSingleton::getInstance().getDirLogTest() + "/";

  FLAGS_minloglevel = 0;
  FLAGS_logtostderr = true;
  google::SetLogDestination(google::GLOG_ERROR, pathLogRoot.append("serialization_with_wrapper_mock.log").c_str());

  WrapperInformations wrapper;
  wrapper.setFrom("04ffff001d0104455468652054696d65732030332f4a616e2f32303039204368616e63656c6c6f72206f6e206272696e6b206f66207365636f6e64206261696c6f757420666f722062616e6b73");
  wrapper.setTo("4104678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5fac");

  vector<string> linkInformations;
  linkInformations.emplace_back("5000000000");
  linkInformations.emplace_back("4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b");
  linkInformations.emplace_back("1231006505");
  wrapper.setLinkInformations(linkInformations);

  wrapper.setDelimitator("|");

  TransactionGraph transaction;
  transaction.buildTransaction(wrapper);

  ASSERT_EQ(wrapper.getFromIdWallets().size(), 1); //Coinbase
  ASSERT_EQ(wrapper.getFromIdWallets().at(0), "Coinbase");
  ASSERT_EQ(wrapper.getToIdWallets().at(0), "1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa");

  ofstream saveTransaction(pathMockRoot + "satoshi_transaction_serialization_graph.txt");

  LOG(WARNING) << "Save on: " << pathMockRoot + "satoshi_transaction_serialization_graph.txt";
  transaction.serialize(saveTransaction);

  saveTransaction.close();
}

//This transaction mustn't be serializated because is an many to many
TEST(serialization_mock_test, witness_serialization_many_to_may_adress_wrapper_mock)
{
  string pathMockRoot = ClientBitcoinSingleton::getInstance().getDirDatatest() + "/";
  string pathLogRoot = ClientBitcoinSingleton::getInstance().getDirLogTest() + "/";

  FLAGS_minloglevel = 0;
  FLAGS_logtostderr = true;
  google::SetLogDestination(google::GLOG_ERROR, pathLogRoot.append("not_serialization_many_to_may_adress_wrapper_mock.log").c_str());

  WrapperInformations wrapper;
  wrapper.setFrom("001444ea678cf84c5c17497b3fd974ed370f89a314f9");

  wrapper.setTo("76a914cfe29ef5b750cdf45ea3e148f3a607a2ae3fd7df88ac");

  vector<string> linkInformations;
  linkInformations.emplace_back("1175411976");
  linkInformations.emplace_back("056d8c9f0c9cc0ba0aad4facc0eb72b985fada892d6b3689107f3153d0b7b177");
  linkInformations.emplace_back("1231006505");
  wrapper.setLinkInformations(linkInformations);

  wrapper.setDelimitator(" ");

  TransactionGraph transaction;
  transaction.buildTransaction(wrapper);

  ASSERT_EQ(wrapper.getFromIdWallets().at(0), "3CRAKZdSrHY5cBPCxBncXRRJDKCGF5saMa"); //Coinbase

  ASSERT_EQ(wrapper.getToIdWallets().at(0), "1KxCMcF5HV4DaZrrrPiTPXA44Bzxj8ZFQn");

  ofstream saveTransaction(pathMockRoot + "another_transaction_serialization_graph.txt");

  LOG(WARNING) << "Save on: " << pathMockRoot + "another_transaction_serialization_graph.txt";
  transaction.serialize(saveTransaction);

  saveTransaction.close();
}

TEST(serialization_mock_test, witness_serialization_adress_wrapper_mock)
{
  string pathMockRoot = ClientBitcoinSingleton::getInstance().getDirDatatest() + "/";
  string pathLogRoot = ClientBitcoinSingleton::getInstance().getDirLogTest() + "/";

  FLAGS_minloglevel = 0;
  FLAGS_logtostderr = true;
  google::SetLogDestination(google::GLOG_ERROR, pathLogRoot.append("not_serialization_many_to_may_adress_wrapper_mock.log").c_str());

  WrapperInformations wrapper;
  wrapper.setFrom("483045022100e5e4749d539a163039769f52e1ebc8e6f62e39387d61e1a305bd722116cded6c022014924b745dd02194fe6b5cb8ac88ee8e9a2aede89e680dcea6169ea696e24d52012102b4b754609b46b5d09644c2161f1767b72b93847ce8154d795f95d31031a08aa2");

  wrapper.setTo("76a914a134408afa258a50ed7a1d9817f26b63cc9002cc88ac");

  vector<string> linkInformations;
  linkInformations.emplace_back("1175411976");
  linkInformations.emplace_back("056d8c9f0c9cc0ba0aad4facc0eb72b985fada892d6b3689107f3153d0b7b177");
  linkInformations.emplace_back("1231006505");
  wrapper.setLinkInformations(linkInformations);

  wrapper.setDelimitator(" ");

  TransactionGraph transaction;
  transaction.buildTransaction(wrapper);

  ASSERT_EQ(wrapper.getFromIdWallets().at(0), "3CRAKZdSrHY5cBPCxBncXRRJDKCGF5saMa"); //Coinbase

  ASSERT_EQ(wrapper.getToIdWallets().at(0), "1KxCMcF5HV4DaZrrrPiTPXA44Bzxj8ZFQn");

  ofstream saveTransaction(pathMockRoot + "witness_serialization_adress_wrapper_mock.txt");

  LOG(WARNING) << "Save on: " << pathMockRoot + "witness_serialization_adress_wrapper_mock.txt";
  transaction.serialize(saveTransaction);

  saveTransaction.close();
}

int main(int argc, char **argv) {
    google::InitGoogleLogging(argv[0]);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
