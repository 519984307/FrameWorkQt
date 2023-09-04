#ifndef _SINGLE_APPLICATION_H_
#define _SINGLE_APPLICATION_H_
#include "ui_global.h"
#include <QApplication>
#include <QLocalServer>
#include <QLocalSocket>
class UI_EXPORT SingleApplication  :public QApplication{
	Q_OBJECT
public:
	explicit SingleApplication(int argc, char** argv);

	bool isRunning();
	bool sendMessage(const QString& msg);
signals:
	void sglMessage(QString message);

public slots:
	void receiveMessage(const QString& msg);
	




protected:
	void initApplication();





private:
	QLocalServer* m_localServer=nullptr;
	bool m_bIsRunning = false;
};






#endif //!_SINGLE_APPLICATION_H_