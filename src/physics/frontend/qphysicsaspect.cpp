#include "qphysicsaspect.h"
#include "qphysicsaspect_p.h"

#include <Qt3DPhysics/private/qt3dphysics-config_p.h>
#include <Qt3DPhysics/private/qphysicsenginefactory_p.h>
#include <Qt3DPhysics/private/qphysicsengine_p.h>
#include <Qt3DPhysics/private/manager_p.h>

#include <Qt3DPhysics/qrigidbody.h>
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>

#include <Qt3DPhysics/private/rigidbody_p.h>
#include <Qt3DPhysics/private/entity_p.h>
#include <Qt3DPhysics/private/transform_p.h>

#include <QDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

QPhysicsAspectPrivate::QPhysicsAspectPrivate(const QString &engine)
    : QAbstractAspectPrivate()
    , m_time(0)
    , m_initialized(false)
    , m_manager(new Physics::Manager)
    , m_engineType(engine)
    , m_engine(nullptr)

{
    qDebug() << __PRETTY_FUNCTION__;
}


QPhysicsAspectPrivate::~QPhysicsAspectPrivate()
{
    m_engine = nullptr;
    qDeleteAll(m_engines);
    m_engines.clear();
}

void QPhysicsAspectPrivate::registerBackendTypes()
{
    qDebug() << __PRETTY_FUNCTION__;

    Q_Q(QPhysicsAspect);

    q->registerBackendType<QRigidBody>(
                Qt3DCore::QBackendNodeMapperPtr(
                    new Physics::RigidBodyFunctor(
                        m_manager.data())));

    q->registerBackendType<Qt3DCore::QEntity>(
                Qt3DCore::QBackendNodeMapperPtr(
                    new Physics::EntityFunctor(
                        m_manager.data())));

    q->registerBackendType<Qt3DCore::QTransform>(
                Qt3DCore::QBackendNodeMapperPtr(
                    new Physics::TransformFunctor(
                        m_manager.data())));
}

void QPhysicsAspectPrivate::unregisterBackendTypes()
{
    qDebug() << __PRETTY_FUNCTION__;

    Q_Q(QPhysicsAspect);
    q->unregisterBackendType<Qt3DCore::QTransform>();
    q->unregisterBackendType<Qt3DCore::QEntity>();
    q->unregisterBackendType<QRigidBody>();

}

void QPhysicsAspectPrivate::loadPhysicsEngines()
{
    qDebug() << __PRETTY_FUNCTION__;
    const QStringList keys = QPhysicsEngineFactory::keys();
    for (const QString &key : keys) {
        if(m_engines.contains(key)) continue;

        QPhysicsEngine *engine = QPhysicsEngineFactory::create(key, QStringList());
        if (engine == nullptr) continue;
        m_engines[key] = engine;
    }

}

QPhysicsAspect::QPhysicsAspect(QObject *parent)
    : QPhysicsAspect(*new QPhysicsAspectPrivate(QLatin1String("default")), parent)
{
    qDebug() << __PRETTY_FUNCTION__;
}

QPhysicsAspect::QPhysicsAspect(const QString &engine, QObject *parent)
    : QPhysicsAspect(*new QPhysicsAspectPrivate(engine), parent)
{
    qDebug() << __PRETTY_FUNCTION__;
}

QPhysicsAspect::QPhysicsAspect(QPhysicsAspectPrivate &dd, QObject *parent)
    : QAbstractAspect(dd, parent)
{
    qDebug() << __PRETTY_FUNCTION__;

    Q_D(QPhysicsAspect);
    setObjectName(QStringLiteral("Physics Aspect"));
}

QPhysicsAspect::~QPhysicsAspect()
{
    qDebug() << __PRETTY_FUNCTION__;
}

QStringList QPhysicsAspect::availableEngines()
{
    qDebug() << __PRETTY_FUNCTION__;

    return QPhysicsEngineFactory::keys();
}

QVector<Qt3DCore::QAspectJobPtr> QPhysicsAspect::jobsToExecute(qint64 time)
{
    //qDebug() << __PRETTY_FUNCTION__ << time;

    QVector<Qt3DCore::QAspectJobPtr> jobs;
    return jobs;
}

void QPhysicsAspect::onRegistered()
{
    qDebug() << __PRETTY_FUNCTION__;

    Q_D(QPhysicsAspect);
    d->registerBackendTypes();
    d->loadPhysicsEngines();

    if(d->m_engines.contains(d->m_engineType)){
        //get requested engine
        d->m_engine = d->m_engines[d->m_engineType];
    } else if (d->m_engines.contains(QLatin1String("ode"))){
        //fall back to default ODE engine
        d->m_engineType = QLatin1String("ode");
        d->m_engine = d->m_engines[d->m_engineType];
    } else if (!d->m_engines.isEmpty()) {
        //fall back to first available engine
        d->m_engineType = d->m_engines.firstKey();
        d->m_engine = d->m_engines[d->m_engineType];
    } else {
        //qWarning(tr("Unable to find any physics engine!"));
        d->m_engine = nullptr;
    }
}

void QPhysicsAspect::onUnregistered()
{
    qDebug() << __PRETTY_FUNCTION__;

    Q_D(QPhysicsAspect);

    d->m_engine = nullptr;
    qDeleteAll(d->m_engines);
    d->m_engines.clear();

    d->unregisterBackendTypes();

}

void QPhysicsAspect::onEngineStartup()
{
    qDebug() << __PRETTY_FUNCTION__;
}

void QPhysicsAspect::onEngineShutdown()
{
    qDebug() << __PRETTY_FUNCTION__;
}

}

QT_END_NAMESPACE

QT3D_REGISTER_NAMESPACED_ASPECT("physics", QT_PREPEND_NAMESPACE(Qt3DPhysics), QPhysicsAspect)
