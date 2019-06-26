#ifndef QT3DPHYSICS_QPHYSICSENGINEFACTORY_P_H
#define QT3DPHYSICS_QPHYSICSENGINEFACTORY_P_H

#include <Qt3DPhysics/private/qt3dphysics_global_p.h>
#include <QtCore/qstringlist.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

class QPhysicsEngine;

class QT3DPHYSICS_PRIVATE_EXPORT QPhysicsEngineFactory {
public:
    static QStringList keys(const QString &pluginPath = QString());
    static QPhysicsEngine * create(const QString &name,
                                   const QStringList &args,
                                   const QString &pluginPath = QString());
};

}

QT_END_NAMESPACE

#endif // QPHYSICSPLUGINFACTORY_P_H
