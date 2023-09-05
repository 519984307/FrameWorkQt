/*****************************************************************//**
 * \file   log.h
 * \brief  
 * 
 * \author shijiaobing
 * \date   September 2023
 *********************************************************************/



#ifndef  _LOG_H_
#define  _LOG_H_


#include "log_global.h"
#include"log4cpp/Category.hh"

#include"log4cpp/Appender.hh"
#include"log4cpp/FileAppender.hh"
#include"log4cpp/RollingFileAppender.hh"
#include"log4cpp/OstreamAppender.hh"

#include"log4cpp/PatternLayout.hh"
#include"log4cpp/Priority.hh"
#include <iostream>
using namespace std;

//1.实现日志文件信息在终端上显示
//2.实现日志文件信息在终端和日志文件同时显示
//3.实现回滚备份，替换掉2即可
class LOG_EXPORT Log
{
public:
    Log();
    Log(string strLogName);
    ~Log();
public:
    void error(const char* msg);
    void warn(const char* msg);
    void info(const char* msg);
    void debug(const char* msg);

    void set_priority(const char*);
protected:
    void initLog();


private:
    //布局
    log4cpp::PatternLayout* pLayout_cout_;
    log4cpp::PatternLayout* pLayout_file_;
    log4cpp::PatternLayout* pLayout_rollfile_;

    //依附目标文件
    log4cpp::OstreamAppender* osAppender_;
    log4cpp::FileAppender* fileAppender_;
    log4cpp::RollingFileAppender* rollfileAppender_;

    //种类
    log4cpp::Category& root_;
    string m_strLogName = "log";
};


#endif // ! _LOG_H_
