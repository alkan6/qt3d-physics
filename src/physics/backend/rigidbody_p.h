#ifndef QT3DPHYSICS_PHYSICS_RIGIDBODY_P_H
#define QT3DPHYSICS_PHYSICS_RIGIDBODY_P_H

#include <Qt3DCore/qbackendnode.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Physics {

class Manager;

class RigidBody : public Qt3DCore::QBackendNode
{
public:
    RigidBody();

    void setManager(Manager *manager) { m_manager = manager; }
    Manager *manager() const { return m_manager; }

protected:
    void sceneChangeEvent(const Qt3DCore::QSceneChangePtr &e) override;

private:
    void initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change) final;

private:
    Manager * m_manager;
    float m_mass;
};


class RigidBodyFunctor : public Qt3DCore::QBackendNodeMapper
{
public:
    explicit RigidBodyFunctor(Manager *manager);

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

#endif // BODYHANDLER_P_H
