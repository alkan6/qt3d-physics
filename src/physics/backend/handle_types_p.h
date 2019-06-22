#ifndef QT3DPHYSICS_PHYSICS_HANDLE_TYPES_P_H
#define QT3DPHYSICS_PHYSICS_HANDLE_TYPES_P_H

#include <Qt3DCore/private/qhandle_p.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Physics {

class RigidBody;
class Entity;
class Transform;

typedef Qt3DCore::QHandle<RigidBody> HRigidBody;
typedef Qt3DCore::QHandle<Entity> HEntity;
typedef Qt3DCore::QHandle<Transform> HTransform;

}
}

QT_END_NAMESPACE

#endif // HANDLE_TYPES_P_H
