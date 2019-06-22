#ifndef QT3DPHYSICS_GLOBAL_H
#define QT3DPHYSICS_GLOBAL_H

#include <QtCore/qglobal.h>
#include <Qt3DPhysics/qt3dphysics-config.h>

QT_BEGIN_NAMESPACE

#if defined(QT_SHARED) || !defined(QT_STATIC)
#  if defined(QT_BUILD_3DPHYSICS_LIB)
#    define QT3DPHYSICSSHARED_EXPORT Q_DECL_EXPORT
#  else
#    define QT3DPHYSICSSHARED_EXPORT Q_DECL_IMPORT
#  endif
#else
#  define QT3DPHYSICSSHARED_EXPORT
#endif

QT_END_NAMESPACE

#endif // QT3DPHYSICS_GLOBAL_H
