#ifndef QT3DPHYSICS_ENGINE_QPHYSICSENGINE_P_H
#define QT3DPHYSICS_ENGINE_QPHYSICSENGINE_P_H

#include <Qt3DPhysics/private/qt3dphysics_global_p.h>
#include <QtCore/qobject.h>

QT_BEGIN_NAMESPACE
namespace Qt3DPhysics {
namespace Engine {

class QT3DPHYSICS_PRIVATE_EXPORT QPhysicsEngine : public QObject
{
    Q_OBJECT
public:
    QPhysicsEngine();
    virtual ~QPhysicsEngine();

    virtual void init() = 0;
    virtual void close() = 0;

    virtual void startup() = 0;
    virtual void shutdown() = 0;
    virtual void setGravity(const QVector3D &gravity) = 0;
    virtual void step(double dt) = 0;

};

typedef QSharedPointer<QPhysicsEngine> QPhysicsEnginePtr;

}
}
QT_END_NAMESPACE

#endif // QPHYSICSPLUGIN_P_H
