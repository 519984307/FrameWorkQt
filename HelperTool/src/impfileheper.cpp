#include "impfilehelper.h"
#include <QFile>

QString ImpFileHelper::readAllText(const QString& filePath)
{
	QFile file(filePath);
	if (file.open(QFile::ReadOnly)) {
		return file.readAll();
	}
	return QString();
}
