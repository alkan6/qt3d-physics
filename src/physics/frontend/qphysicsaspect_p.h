#ifndef QT3DPHYSICS_QPHYSICSASPECT_P_H
#define QT3DPHYSICS_QPHYSICSASPECT_P_H

#include <Qt3DCore/private/qabstractaspect_p.h>
#include <Qt3DPhysics/qphysicsaspect.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

namespace Physics {
class Manager;
}

class QPhysicsAspectPrivate : public Qt3DCore::QAbstractAspectPrivate
{

public:
    QPhysicsAspectPrivate();


    void registerBackendTypes();

    qint64 m_time;
    bool m_initialized;
    QScopedPointer<Physics::Manager> m_manager;

    Q_DECLARE_PUBLIC(QPhysicsAspect)
};

}

QT_END_NAMESPACE

#endif
