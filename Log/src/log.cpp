#include "../include/log.h"
//构造函数
//引用必须用初始化列表初始化

Log::Log() :root_(log4cpp::Category::getInstance("infoCategory"))
{
    initLog();
}
Log::Log(string strLogName) : root_(log4cpp::Category::getInstance("infoCategory")),m_strLogName(strLogName)
{
    initLog();
}
void Log::initLog() {

    std::cout << "Mylog()" << std::endl;
    //创建Layout并设置成pattern模式
    pLayout_cout_ = new log4cpp::PatternLayout();
    pLayout_cout_->setConversionPattern("%d: %p %c %x: %m%n");
    pLayout_file_ = new log4cpp::PatternLayout();
    pLayout_file_->setConversionPattern("%d: %p %c %x: %m%n");
    pLayout_rollfile_ = new log4cpp::PatternLayout();
    pLayout_rollfile_->setConversionPattern("%d: %p %c %x: %m%n");

    //创建Appender并将layout对象绑定
    osAppender_ = new log4cpp::OstreamAppender("osAppender_", &std::cout);
    osAppender_->setLayout(pLayout_cout_);

    //日志文件保存在固定的文件夹中
    fileAppender_ = new log4cpp::FileAppender("fileAppender_", m_strLogName);
    fileAppender_->setLayout(pLayout_file_);

    //回滚文件也是保存在固定地方，为了便于测试把文件大小设置成1*1024
    rollfileAppender_ = new log4cpp::RollingFileAppender("rollfileAppender_", m_strLogName, 1 * 1024, 3);
    rollfileAppender_->setLayout(pLayout_rollfile_);

    //log4cpp::Category & root_ = log4cpp::Category::getInstance("infoCategory");//不能再这初始化，引用必须在初始化列表中

    //把Appender对象附到category上,一个category可以有多个appender
    root_.addAppender(osAppender_);
    root_.addAppender(fileAppender_);
    root_.addAppender(rollfileAppender_);
}
//设置优先级
void Log::set_priority(const char* prioritylevel)
{
    if (prioritylevel == "DEBUG")
        root_.setPriority(log4cpp::Priority::DEBUG);
    else if (prioritylevel == "ERROR")
        root_.setPriority(log4cpp::Priority::ERROR);
    else if (prioritylevel == "WARN")
        root_.setPriority(log4cpp::Priority::WARN);
    else if (prioritylevel == "INFO")
        root_.setPriority(log4cpp::Priority::INFO);
    else    //把优先级设置到最低
        root_.setPriority(801);
}

void Log::error(const char* msg)
{
    std::cout << "error()" << std::endl;
    root_.error(msg);
}

void Log::warn(const char* msg)
{
    std::cout << "warn()" << std::endl;
    root_.warn(msg);
}
void Log::info(const char* msg)
{
    std::cout << "info()" << std::endl;
    root_.info(msg);
}

void Log::debug(const char* msg)
{
    std::cout << "debug()" << std::endl;
    root_.debug(msg);
}

//析构函数
Log::~Log()
{
    std::cout << "~Mylog()" << std::endl;
    log4cpp::Category::shutdown();
}