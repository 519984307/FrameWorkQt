/*****************************************************************//**
 * \file   singleapplication.h
 * \brief  
 * 
 * 
 * \author shijiaobing
 * \date   September 2023
 *********************************************************************/
#ifndef _SINGLE_APPLICATION_H_
#define _SINGLE_APPLICATION_H_
#include "ui_global.h"
#include <QApplication>
#include <QLocalServer>
#include <QLocalSocket>
#include <QSharedMemory>
class UI_EXPORT SingleApplication  :public QApplication{
	Q_OBJECT
public:
	
	explicit SingleApplication(int argc, char** argv,const QString&uniqueKey);

	bool isRunning();

	bool sendMessage(const QString& message);
signals:
	void sglSendExistedMessage(QString message);

public slots:
	void receiveMessage();
	
protected:
	
	void initApp();

private:
	QLocalServer* m_pLocalServer=nullptr;
	bool m_bIsRunning = false;
	QString m_strUniqueKey;
	QSharedMemory m_sharedMemory;
	static const int m_nTimeOut = 1000;
};






#endif //!_SINGLE_APPLICATION_H_