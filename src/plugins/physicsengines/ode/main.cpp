
#include "odeengine.h"
#include <Qt3DPhysics/private/qphysicsengineplugin_p.h>

#include <QDebug>

QT_BEGIN_NAMESPACE

class OdePhysicsPlugin : public Qt3DPhysics::QPhysicsEnginePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QPhysicsEngineFactoryInterface_iid FILE "ode.json")

    Qt3DPhysics::QPhysicsEngine *create(const QString &key, const QStringList &params) override
    {
        qDebug() << __PRETTY_FUNCTION__ << key << params;
        return new Qt3DPhysics::OdeEngine();
    }
};

QT_END_NAMESPACE

#include "main.moc"

