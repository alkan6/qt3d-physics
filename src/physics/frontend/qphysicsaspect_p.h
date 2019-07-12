#ifndef QT3DPHYSICS_QPHYSICSASPECT_P_H
#define QT3DPHYSICS_QPHYSICSASPECT_P_H

#include <Qt3DCore/private/qabstractaspect_p.h>
#include <Qt3DPhysics/qphysicsaspect.h>

#include <QtCore/qmap.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

namespace Physics {
class Manager;
}

namespace Engine {
class QPhysicsEngine;
}

namespace Jobs {
class SimulJob;
}


class QPhysicsAspectPrivate : public Qt3DCore::QAbstractAspectPrivate
{

public:
    QPhysicsAspectPrivate(const QString &engine);
    ~QPhysicsAspectPrivate();

    void registerBackendTypes();
    void unregisterBackendTypes();
    void loadPhysicsEngines();
    void selectPysicsEngine();

    qint64 m_time;
    bool m_initialized;
    QScopedPointer<Physics::Manager> m_manager;
    QMap<QString, QSharedPointer<Engine::QPhysicsEngine>> m_engines;
    QSharedPointer<Jobs::SimulJob> m_simulJob;

    QString m_engineType;
    Q_DECLARE_PUBLIC(QPhysicsAspect)
};

}

QT_END_NAMESPACE

#endif
