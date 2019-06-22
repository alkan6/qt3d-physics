#ifndef QT3DPHYSICS_PHYSICS_ENTITY_P_H
#define QT3DPHYSICS_PHYSICS_ENTITY_P_H

#include <Qt3DCore/qbackendnode.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Physics {

class Manager;

class Entity : public Qt3DCore::QBackendNode
{
public:
    Entity();

    void setManager(Manager *manager) { m_manager = manager; }
    Manager *manager() const { return m_manager; }

protected:
    void sceneChangeEvent(const Qt3DCore::QSceneChangePtr &e) override;

private:
    void initializeFromPeer(const Qt3DCore::QNodeCreatedChangeBasePtr &change) final;

private:
    Manager * m_manager;
};


class EntityFunctor : public Qt3DCore::QBackendNodeMapper
{
public:
    explicit EntityFunctor(Manager *manager);

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
