#include "../include/log.h"
//���캯��
//���ñ����ó�ʼ���б��ʼ��

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
    //����Layout�����ó�patternģʽ
    pLayout_cout_ = new log4cpp::PatternLayout();
    pLayout_cout_->setConversionPattern("%d: %p %c %x: %m%n");
    pLayout_file_ = new log4cpp::PatternLayout();
    pLayout_file_->setConversionPattern("%d: %p %c %x: %m%n");
    pLayout_rollfile_ = new log4cpp::PatternLayout();
    pLayout_rollfile_->setConversionPattern("%d: %p %c %x: %m%n");

    //����Appender����layout�����
    osAppender_ = new log4cpp::OstreamAppender("osAppender_", &std::cout);
    osAppender_->setLayout(pLayout_cout_);

    //��־�ļ������ڹ̶����ļ�����
    fileAppender_ = new log4cpp::FileAppender("fileAppender_", m_strLogName);
    fileAppender_->setLayout(pLayout_file_);

    //�ع��ļ�Ҳ�Ǳ����ڹ̶��ط���Ϊ�˱��ڲ��԰��ļ���С���ó�1*1024
    rollfileAppender_ = new log4cpp::RollingFileAppender("rollfileAppender_", m_strLogName, 1 * 1024, 3);
    rollfileAppender_->setLayout(pLayout_rollfile_);

    //log4cpp::Category & root_ = log4cpp::Category::getInstance("infoCategory");//���������ʼ�������ñ����ڳ�ʼ���б���

    //��Appender���󸽵�category��,һ��category�����ж��appender
    root_.addAppender(osAppender_);
    root_.addAppender(fileAppender_);
    root_.addAppender(rollfileAppender_);
}
//�������ȼ�
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
    else    //�����ȼ����õ����
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

//��������
Log::~Log()
{
    std::cout << "~Mylog()" << std::endl;
    log4cpp::Category::shutdown();
}