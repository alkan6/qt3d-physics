#ifndef QT3DPHYSICS_PHYSICS_MANAGERS_P_H
#define QT3DPHYSICS_PHYSICS_MANAGERS_P_H

#include <Qt3DPhysics/private/rigidbody_p.h>
#include <Qt3DPhysics/private/entity_p.h>
#include <Qt3DPhysics/private/transform_p.h>

#include <Qt3DCore/private/qresourcemanager_p.h>
#include <Qt3DCore/qnodeid.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Physics {

class RigidBodyManager
        : public Qt3DCore::QResourceManager< RigidBody, Qt3DCore::QNodeId >
{public:RigidBodyManager() {}};

class EntityManager
        : public Qt3DCore::QResourceManager< Entity, Qt3DCore::QNodeId >
{public:EntityManager() {}};

class TransformManager
        : public Qt3DCore::QResourceManager< Transform, Qt3DCore::QNodeId >
{public:TransformManager() {}};

}
}

#endif
