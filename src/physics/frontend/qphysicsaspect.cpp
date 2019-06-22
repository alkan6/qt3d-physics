#include "qphysicsaspect.h"
#include "qphysicsaspect_p.h"

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

QPhysicsAspectPrivate::QPhysicsAspectPrivate()
    : QAbstractAspectPrivate()
    , m_time(0)
    , m_initialized(false)
    , m_manager(new Physics::Manager)
{
    qDebug() << __PRETTY_FUNCTION__;
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

QPhysicsAspect::QPhysicsAspect(QObject *parent)
    : QPhysicsAspect(*new QPhysicsAspectPrivate, parent)
{
    qDebug() << __PRETTY_FUNCTION__;
}

QPhysicsAspect::QPhysicsAspect(QPhysicsAspectPrivate &dd, QObject *parent)
    : QAbstractAspect(dd, parent)
{
    qDebug() << __PRETTY_FUNCTION__;

    Q_D(QPhysicsAspect);  
    setObjectName(QStringLiteral("Physics Aspect"));
    d->registerBackendTypes();
}

QPhysicsAspect::~QPhysicsAspect()
{
    qDebug() << __PRETTY_FUNCTION__;
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
}

void QPhysicsAspect::onUnregistered()
{
    qDebug() << __PRETTY_FUNCTION__;
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
