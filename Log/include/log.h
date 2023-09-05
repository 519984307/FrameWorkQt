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

//1.ʵ����־�ļ���Ϣ���ն�����ʾ
//2.ʵ����־�ļ���Ϣ���ն˺���־�ļ�ͬʱ��ʾ
//3.ʵ�ֻع����ݣ��滻��2����
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
    //����
    log4cpp::PatternLayout* pLayout_cout_;
    log4cpp::PatternLayout* pLayout_file_;
    log4cpp::PatternLayout* pLayout_rollfile_;

    //����Ŀ���ļ�
    log4cpp::OstreamAppender* osAppender_;
    log4cpp::FileAppender* fileAppender_;
    log4cpp::RollingFileAppender* rollfileAppender_;

    //����
    log4cpp::Category& root_;
    string m_strLogName = "log";
};


#endif // ! _LOG_H_
