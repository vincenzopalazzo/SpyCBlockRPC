cmake_minimum_required(VERSION 3.1)
project(SpyCBlockRPC)

set(CMAKE_CXX_STANDARD 14)

# Locate GTest
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#Glog
find_package(glog 0.3.5 REQUIRED)

#bitcoin rpc lib
find_library(bitcoinapi 0.3 REQUIRED)

add_executable(
        ${PROJECT_NAME}

        #cpp-properties file include
        lib/cpp-properties/src/Properties.cpp
        lib/cpp-properties/src/PropertiesParser.cpp
        lib/cpp-properties/src/PropertiesUtils.cpp

        src/core/graph/TransactionGraph.cpp
        src/core/graph/WrapperInformations.cpp

        src/commands/DecodeScriptCommand.cpp
        src/commands/DecodeRawTransaction.cpp
        src/commands/HeightBlockchainCommand.cpp
        src/commands/DecodeBlockAtIndexCommand.cpp

        src/ConfiguratorSingleton.cpp

        src/main.cpp
)

add_executable(

        SpyCBlockRPCTest

        #cpp-properties file include
        lib/cpp-properties/src/Properties.cpp
        lib/cpp-properties/src/PropertiesParser.cpp
        lib/cpp-properties/src/PropertiesUtils.cpp

        src/core/graph/TransactionGraph.cpp
        src/core/graph/WrapperInformations.cpp

        src/commands/DecodeScriptCommand.cpp
        src/commands/DecodeRawTransaction.cpp
        src/commands/HeightBlockchainCommand.cpp
        src/commands/DecodeBlockAtIndexCommand.cpp

        src/ConfiguratorSingleton.cpp


        #Test
        test/SerializationMockTest.cpp
        test/RPCCOmmandMediatorTest.cpp
        test/DecodeScriptCommandTest.cpp
        test/DecodeRawTransactionCommand.cpp

        )

#using glog
target_link_libraries(${PROJECT_NAME} glog::glog)
target_link_libraries(SpyCBlockRPCTest glog::glog)

#bitcoin rpc lib
target_link_libraries(SpyCBlockRPCTest bitcoinapi)
target_link_libraries(${PROJECT_NAME} bitcoinapi)

#using gtest
target_link_libraries(SpyCBlockRPCTest ${GTEST_LIBRARIES} pthread)

##using filesystem
target_link_libraries(${PROJECT_NAME} stdc++fs)
target_link_libraries(SpyCBlockRPCTest stdc++fs)
