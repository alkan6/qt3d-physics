#ifndef QT3DPHYSICS_PHYSICS_MANAGER_P_H
#define QT3DPHYSICS_PHYSICS_MANAGER_P_H

#include <QtCore/qscopedpointer.h>
#include <QtCore/qsharedpointer.h>
#include <QtCore/qvector.h>

#include <Qt3DCore/qnodeid.h>
#include <Qt3DCore/QAspectJob>
#include <Qt3DCore/private/qabstractframeadvanceservice_p.h>

#include <Qt3DPhysics/private/handle_types_p.h>
#include <Qt3DPhysics/private/managers_p.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

namespace Engine {
class QPhysicsEngine;
}

namespace Physics {


class Manager
{
public:
    Manager();
    ~Manager();

    RigidBodyManager * rigidBodyManager() const { return m_rigidBodyManager.data(); }
    EntityManager * entityManager() const { return m_entityManager.data(); }
    TransformManager * transformManager() const { return m_transformManager.data(); }

    void setEngine(QSharedPointer<Engine::QPhysicsEngine> engine) { m_engine = engine; }
    QSharedPointer<Engine::QPhysicsEngine> engine() { return m_engine; }
    QVector<Qt3DCore::QAspectJobPtr> engineJobs();

    void setGravity(const QVector3D &gravity);
    QVector3D gravity() const;

    void appendRigidBody(RigidBody *rigidBody);
    void removeRigidBody(Qt3DCore::QNodeId id);

private:
    QSharedPointer<Engine::QPhysicsEngine> m_engine;
    QVector3D m_gravity;

    QVector<Qt3DCore::QAspectJobPtr> m_engineJobs;

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
