#include "rigidbody_p.h"

#include <Qt3DPhysics/private/manager_p.h>

#include <Qt3DPhysics/private/qrigidbody_p.h>
#include <Qt3DCore/qpropertyupdatedchange.h>

#include <QDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Physics {

RigidBody::RigidBody()
    : Qt3DCore::QBackendNode()
    , m_manager(nullptr)
    , m_mass(0.0f)
{
    //qDebug() << __PRETTY_FUNCTION__;
}


void RigidBody::initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change)
{
    qDebug() << __PRETTY_FUNCTION__;
    const auto typedChange = qSharedPointerCast<Qt3DCore::QNodeCreatedChange<QRigidBodyData>>(change);
    const auto &data = typedChange->data;
    m_mass = data.mass;

    m_manager->appendRigidBody(this);
}



void RigidBody::sceneChangeEvent(const Qt3DCore::QSceneChangePtr &e)
{
    qDebug() << __PRETTY_FUNCTION__ << e->type();

    if(e->type() == Qt3DCore::PropertyUpdated){
        Qt3DCore::QPropertyUpdatedChangePtr change =
                qSharedPointerCast<Qt3DCore::QPropertyUpdatedChange>(e);
        if(change->propertyName() == QByteArrayLiteral("mass")){
            m_mass = change->value().toFloat();
        }
    }

    Qt3DCore::QBackendNode::sceneChangeEvent(e);
}


RigidBodyFunctor::RigidBodyFunctor(Manager *manager)
    : m_manager(manager)
{
    qDebug() << __PRETTY_FUNCTION__;
}

Qt3DCore::QBackendNode *RigidBodyFunctor::create(
        const Qt3DCore::QNodeCreatedChangeBasePtr &change) const
{
    qDebug() << __PRETTY_FUNCTION__;

    RigidBody *handler = m_manager->rigidBodyManager()->getOrCreateResource(change->subjectId());
    handler->setManager(m_manager);

    return handler;
}

Qt3DCore::QBackendNode *RigidBodyFunctor::get(Qt3DCore::QNodeId id) const
{
    qDebug() << __PRETTY_FUNCTION__;

    return m_manager->rigidBodyManager()->lookupResource(id);
}

void RigidBodyFunctor::destroy(Qt3DCore::QNodeId id) const
{
    qDebug() << __PRETTY_FUNCTION__;

    m_manager->removeRigidBody(id);
    m_manager->rigidBodyManager()->releaseResource(id);

}

}
}

QT_END_NAMESPACE
