cmake_minimum_required(VERSION 3.1)
project(SpyCBlockRPC)

set(CMAKE_CXX_STANDARD 14)

#Glog
find_package(glog 0.3.5 REQUIRED)
#bitcoin rpc lib
find_library(bitcoinapi 0.3 REQUIRED)
#Rapid json
find_package(RapidJSON)

add_executable(
        ${PROJECT_NAME}

        #cpp-properties file include
        lib/cpp-properties/src/Properties.cpp
        lib/cpp-properties/src/PropertiesParser.cpp
        lib/cpp-properties/src/PropertiesUtils.cpp

        main.cpp
)

#using glog
target_link_libraries(${PROJECT_NAME} glog::glog)
target_link_libraries(${PROJECT_NAME} bitcoinapi)
target_link_libraries(${PROJECT_NAME} stdc++fs)
