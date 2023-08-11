#pragma once
#include <string>
using namespace std;
class PollTag
{
public:
    int ByteOrder;
    string* paramList;

    string old_value;
    string raw_value;
    string Value;
    string errorMessage;
    //    [DisplayName("点位类型")]
    int tagType;
    //  [DisplayName("是否变化推送")]
    int changeReporting;
    //[DisplayName("本次是否需要推送")]
    bool IsNeedPush;
    //[DisplayName("数据读取完成时间")]
    long FinishedTime;
    //[DisplayName("数据读取完成时间")]
    //[JsonIgnore]
    long StartReadTime;
    //[DisplayName("推送数据的时间")]
    long PushTime;
    //[DisplayName("失败数据统计")]
    long FailedCount;
    //[DisplayName("读取数据统计")]
    long ReadCount;
    //[DisplayName("采集频率")]
    //[JsonProperty("readInterval")]
    int ReadInterval;
    //[DisplayName("数据类型")]
    //[JsonProperty("dataType")]
    int   DataType;
    //[DisplayName("点位启停")]
    //[JsonProperty("state")]
    int   State;
    //[DisplayName("访问类型")]
    //[JsonProperty("attribute")]
    int   Attribute;
    //[DisplayName("表达式")]
   // [JsonProperty("expl")]
    string   Expl;
    // [DisplayName("读取长度")]
     //[JsonProperty("len")]
    int   Len;
    //[DisplayName("地址码")]
    //[JsonProperty("address")]
    string   Address;
    //[DisplayName("功能码")]
   // [JsonProperty("funcCode")]
    int   FuncCode;
    //[DisplayName("点位名称")]
    //[JsonProperty("name")]
    string   Name;
    //[DisplayName("点位ID")]
   // [JsonProperty("tagId")]
    string   TagId;
    bool IsDataChange;
    int   characterSet;
};

