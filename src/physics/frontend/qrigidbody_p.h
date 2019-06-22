#ifndef QT3DPHYSICS_QRIGIDBODY_P_H
#define QT3DPHYSICS_QRIGIDBODY_P_H

#include <Qt3DPhysics/private/qt3dphysics_global_p.h>
#include <Qt3DCore/private/qcomponent_p.h>
#include <Qt3DPhysics/qrigidbody.h>

QT_BEGIN_NAMESPACE

namespace Qt3DCore {
class QTransform;
}

namespace Qt3DPhysics {

class QRigidBody;

class QT3DPHYSICS_PRIVATE_EXPORT QRigidBodyPrivate : public Qt3DCore::QComponentPrivate
{

public:
    QRigidBodyPrivate();
    ~QRigidBodyPrivate();

    float m_mass;

    Q_DECLARE_PUBLIC(QRigidBody)
};

struct QRigidBodyData
{
    float mass;
};

}

QT_END_NAMESPACE

#endif // QRIGIDBODY_P_H
