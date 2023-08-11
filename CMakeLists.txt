# CMakeList.txt: Simens 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("Simens")

include_directories(include)
# 将源代码添加到此项目的可执行文件。
#include( "Analysis.h" "CommandAttribute.h" "CTcpClient.h" "CUdpClient.h" "ETH_S7SimensCommands.h"  "Model.h" "PollTag.h" "SimensCNCS7Driver.h" "SocketClient.h")
add_executable (Simens  "Analysis.h" "CommandAttribute.cpp" "CommandAttribute.h" "CTcpClient.cpp" "CTcpClient.h" "CUdpClient.cpp" "CUdpClient.h" "ETH_S7SimensCommands.h" "ETH_S7SimensCommands.cpp" "Model.h" "PollTag.h" "SimensCNCS7Driver.cpp" "SimensCNCS7Driver.h" "SocketClient.cpp" "SocketClient.h" "main.cpp")
add_library(SimensCNCDriver  "Analysis.h" "CommandAttribute.cpp" "CommandAttribute.h" "CTcpClient.cpp" "CTcpClient.h" "CUdpClient.cpp" "CUdpClient.h" "ETH_S7SimensCommands.h" "ETH_S7SimensCommands.cpp" "Model.h" "PollTag.h" "SimensCNCS7Driver.cpp" "SimensCNCS7Driver.h" "SocketClient.cpp" "SocketClient.h" "main.cpp")
#ADD_SUBDIRECTORY(lib)
# TODO: 如有需要，请添加测试并安装目标。
