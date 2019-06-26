#include "qphysicsenginefactory_p.h"
#include "qphysicsengineplugin_p.h"
#include "qphysicsengine_p.h"

#include <QtCore/private/qfactoryloader_p.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

Q_GLOBAL_STATIC_WITH_ARGS(QFactoryLoader, loader, (QPhysicsEngineFactoryInterface_iid, QLatin1String("/engines"), Qt::CaseInsensitive))
#ifndef QT_NO_LIBRARY
Q_GLOBAL_STATIC_WITH_ARGS(QFactoryLoader, directLoader, (QPhysicsEngineFactoryInterface_iid, QLatin1String(""), Qt::CaseInsensitive))
#endif

QStringList QPhysicsEngineFactory::keys(const QString &pluginPath)
{
    QStringList list;

    return list;
}

QPhysicsEngine * QPhysicsEngineFactory::create(const QString &name, const QStringList &args, const QString &pluginPath)
{
    return nullptr;
}

}

QT_END_NAMESPACE
