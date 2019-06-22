#include "manager_p.h"
#include "managers_p.h"

#include <QDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Physics {

Manager::Manager()
    : m_rigidBodyManager(new RigidBodyManager)
    , m_entityManager(new EntityManager)
    , m_transformManager(new TransformManager)
{
    qDebug() << __PRETTY_FUNCTION__;
}

Manager::~Manager()
{

}

void Manager::appendRigidBody(RigidBody *rigidBody)
{
    qDebug() << __PRETTY_FUNCTION__;

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
