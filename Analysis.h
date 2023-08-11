#pragma once
#include<memory>
#include<cstddef>
#include <vector>
#include<variant>
#include<any>
using namespace std;
//typedef std::any ReturnType;
//typedef variant<int, double,string> ReturnType;

class Analysis
{
public:
    Analysis();
    ~Analysis();

    /// <summary>
    /// 操作模式
    /// </summary>
    enum SimensMode
    {

        JOG,//手动模式
        TEACHIN,//子运行模式示教
        MDA,//mdi
        AUTO,//自动运行模式
        REPOS,//再定位，重新逼近轮廓
        REFPOINT,//返回参考点
        VAR,//以可变增量运行
        INC,//增量进给
        Mode_OTHER//未知
    };
    /// <summary>
    /// 运行状态
    /// </summary>
    enum SimensStatus
    {
        RESET = 0,//复位
        STOP = 1,//程序块结束
        HOLD = 2,//进给保持
        START = 3,//程序运行 
        SPENDLE_CW_CCW = 4,//主轴正反转
        Satus_OTHER = 5
    };
    /// <summary>
    /// 解析操作模式
    /// </summary>
    /// <param name="datas"></param>
    /// <param name="len"></param>
    /// <returns></returns>
    int AnalysisModeData(byte* datas)
    {
        if (datas[24] == 0x02)
        {
            if (datas[31] == 0x00)
            {
                if (datas[25] == 0x00)
                {
                    return (int)SimensMode::JOG;
                }
                else if (datas[25] == 0x01)
                {
                    return (int)SimensMode::MDA;
                }
                else if (datas[25] == 0x02)
                {
                    return (int)SimensMode::AUTO;
                }
                else
                {
                    return (int)SimensMode::Mode_OTHER;
                }
            }
            else if (datas[31] == 0x03)
            {
                return (int)SimensMode::REFPOINT;
            }
            else
            {
                return (int)SimensMode::Mode_OTHER;
            }
        }
        else
        {
            return (int)SimensMode::Mode_OTHER;
        }
    }
    /// <summary>
    /// 解析运行状态
    /// </summary>
    /// <param name="datas"></param>
    /// <returns></returns>
    int AnalysisStatusData(byte* datas)
    {
        if (datas[24] == 0x02)
        {
            if ((datas[25] == 0x00) && (datas[31] == 0x05))
                return ((int)SimensStatus::RESET);
            else if ((datas[25] == 0x02) && (datas[31] == 0x02))
                return ((int)SimensStatus::STOP);
            else if ((datas[25] == 0x01) && (datas[31] == 0x03))
                return ((int)SimensStatus::START);
            else if ((datas[25] == 0x01) && (datas[31] == 0x05))
                return ((int)SimensStatus::SPENDLE_CW_CCW);
            else
                return ((int)SimensStatus::Satus_OTHER);
        }
        else
        {
            return ((int)SimensStatus::Satus_OTHER);
        }
    }

    float  AnalysisFloatData(byte* datas)
    {
        auto value = *reinterpret_cast<float*>(datas[25]);
        std::reverse(reinterpret_cast<char*>(&value), reinterpret_cast<char*>(&value) + sizeof(float));
        return value;
    }
    double AnalysisDoubleData(byte* datas)
    {
        double value = NULL;
        if (datas[3] == 33)
        {
            value = *reinterpret_cast<double*>(datas[25]);
            std::reverse(reinterpret_cast<char*>(&value), reinterpret_cast<char*>(&value) + sizeof(double));
        }
        else
        {
            value = *reinterpret_cast<double*>(datas[0]);
            std::reverse(reinterpret_cast<char*>(&value), reinterpret_cast<char*>(&value) + sizeof(double));
        }

        return value;
    }
    short AnalysisInt32Data(byte* datas)
    {
        string ss(datas + 25, datas + 27);
        short value = *reinterpret_cast<short*>(&ss);
        return value;

        //        std::vector<char> datas = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
        //        short value = *reinterpret_cast<short*>(&datas[25]);



            ///*string ss(datas, datas + sizeof(datas));
            //ss = ss.substr(0, ss.size() - 1);
            //auto value = *reinterpret_cast<int*>(datas[25]);
            //
            //string s(reinterpret_cast<char*>(&ss);
            //s.erase(remove(s.begin(), s.end(), '\0'), s.end());

            //int value = (datas[25] << 8) | datas[26];*/
    }
    string AnalysisStrData(byte* datas)
    {
        string value(datas + 25, datas + sizeof(datas));
        return value;

        //string ss(datas, datas + sizeof(datas));
        //ss = ss.substr(0, ss.size() - 1);
        //auto value = "";
        ///*ss.erase(remove(ss.begin(), ss.end(), '\0'), ss.end());
        //string value = (datas[25] << 8) | datas[26];*/
        //return value;
    }
    int AnalysisAlarm(byte* datas)
    {
        string ss(datas + 25, datas + 29);
        int value = *reinterpret_cast<int*>(&ss);
        //value = *reinterpret_cast<double*>(datas[25]);
        //std::reverse(reinterpret_cast<char*>(&value), reinterpret_cast<char*>(&value) + sizeof(double));
        return value;
    }


private:

};

Analysis::Analysis()
{
}

Analysis::~Analysis()
{
}
