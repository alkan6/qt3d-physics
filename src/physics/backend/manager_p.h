#ifndef QT3DPHYSICS_PHYSICS_MANAGER_P_H
#define QT3DPHYSICS_PHYSICS_MANAGER_P_H

#include <QtCore/qscopedpointer.h>
#include <QtCore/qvector.h>

#include <Qt3DCore/qnodeid.h>

#include <Qt3DPhysics/private/handle_types_p.h>
#include <Qt3DPhysics/private/managers_p.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Physics {

class Manager
{
public:
    Manager();
    ~Manager();

    RigidBodyManager * rigidBodyManager() const { return m_rigidBodyManager.data(); }
    EntityManager * entityManager() const { return m_entityManager.data(); }
    TransformManager * transformManager() const { return m_transformManager.data(); }

    void appendRigidBody(RigidBody *rigidBody);
    void removeRigidBody(Qt3DCore::QNodeId id);

private:
    QScopedPointer<RigidBodyManager> m_rigidBodyManager;
    QScopedPointer<EntityManager> m_entityManager;
    QScopedPointer<TransformManager> m_transformManager;

    QVector<HRigidBody> m_rigidBodyHandlers;
    QVector<Qt3DCore::QNodeId> m_rigidBodyComponentIds;

};

}
}

QT_END_NAMESPACE


#endif // MANAGER_P_H
