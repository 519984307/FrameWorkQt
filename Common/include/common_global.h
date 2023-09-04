#ifndef _COMMON_GLOBAL_H_
#define _COMMON_GLOBAL_H_
#include <QtCore/qglobal.h>

# if defined(COMMON_LIB)
#  define COMMON_EXPORT Q_DECL_EXPORT
# else
#  define COMMON_EXPORT Q_DECL_IMPORT
# endif

#endif // !_COMMON_GLOBAL_H_
