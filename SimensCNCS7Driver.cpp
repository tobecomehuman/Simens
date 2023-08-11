#include"SimensCNCS7Driver.h"
#include"include/rapidjson/document.h"
#include"include/rapidjson/rapidjson.h"
#include"include/rapidjson/encodings.h"
using namespace rapidjson;
using namespace std;
SimensCNCS7Driver::SimensCNCS7Driver(const char* config)
{
    Document parse_config;
    parse_config.Parse(config);
    ip = parse_config["ip"].GetString();
    port = parse_config["port"].GetInt();
    _client = SocketClient(ip, port);
    _model = Model();
    _eth_S7SimensCommands = ETH_S7SimensCommands();

}

SimensCNCS7Driver::~SimensCNCS7Driver()
{
}
bool SimensCNCS7Driver::Connect()
{
    if (_client.isConnected)
    {
        cout << "已连接\n";
        return true;
    }
    auto flag = _client.Connect();
    cout << "SimensCNC 成功连接:" << flag << endl;
    if (_client.isConnected)
    {
        HandShake();
        cout << "握手连接成功\n";
        return true;
    }
    return flag;
}
/*   progStatus,
       opMode,
       driveLoad,
       speedOvr,
       cmdSpeed,
       actSpeed,
       feedRateOvr,
       cmdFeedRate,
       actFeedRate,
       toolNumber,
       progName,
       block,
       axisName,*/

string SimensCNCS7Driver::ReadItem(PollTag polltag)
{
    try
    {
        string prop = polltag.Address;
        /*auto value = NULL;*/
        if (prop == "progStatus")
        {
            return send(_eth_S7SimensCommands.CNC_STATUS, "AnalysisStatusData");
        }
        else if (prop == "opMode")
        {
            return send(_eth_S7SimensCommands.CNC_MODE, "AnalysisModeData");
        }
        else if (prop == "driveLoad")
        {
            return  send(_eth_S7SimensCommands.DRIVER_SPLOAD, "AnalysisFloatData");
        }
        else if (prop == "speedOvr")
        {
            return send(_eth_S7SimensCommands.CNC_SPINDRATE, "AnalysisDoubleData");
        }
        else if (prop == "cmdSpeed")
        {
            return send(_eth_S7SimensCommands.CNC_SPINDLESETSPEED, "AnalysisDoubleData");
        }
        else if (prop == "actSpeed")
        {
            return send(_eth_S7SimensCommands.CNC_SPINDLEACTSPEED, "AnalysisDoubleData");
        }
        else if (prop == "feedRateOvr")
        {
            return  send(_eth_S7SimensCommands.CNC_FEEDRATE, "AnalysisDoubleData");
        }
        else if (prop == "cmdFeedRate")
        {
            return  send(_eth_S7SimensCommands.CNC_FEEDSETSPEED, "AnalysisDoubleData");
        }
        else if (prop == "actFeedRate")
        {
            return send(_eth_S7SimensCommands.CNC_FEEDACTSPEED, "AnalysisDoubleData");
        }
        else if (prop == "toolNumber")
        {
            return send(_eth_S7SimensCommands.TOOL_NUMBER, "AnalysisInt32Data");
        }
        else if (prop == "progName")
        {
            return send(_eth_S7SimensCommands.PROGRAM_NAME, "AnalysisStrData");
        }
        else if (prop == "block")
        {
            return  send(_eth_S7SimensCommands.CurrentPro, "AnalysisStrData");
        }
        else if (prop == "alarmNo")
        {
            return  send(_eth_S7SimensCommands.CNC_ALARM, "AnalysisAlarm");
        }
        else if (prop == "axisName")
        {
            return send(_eth_S7SimensCommands.AXIS_NAME, "AnalysisStrData");
        }
        else {
            cout << "为找到相关命令\n";
        }
    }
    catch (const std::exception&)
    {
        cout << "读取失败!!!\n";
        exception::exception("Error!!!");
    }
}



void SimensCNCS7Driver::DisConnect()
{
    _client.isConnected = false;
    _client.~SocketClient();
    _model.~Model();
    _eth_S7SimensCommands.~ETH_S7SimensCommands();
}


void SimensCNCS7Driver::HandShake()
{
    //string handShakeCmd;
    //for (int i = 0; i < 22; i++)
    //{
    //    handShakeCmd += ETH_S7SimensCommands::FIRST_HAND_SHAKE[i];
    //}
    //auto buffer = new byte[1024];
    //handShakeCmd.clear();

    /*for (int i = 0; i < 25; i++)
    {
        handShakeCmd += ETH_S7SimensCommands::SECOND_HAND_SHAKE[i];
    }
    _client.Send(handShakeCmd);*/
    _client.Send(ETH_S7SimensCommands::FIRST_HAND_SHAKE);
    auto receive = _client.RecvByte();
    _client.Send(ETH_S7SimensCommands::SECOND_HAND_SHAKE);
    receive = _client.RecvByte();
    _client.Send(ETH_S7SimensCommands::THIRD_HAND_SHAKE);
    receive = _client.RecvByte();
}

string SimensCNCS7Driver::send(byte* cmd, string analysis)
{
    string result;
    byte* buffer = NULL;
    buffer = _eth_S7SimensCommands.getCommands(cmd);
    _client.Send(buffer);
    std::this_thread::sleep_for(chrono::milliseconds(10));
    auto recvBuffer = _client.RecvByte();
    // string result = std::to_string(_analysis.getMethod(analysis, recvBuffer)) ;

    if (analysis == "AnalysisAlarm")
    {
        result = std::to_string(_analysis.AnalysisAlarm(recvBuffer));
    }
    else if (analysis == "AnalysisStrData")
    {
        result = (_analysis.AnalysisStrData(recvBuffer));
    }
    else if (analysis == "AnalysisInt32Data")
    {
        result = std::to_string(_analysis.AnalysisInt32Data(recvBuffer));
    }
    else if (analysis == "AnalysisDoubleData")
    {
        result = std::to_string(_analysis.AnalysisDoubleData(recvBuffer));
    }
    else if (analysis == "AnalysisFloatData")
    {
        result = std::to_string(_analysis.AnalysisFloatData(recvBuffer));
    }
    else if (analysis == "AnalysisStatusData")
    {
        result = std::to_string(_analysis.AnalysisStatusData(recvBuffer));
    }
    else if (analysis == "AnalysisModeData")
    {
        result = std::to_string(_analysis.AnalysisModeData(recvBuffer));
    }
    else
    {
        cout << "Error: Can't find the method you want!\n";
    }
    return result;

};

string SimensCNCS7Driver::getPos(int num, string address)//不在Model里的，就是配置文件中的点位，这里只有坐标点位
{
    std::vector<byte>buffer;
    string sendBuffer;
    int i = 0;
    if (address == "machinePos") // 机械坐标
    {
        while (i < 36)
        {
            sendBuffer += _eth_S7SimensCommands.MACHINE_POS[i];
            i++;
        }

    }
    else if (address == "relPos") // 相对坐标
    {
        while (i)
        {
            sendBuffer += _eth_S7SimensCommands.RELATIVELY_POS[i];
            // buffer.push_back(_eth_S7SimensCommands.RELATIVELY_POS[i]);
            i++;
        }
    }
    else if (address == "remPos") // 剩余坐标
    {
        while (i)
        {
            sendBuffer += _eth_S7SimensCommands.REMAIN_POS[i];
            // buffer.push_back(_eth_S7SimensCommands.REMAIN_POS[i]);
            i++;
        }
    }
    if (!sendBuffer.empty())
    {
        cout << "msg:已接收到查询坐标相关命令\n";
        _client.Send(sendBuffer);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        auto recvBuffer = _client.RecvByte();
        byte  recvBuffer2[] = { 0, };
        for (size_t x = 0; i < 2048; x++)
        {
            recvBuffer2[x] = recvBuffer[x];
        }
        auto value = std::to_string(_analysis.AnalysisDoubleData(recvBuffer2));
        return value;
    }

    else
    {
        cout << "Error:未接收到任何坐标坐标信\n";
        return 0;
    }
};
//std::stringstream ss;
//ss << std::setprecision(25) << value;
//if (!buffer.empty())
//{
//    buffer[26] = static_cast<byte>(num);

//    _client.Send(buffer.data(), buffer.size());
//    auto bytes = _client.ReceiveByte();
//    auto value = AnalysisDoubleData(bytes);
//    return value;
//}