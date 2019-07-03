#include "qphysicsaspect.h"
#include "qphysicsaspect_p.h"

#include <Qt3DPhysics/private/manager_p.h>
#include <Qt3DPhysics/private/qphysicsenginefactory_p.h>
#include <Qt3DPhysics/private/qphysicsengine_p.h>
#include <Qt3DPhysics/private/simuljob_p.h>

#include <Qt3DPhysics/qrigidbody.h>
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>

#include <Qt3DPhysics/private/rigidbody_p.h>
#include <Qt3DPhysics/private/entity_p.h>
#include <Qt3DPhysics/private/transform_p.h>

#include <cmath>

#include <QDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

QPhysicsAspectPrivate::QPhysicsAspectPrivate(const QString &engine)
    : QAbstractAspectPrivate()
    , m_time(0)
    , m_simStep(1.0f/60.0f)
    , m_initialized(false)
    , m_manager(new Physics::Manager)
    , m_simulJob(new Jobs::SimulJob(m_manager.data()))
    , m_engineType(engine)


{
    qDebug() << __PRETTY_FUNCTION__;   
    m_simulJob->setStep(m_simStep);
    loadPhysicsEngines();
}


QPhysicsAspectPrivate::~QPhysicsAspectPrivate()
{
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

    Engine::QPhysicsEngine * e;
    const QStringList keys = Engine::QPhysicsEngineFactory::keys();

    for (const QString &key : keys) {
        if(m_engines.contains(key)) continue;
        e = Engine::QPhysicsEngineFactory::create(key, QStringList());
        if(e == nullptr) continue;
        m_engines[key].reset(e);
    }
}

void QPhysicsAspectPrivate::selectPysicsEngine()
{
    //selects physics engine plugin
    Engine::QPhysicsEnginePtr e;
    if(m_engines.contains(m_engineType)){
        //get requested engine
        e = m_engines[m_engineType];
    } else if (m_engines.contains(QLatin1String("ode"))){
        //fall back to default ODE engine
        m_engineType = QLatin1String("ode");
        e = m_engines[m_engineType];
    } else if (!m_engines.isEmpty()) {
        //fall back to first available engine
        m_engineType = m_engines.firstKey();
        e = m_engines[m_engineType];
    } else {
        //qWarning(tr("Unable to find any physics engine!"));
        e.clear();
        m_engineType.clear();
    }

    m_manager->setEngine(e);
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
    setObjectName(QStringLiteral("Physics Aspect"));
}

QPhysicsAspect::~QPhysicsAspect()
{
    qDebug() << __PRETTY_FUNCTION__;
}

QStringList QPhysicsAspect::availableEngines()
{
    qDebug() << __PRETTY_FUNCTION__;

    return Engine::QPhysicsEngineFactory::keys();
}

void QPhysicsAspect::setGravity(const QVector3D &gravity)
{
    Q_D(QPhysicsAspect);
    d->m_manager->setGravity(gravity);

}

QVector<Qt3DCore::QAspectJobPtr> QPhysicsAspect::jobsToExecute(qint64 time)
{
    //qDebug() << __PRETTY_FUNCTION__;

    QVector<Qt3DCore::QAspectJobPtr> jobs;

    Q_D(QPhysicsAspect);

    //calculate delta time to run the simulation
    if(d->m_time==0) d->m_time = time;
    const qint64 dTime = time - d->m_time;
    float dt = static_cast<float>(dTime) / 1.0e9f;
    d->m_time = time;

    if(dt >= d->m_simStep){
        //run simulation to the closest time point
        //this is to keep simulation step constant, otherwise engines sacmalar
        d->m_simulJob->setDeltaTime(dt);
        jobs << d->m_simulJob;
        d->m_time -= dTime % qint64(d->m_simStep*1.0e9f);
    }

    jobs << d->m_manager->engineJobs();
    return jobs;
}



void QPhysicsAspect::onRegistered()
{
    qDebug() << __PRETTY_FUNCTION__;

    Q_D(QPhysicsAspect);
    d->registerBackendTypes();
    d->selectPysicsEngine();

    d->m_manager->engine()->init();
}

void QPhysicsAspect::onUnregistered()
{
    qDebug() << __PRETTY_FUNCTION__;

    Q_D(QPhysicsAspect);

    d->unregisterBackendTypes();
    d->m_manager->engine()->close();
}

void QPhysicsAspect::onEngineStartup()
{
    qDebug() << __PRETTY_FUNCTION__;
    Q_D(QPhysicsAspect);
    d->m_manager->engine()->startup();
}

void QPhysicsAspect::onEngineShutdown()
{
    qDebug() << __PRETTY_FUNCTION__;
    Q_D(QPhysicsAspect);
    d->m_manager->engine()->shutdown();
}

}

QT_END_NAMESPACE

QT3D_REGISTER_NAMESPACED_ASPECT("physics", QT_PREPEND_NAMESPACE(Qt3DPhysics), QPhysicsAspect)
