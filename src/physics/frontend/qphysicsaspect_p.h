#ifndef QT3DPHYSICS_QPHYSICSASPECT_P_H
#define QT3DPHYSICS_QPHYSICSASPECT_P_H

#include <Qt3DCore/private/qabstractaspect_p.h>
#include <Qt3DPhysics/qphysicsaspect.h>

#include <QtCore/qmap.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

class QPhysicsEngine;

namespace Physics {
class Manager;
}

class QPhysicsAspectPrivate : public Qt3DCore::QAbstractAspectPrivate
{

public:
    QPhysicsAspectPrivate(const QString &engine);
    ~QPhysicsAspectPrivate();

    void registerBackendTypes();
    void unregisterBackendTypes();
    void loadPhysicsEngines();

    qint64 m_time;
    bool m_initialized;
    QScopedPointer<Physics::Manager> m_manager;

    QString m_engineType;
    QMap<QString, QPhysicsEngine*> m_engines;
    QPhysicsEngine * m_engine;

    Q_DECLARE_PUBLIC(QPhysicsAspect)
};

}

QT_END_NAMESPACE

#endif
