#include "qphysicsengineplugin_p.h"

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

QQPhysicsEnginePlugin::QQPhysicsEnginePlugin(QObject *parent)
    : QObject(parent)
{

}

QQPhysicsEnginePlugin::~QQPhysicsEnginePlugin()
{

}

QPhysicsEngine *QQPhysicsEnginePlugin::create(const QString &key, const QStringList &paramList)
{
    return nullptr;
}

}

QT_END_NAMESPACE
