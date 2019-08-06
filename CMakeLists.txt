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

        core/graph/TransactionGraph.cpp
        core/graph/WrapperInformations.cpp

        commands/DecodeScriptCommand.cpp

        ConfiguratorSingleton.cpp

        main.cpp
)

add_executable(
        SpyCBlockRPCTest

        #cpp-properties file include
        lib/cpp-properties/src/Properties.cpp
        lib/cpp-properties/src/PropertiesParser.cpp
        lib/cpp-properties/src/PropertiesUtils.cpp

        core/graph/TransactionGraph.cpp
        core/graph/WrapperInformations.cpp
        commands/DecodeScriptCommand.cpp

        ConfiguratorSingleton.cpp


        #Test
        test/SerializationMockTest.cpp

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
