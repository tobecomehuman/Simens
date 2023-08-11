#pragma once
#include <ostream>
#include <cstddef>



#define Command(name, command, analysis) 
std::string name;
std::string command;
std::string analysis;

using namespace std;
class Model
{
public:
    std::string progStatus = "运行状态";
    std::string opMode = "工作模式";
    std::string driveLoad = "主轴负载";
    std::string speedOvr = "主轴倍率";
    std::string cmdSpeed = "主轴设定速度";
    std::string actSpeed = "主轴实际速度";
    std::string feedRateOvr = "进给倍率";
    std::string cmdFeedRate = "进给设定速度";
    std::string actFeedRate = "进给实际速度";
    std::string toolNumber = "刀具号";
    std::string progName = "程序号";
    std::string block = "当前程序内容";
    std::string alarmNo = "告警号";
    std::string axisName = "轴名称";

    enum class model_enum
    {
        progStatus,
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
        axisName,
    };


    Model();
    ~Model();

private:

};

Model::Model()
{
}

Model::~Model()
{
}