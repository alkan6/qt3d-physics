#include "manager_p.h"
#include "managers_p.h"

#include <Qt3DPhysics/private/qphysicsenginefactory_p.h>
#include <Qt3DPhysics/private/qphysicsengine_p.h>

#include <Qt3DPhysics/private/initjob_p.h>
#include <Qt3DPhysics/private/closejob_p.h>
#include <Qt3DPhysics/private/startjob_p.h>
#include <Qt3DPhysics/private/stopjob_p.h>
#include <Qt3DPhysics/private/gravityjob_p.h>
#include <Qt3DPhysics/private/simuljob_p.h>

#include <QDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Physics {

Manager::Manager()
    : m_engine(nullptr)
    , m_gravity(0,0,0)
    , m_rigidBodyManager(new RigidBodyManager)
    , m_entityManager(new EntityManager)
    , m_transformManager(new TransformManager)
{
    qDebug() << __PRETTY_FUNCTION__;
}

Manager::~Manager()
{
    qDebug() << __PRETTY_FUNCTION__;
}

QVector<Qt3DCore::QAspectJobPtr> Manager::engineJobs()
{
    //qDebug() << __PRETTY_FUNCTION__;

    QVector<Qt3DCore::QAspectJobPtr> jobs;
    jobs << m_engineJobs;
    m_engineJobs.clear();

    return jobs;
}

void Manager::setGravity(const QVector3D &gravity)
{
    qDebug() << __PRETTY_FUNCTION__;
    m_gravity = gravity;

    m_engineJobs << Jobs::GravityJobPtr::create(this, m_gravity);
}

QVector3D Manager::gravity() const
{
    return m_gravity;
}




void Manager::appendRigidBody(RigidBody *rigidBody)
{
    qDebug() << "####################" << __PRETTY_FUNCTION__;

    HRigidBody handle = m_rigidBodyManager->lookupHandle(rigidBody->peerId());
    m_rigidBodyHandlers.append(handle);
    m_rigidBodyComponentIds.append(rigidBody->peerId());


}

void Manager::removeRigidBody(Qt3DCore::QNodeId id)
{
    qDebug() << __PRETTY_FUNCTION__;

    HRigidBody handle = m_rigidBodyManager->lookupHandle(id);
    m_rigidBodyComponentIds.removeAll(id);
    m_rigidBodyHandlers.removeAll(handle);
}

}
}

QT_END_NAMESPACE
