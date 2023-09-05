#include "../include/singleapplication.h"

#include <QLocalSocket>


SingleApplication::SingleApplication(int argc, char** argv, const QString& uniqueKey)
	:QApplication(argc, argv), m_strUniqueKey(uniqueKey)
{
	initApp();
}

bool SingleApplication::isRunning()
{
	return m_bIsRunning;
}

bool SingleApplication::sendMessage(const QString& msg)
{
	if (!m_bIsRunning)
		return false;
	QLocalSocket  localSocket(this);
	localSocket.connectToServer(m_strUniqueKey, QIODevice::WriteOnly);
	if (!localSocket.waitForConnected(m_nTimeOut)) {
		return false;
	}
	localSocket.write(msg.toUtf8());
	if (!localSocket.waitForBytesWritten(m_nTimeOut)) {
		return false;
	}
	localSocket.disconnectFromServer();
	return true;

}


void SingleApplication::initApp()
{
	m_sharedMemory.setKey(m_strUniqueKey);
	if (m_sharedMemory.attach()) {
		m_bIsRunning = true;
	}
	else
	{
		m_bIsRunning = false;
		if (!m_sharedMemory.create(1)) {
			return;
		}
		m_pLocalServer = new QLocalServer(this);
		connect(m_pLocalServer, SIGNAL(newConnection()), this, SLOT(receiveMessage()));
		m_pLocalServer->listen(m_strUniqueKey);
	}
}


void SingleApplication::receiveMessage() {

	QLocalSocket* localSocket = m_pLocalServer->nextPendingConnection();
	if (!localSocket->waitForReadyRead(m_nTimeOut)) {
		return;
	}


	QByteArray  byteArray = localSocket->readAll();
	QString message = QString::fromUtf8(byteArray.constData());
	emit sglSendExistedMessage(message);
	localSocket->disconnectFromServer();
	
}
