#pragma once
#include<memory>
#include<string>
#include <cstddef>
#include"ETH_S7SimensCommands.h"
#include"Model.h"
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include<iomanip>
#include"Analysis.h"
#include"SocketClient.h"
#include"PollTag.h"
class SimensCNCS7Driver
{
public:
    SimensCNCS7Driver();
    SimensCNCS7Driver(const char* config);
    ~SimensCNCS7Driver();
    string DriverName = "MIOT.SimensCNCS7.Driver";

    // void init(const char* config);
    //OperateResult Connect();
    void DisConnect();

    bool Connect();

    string ReadItem(PollTag polltag);
    //
    //ValueTake<OperateResult>ReadItem(pollTag);

private:
    SocketClient _client;
    string ip = "127.0.0.1";
    int port = 8001;
    Model _model;
    ETH_S7SimensCommands _eth_S7SimensCommands;
    Analysis _analysis;
    void HandShake();
    string send(byte* cmd, string analysis);
    string getPos(int num, string address);

};