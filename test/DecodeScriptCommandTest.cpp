#include <gtest/gtest.h>
#include <glog/logging.h>

#include "../src/core/graph/ITransactionGraph.h"
#include "../src/core/graph/TransactionGraph.h"
#include "../src/core/graph/WrapperInformations.h"
#include "../src/ConfiguratorSingleton.h"
#include "../src/commands/DecodeScriptCommand.h"

using namespace spyCBlockRPC;
using namespace std;

TEST(decode_script_command_test, decode_script_execute_command_execute_decode_script_coinbase)
{
  string pathMockRoot = ConfiguratorSingleton::getInstance().getDirDatatest() + "/";
  string pathLogRoot = ConfiguratorSingleton::getInstance().getDirLogTest() + "/";

  FLAGS_minloglevel = 0;
  FLAGS_logtostderr = true;
  google::SetLogDestination(google::GLOG_ERROR, pathLogRoot.append("decode_script_execute_command_execute_decode_script_coinbase.log").c_str());

  WrapperInformations wrapper;
  //Insert inside the wrapper the information coinbase
  //Thi si the reference transaction
  //https://blockstream.info/tx/4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b
  wrapper.setHashPreviousTx("0000000000000000000000000000000000000000000000000000000000000000");
  wrapper.setNOutpoint(5000000000);
  wrapper.setTo("4104678afdb0fe5548271967f1a67130b7105cd6a828e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5fac");

  vector<string> informations{"4a5e1e4baab89f3a32518a88c31bc87f618f76673e2cc77ab2127b7afdeda33b"};
  wrapper.setLinkInformations(informations);

  BitcoinAPI api(ConfiguratorSingleton::getInstance().getUser(),
                       ConfiguratorSingleton::getInstance().getPassword(),
                       ConfiguratorSingleton::getInstance().getHost(),
                       ConfiguratorSingleton::getInstance().getPort());

  DecodeScriptCommand decodeScript;

  try
  {
    decodeScript.doCommand(wrapper, api);
  } catch (BitcoinException btcEx) {
    FAIL() << btcEx.getMessage();
  }

  ASSERT_EQ(wrapper.getFromIdWallets().size(), 1);
  ASSERT_EQ(wrapper.getFromIdWallets().at(0), "Coinbase");
  ASSERT_EQ(wrapper.getToIdWallets().size(), 1);
  ASSERT_EQ(wrapper.getToIdWallets().at(0), "1A1zP1eP5QGefi2DMPTfTL5SLmv7DivfNa");
  //Look the reference P2PK
}

//This transaction is real because is my tx
TEST(decode_script_command_test, decode_script_execute_command_execute_another_tx)
{
  string pathMockRoot = ConfiguratorSingleton::getInstance().getDirDatatest() + "/";
  string pathLogRoot = ConfiguratorSingleton::getInstance().getDirLogTest() + "/";

  FLAGS_minloglevel = 0;
  FLAGS_logtostderr = true;
  google::SetLogDestination(google::GLOG_ERROR, pathLogRoot.append("decode_script_execute_command_execute_another_tx.log").c_str());

  WrapperInformations wrapper;
  //Insert inside the wrapper the information coinbase
  //Thi si the reference transaction
  //https://blockstream.info/tx/bd28376c31d39233c7ab832515e1b68808678319232034bb5a98a997b05ae418
  //The previeus hash tx is get to this reference https://www.blockchain.com/btc/address/1Peysn8vEPV1emkfRQ8rh3tiR1vDnb7Cxw
  wrapper.setHashPreviousTx("e664f6a3197402534abc5b6d1d918dd6a3ba764f8defcc54ad386b71f7b0862a");
  wrapper.setNOutpoint(1);
  wrapper.setTo("a9149bf9d68af78d22c3040a4714c928c6ba9481519887");

  vector<string> informations{"bd28376c31d39233c7ab832515e1b68808678319232034bb5a98a997b05ae418"};
  wrapper.setLinkInformations(informations);

  BitcoinAPI api(ConfiguratorSingleton::getInstance().getUser(),
                       ConfiguratorSingleton::getInstance().getPassword(),
                       ConfiguratorSingleton::getInstance().getHost(),
                       ConfiguratorSingleton::getInstance().getPort());

  DecodeScriptCommand decodeScript;

  try
  {
    decodeScript.doCommand(wrapper, api);
  } catch (BitcoinException btcEx) {
    FAIL() << btcEx.getMessage();
  }

  ASSERT_EQ(wrapper.getToIdWallets().size(), 1);
  ASSERT_EQ(wrapper.getToIdWallets().at(0), "3FujxL6aYLU8KR9PHLaa7k51qBBdHnFRfi");
  ASSERT_EQ(wrapper.getFromIdWallets().size(), 1);
  ASSERT_EQ(wrapper.getFromIdWallets().at(0), "3Aj9iSzgxjdwTSyUDx8iQbuHtWhBud2GrD");
}

//This transaction is real because is my tx
TEST(decode_script_command_test, decode_script_execute_command)
{
  string pathMockRoot = ConfiguratorSingleton::getInstance().getDirDatatest() + "/";
  string pathLogRoot = ConfiguratorSingleton::getInstance().getDirLogTest() + "/";

  FLAGS_minloglevel = 0;
  FLAGS_logtostderr = true;
  google::SetLogDestination(google::GLOG_ERROR, pathLogRoot.append("decode_script_execute_command.log").c_str());

  WrapperInformations wrapper;
  //Insert inside the wrapper the information coinbase
  //Thi si the reference transaction
  //https://blockstream.info/tx/bd28376c31d39233c7ab832515e1b68808678319232034bb5a98a997b05ae418
  //The previeus hash tx is get to this reference https://www.blockchain.com/btc/address/1Peysn8vEPV1emkfRQ8rh3tiR1vDnb7Cxw
  wrapper.setHashPreviousTx("e664f6a3197402534abc5b6d1d918dd6a3ba764f8defcc54ad386b71f7b0862a");
  wrapper.setNOutpoint(0);
  wrapper.setTo("a9149bf9d68af78d22c3040a4714c928c6ba9481519887");

  vector<string> informations{"bd28376c31d39233c7ab832515e1b68808678319232034bb5a98a997b05ae418"};
  wrapper.setLinkInformations(informations);

  BitcoinAPI api(ConfiguratorSingleton::getInstance().getUser(),
                       ConfiguratorSingleton::getInstance().getPassword(),
                       ConfiguratorSingleton::getInstance().getHost(),
                       ConfiguratorSingleton::getInstance().getPort());

  DecodeScriptCommand decodeScript;

  try
  {
    decodeScript.doCommand(wrapper, api);
  } catch (BitcoinException btcEx) {
    FAIL() << btcEx.getMessage();
  }

  ASSERT_EQ(wrapper.getTo(), "a9149bf9d68af78d22c3040a4714c928c6ba9481519887");
}
