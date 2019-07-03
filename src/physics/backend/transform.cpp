#include "transform_p.h"

#include <Qt3DCore/qtransform.h>
#include <Qt3DCore/private/qtransform_p.h>

#include <Qt3DPhysics/private/manager_p.h>

#include <Qt3DCore/qpropertyupdatedchange.h>

#include <QDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Physics {

Transform::Transform()
    : Qt3DCore::QBackendNode()
    , m_manager(nullptr)
    , m_transformMatrix()
    , m_rotation()
    , m_scale(1.0f, 1.0f, 1.0f)
    , m_translation()
{
    //qDebug() << __PRETTY_FUNCTION__;
}


void Transform::initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change)
{
    //qDebug() << __PRETTY_FUNCTION__;
    const auto typedChange = qSharedPointerCast<Qt3DCore::QNodeCreatedChange<Qt3DCore::QTransformData>>(change);
    const auto &data = typedChange->data;
    m_rotation = data.rotation;
    m_scale = data.scale;
    m_translation = data.translation;
    m_transformMatrix.setToIdentity();
    m_transformMatrix.translate(m_translation);
    m_transformMatrix.rotate(m_rotation);
    m_transformMatrix.scale(m_scale);
}



void Transform::sceneChangeEvent(const Qt3DCore::QSceneChangePtr &e)
{
    //qDebug() << __PRETTY_FUNCTION__ << e->type();

    if(e->type() == Qt3DCore::PropertyUpdated){
        Qt3DCore::QPropertyUpdatedChangePtr change =
                qSharedPointerCast<Qt3DCore::QPropertyUpdatedChange>(e);
    }

    Qt3DCore::QBackendNode::sceneChangeEvent(e);
}


TransformFunctor::TransformFunctor(Manager *manager)
    : m_manager(manager)
{
    //qDebug() << __PRETTY_FUNCTION__;
}

Qt3DCore::QBackendNode *TransformFunctor::create(
        const Qt3DCore::QNodeCreatedChangeBasePtr &change) const
{
    //qDebug() << __PRETTY_FUNCTION__;

    Transform *handler = m_manager->transformManager()->getOrCreateResource(change->subjectId());
    handler->setManager(m_manager);

    return handler;
}

Qt3DCore::QBackendNode *TransformFunctor::get(Qt3DCore::QNodeId id) const
{
    //qDebug() << __PRETTY_FUNCTION__;

    return m_manager->transformManager()->lookupResource(id);
}

void TransformFunctor::destroy(Qt3DCore::QNodeId id) const
{
    //qDebug() << __PRETTY_FUNCTION__;

    //m_manager->removeEntityBody(id);
    m_manager->transformManager()->releaseResource(id);

}

}
}

QT_END_NAMESPACE
