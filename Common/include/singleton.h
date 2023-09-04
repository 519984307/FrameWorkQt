#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include <QMutexLocker>
#include <QMutex>
#include <QAtomicPointer>
template<typename T>
class Singleton {

public:
	static T* instance()
	{
		if (s_instance.testAndSetOrdered(0, 0)) {
			QMutexLocker locker(s_mutex);
			if (s_instance.testAndSetOrdered(0, 0)) {
				s_instance.store(new T);
			}
		}
		return s_instance.load();
	}
	static void destroy()
	{
		T* tins = s_instance.fetchAndStoreOrdered(0);// Atomic fetch-and-store
		if (tins) {
			delete tins;
		}
	}
	static bool isInstanceExist()
	{
		return !(s_instance.testAndSetOrdered(0, 0));
	}
protected:
	Singleton() {}
	~Singleton() {}
private:
	Singleton(const Singleton&);
	Singleton& operator =(const Singleton&);

private:
	static QMutex* s_mutex;
	static QAtomicPointer<T> s_instance;


};


template <typename T>
QMutex* Singleton<T>::s_mutex = new QMutex;

template <typename T>
QAtomicPointer<T> Singleton<T>::s_instance;

#define  DECLARE_CONSTRUCT(CLASS_NAME) \
    protected:\
    CLASS_NAME();\
    ~CLASS_NAME();\
    friend class Singleton<CLASS_NAME>;

#define  DECLARE_CONSTRUCT_PARENT(CLASS_NAME,PARENT_NAME)\
    protected:\
    explicit CLASS_NAME(PARENT_NAME*parent=nullptr);\
    ~CLASS_NAME();\
    friend class Singleton<CLASS_NAME>;


#endif  //_SINGLETON_H_
