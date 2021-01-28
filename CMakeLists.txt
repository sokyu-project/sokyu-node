cmake_minimum_required(VERSION 3.10)

project(SokyuNode VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)

find_package(Threads)

list(APPEND SOURCE_FILES
	main.cpp

	src/Node.cpp
	src/Logger.cpp
        src/Hash.cpp

	src/blockchain/Blockchain.cpp

	src/network/Address.cpp
	src/network/Client.cpp
	src/network/Network.cpp
	src/network/NetworkHandler.cpp
	src/network/Packet.cpp
	src/network/Peer.cpp
	src/network/PeerManager.cpp
	src/network/Server.cpp
        src/network/Bucket.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/blockchain)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/network)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/storage)

add_executable(SokyuNode ${SOURCE_FILES})

target_link_libraries(SokyuNode Threads::Threads)
