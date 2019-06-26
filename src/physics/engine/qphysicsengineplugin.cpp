#include "qphysicsengineplugin_p.h"

#include <QtDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

QPhysicsEnginePlugin::QPhysicsEnginePlugin(QObject *parent)
    : QObject(parent)
{
    qDebug() << __PRETTY_FUNCTION__;
}

QPhysicsEnginePlugin::~QPhysicsEnginePlugin()
{
    qDebug() << __PRETTY_FUNCTION__;
}

QPhysicsEngine *QPhysicsEnginePlugin::create(const QString &key, const QStringList &paramList)
{
    qDebug() << __PRETTY_FUNCTION__;
    return nullptr;
}

}

QT_END_NAMESPACE
