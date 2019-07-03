#include "entity_p.h"

#include <Qt3DPhysics/private/manager_p.h>

#include <Qt3DCore/private/qentity_p.h>
#include <Qt3DCore/qpropertyupdatedchange.h>

#include <QDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Physics {

Entity::Entity()
    : Qt3DCore::QBackendNode()
    , m_manager(nullptr)
{
    //qDebug() << __PRETTY_FUNCTION__;
}


void Entity::initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change)
{
    //qDebug() << __PRETTY_FUNCTION__;
    const auto typedChange = qSharedPointerCast<Qt3DCore::QNodeCreatedChange<Qt3DCore::QEntityData>>(change);
    const auto &data = typedChange->data;

}



void Entity::sceneChangeEvent(const Qt3DCore::QSceneChangePtr &e)
{
    //qDebug() << __PRETTY_FUNCTION__ << e->type();

    if(e->type() == Qt3DCore::PropertyUpdated){
        Qt3DCore::QPropertyUpdatedChangePtr change =
                qSharedPointerCast<Qt3DCore::QPropertyUpdatedChange>(e);
    }

    Qt3DCore::QBackendNode::sceneChangeEvent(e);
}


EntityFunctor::EntityFunctor(Manager *manager)
    : m_manager(manager)
{
    //qDebug() << __PRETTY_FUNCTION__;
}

Qt3DCore::QBackendNode *EntityFunctor::create(
        const Qt3DCore::QNodeCreatedChangeBasePtr &change) const
{
    //qDebug() << __PRETTY_FUNCTION__;

    Entity *handler = m_manager->entityManager()->getOrCreateResource(change->subjectId());
    handler->setManager(m_manager);

    return handler;
}

Qt3DCore::QBackendNode *EntityFunctor::get(Qt3DCore::QNodeId id) const
{
    //qDebug() << __PRETTY_FUNCTION__;

    return m_manager->entityManager()->lookupResource(id);
}

void EntityFunctor::destroy(Qt3DCore::QNodeId id) const
{
    //qDebug() << __PRETTY_FUNCTION__;

    //m_manager->removeEntityBody(id);
    m_manager->entityManager()->releaseResource(id);

}

}
}

QT_END_NAMESPACE
