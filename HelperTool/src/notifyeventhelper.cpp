#include "notifyeventhelper.h"

#include <QMap>
#include <QList>
#include <QReadLocker>
#include <QReadWriteLock>

static QMap<NotifyEventHelper::EventType, QList<std::pair<NotifyEventHelper::notify_event_function, void*> > > g_notifys;
static QReadWriteLock* s_lock = new QReadWriteLock;
void NotifyEventHelper::add(EventType eventType, notify_event_function func, void* context)
{
	QWriteLocker locker(s_lock);
	g_notifys[eventType].push_back(std::make_pair(func, context));
}

void NotifyEventHelper::remove(notify_event_function func, void* context)
{
	QWriteLocker locker(s_lock);
	for (auto it = g_notifys.begin(); it != g_notifys.end(); ++it) {
		auto funcIt = std::remove_if(it.value().begin(), it.value().end(), [=](const std::pair<notify_event_function, void*>& p) -> bool {
			if (p.first == func && p.second == context) {
				return true;
			}
			else {
				return false;
			}
			});
		it.value().erase(funcIt, it.value().end());
	}
}

void NotifyEventHelper::notify(EventType type, int event, void* data)
{
	QList<std::pair<notify_event_function, void*>> funs;

	{
		QReadLocker locker(s_lock);
		auto it = g_notifys.find(type);
		if (it == g_notifys.end()) {
			//            qDebug() << __FUNCTION__ << GetCurrentThreadId() << "end";
			return;
		}
		funs = *it;
	}


	for (auto it = funs.begin(); it != funs.end(); ++it) {
		if (it->first) {
			it->first(event, data, it->second);
		}
	}
}

void NotifyEventHelper::notify(int event, void* data /*= nullptr*/)
{
	notify(DEFAULT_EVENT, event, data);
}

void NotifyEventHelper::clear()
{

	QWriteLocker locker(s_lock);
	g_notifys.clear();
}






