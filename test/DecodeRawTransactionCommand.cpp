#include <gtest/gtest.h>
#include <glog/logging.h>

#include "../core/graph/ITransactionGraph.h"
#include "../core/graph/TransactionGraph.h"
#include "../core/graph/WrapperInformations.h"
#include "../ConfiguratorSingleton.h"
#include "../commands/RPCCommandMediator.h"

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
  //The previeus hash tx is get to this reference https://www.blockchain.com/btc/address/1Peysn8vEPV1emkfRQ8rh3tiR1vDnb7Cxw
  wrapper.setHashPreviousTx("0000000000000000000000000000000000000000000000000000000000000000");
  wrapper.setNOutpoint(5000000000);

  vector<string> informations{"bd28376c31d39233c7ab832515e1b68808678319232034bb5a98a997b05ae418"};
  wrapper.setLinkInformations(informations);

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
TEST(decode_script_command_test, decode_raw_tx_execute_command)
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
  wrapper.setHashPreviousTx("d86e8dae82c2d17bed80a8b98d0a524c0b3851060747ae17322115ab69831adb");
  wrapper.setNOutpoint(558612);
  wrapper.setTo("a9149bf9d68af78d22c3040a4714c928c6ba9481519887");

  vector<string> informations{"bd28376c31d39233c7ab832515e1b68808678319232034bb5a98a997b05ae418"};
  wrapper.setLinkInformations(informations);

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

  ASSERT_EQ(wrapper.getFrom(), "76a914429cd5f16354f256ae4a5b0b7bf81b10889a77ac88ac");
}
