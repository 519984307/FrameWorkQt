#ifndef _MEDIA_GLOBAL_H_
#define _MEDIA_GLOBAL_H_
#include <QtCore/qglobal.h>

# if defined(LOG_LIB)
#  define LOG_EXPORT Q_DECL_EXPORT
# else
#  define LOG_EXPORT Q_DECL_IMPORT
# endif

#endif // !_COMMON_GLOBAL_H_
