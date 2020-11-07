#ifndef DLT698MYSQL_GLOBAL_H
#define DLT698MYSQL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DLT698MYSQL_LIBRARY)
#  define DLT698MYSQLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DLT698MYSQLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DLT698MYSQL_GLOBAL_H
