#ifndef _HELPER_TOOL_GLOBAL_H_
#define _HELPER_TOOL_GLOBAL_H_
#include <QtCore/qglobal.h>

# if defined(HELPER_TOOL_LIB)
#  define HELPER_TOOL_EXPORT Q_DECL_EXPORT
# else
#  define HELPER_TOOL_EXPORT Q_DECL_IMPORT
# endif

#endif // !_HELPER_TOOL_GLOBAL_H_
