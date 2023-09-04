#ifndef _NOTIFY_EVENT_HLEPER_H_
#define _NOTIFY_EVENT_HLEPER_H_
#include "helper_tool_global.h"
#include <QMap>
#include <QList>
#include <QReadLocker>
#include <QReadWriteLock>


class HELPER_TOOL_EXPORT NotifyEventHelper {

public:
	enum EventType
	{
		DEFAULT_EVENT,


	};
	using  notify_event_function = void (*)(int eventType, void* data, void* context);

	static void add(EventType eventType, notify_event_function func,void* context);
	static void remove(notify_event_function func,void * context);
	static void notify(EventType type,int event,void *data);
	static void notify(int event, void* data = nullptr);
	static void clear();
};

#endif
