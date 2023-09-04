#ifndef _UI_GLOBAL_H_
#define _UI_GLOBAL_H_
#include <QtCore/qglobal.h>

# if defined(UI_LIB)
#  define UI_EXPORT Q_DECL_EXPORT
# else
#  define UI_EXPORT Q_DECL_IMPORT
# endif

#endif // !_UI_GLOBAL_H_
