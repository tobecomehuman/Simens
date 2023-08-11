

file(GLOB SOURCES  "Analysis.h" "CommandAttribute.cpp" "CommandAttribute.h" "CTcpClient.cpp" "CTcpClient.h" "CUdpClient.cpp" "CUdpClient.h" "ETH_S7SimensCommands.h" "ETH_S7SimensCommans.cpp" "Model.h" "PollTag.h" "SimensCNCS7Driver.cpp" "SimensCNCS7Driver.h" "SocketClient.cpp" "SocketClient.h")

add_library(SimensCNCS7Driver SHARED ${SOURCES})