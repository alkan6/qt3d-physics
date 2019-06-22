#ifndef QT3DPHYSICS_PHYSICS_TRANSFORM_P_H
#define QT3DPHYSICS_PHYSICS_TRANSFORM_P_H

#include <Qt3DCore/qbackendnode.h>

#include <QtGui/QVector3D>
#include <QtGui/qquaternion.h>
#include <QtGui/qmatrix4x4.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Physics {

class Manager;

class Transform : public Qt3DCore::QBackendNode
{
public:
    Transform();

    void setManager(Manager *manager) { m_manager = manager; }
    Manager *manager() const { return m_manager; }

protected:
    void sceneChangeEvent(const Qt3DCore::QSceneChangePtr &e) override;

private:
    void initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change) final;

private:
    Manager * m_manager;

    QMatrix4x4 m_transformMatrix;
    QQuaternion m_rotation;
    QVector3D m_scale;
    QVector3D m_translation;
};


class TransformFunctor : public Qt3DCore::QBackendNodeMapper
{
public:
    explicit TransformFunctor(Manager *manager);

    Qt3DCore::QBackendNode *create(
            const Qt3DCore::QNodeCreatedChangeBasePtr &change) const override;
    Qt3DCore::QBackendNode *get(Qt3DCore::QNodeId id) const override;
    void destroy(Qt3DCore::QNodeId id) const override;

private:
    Manager *m_manager;

};

}
}

QT_END_NAMESPACE

#endif
