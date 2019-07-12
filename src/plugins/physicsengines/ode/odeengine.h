#ifndef QT3D_ENGINE_ODEENGINE_H
#define QT3D_ENGINE_ODEENGINE_H

#include <Qt3DPhysics/private/qphysicsengine_p.h>
#include <ode/ode.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Engine {

class OdeEngine : public QPhysicsEngine
{
    Q_OBJECT
public:
    OdeEngine();
    ~OdeEngine();

public:
    void init() override;
    void close() override;

    void startup() override;
    void shutdown() override;

    void setGravity(const QVector3D &gravity) override;
    void step(double dt) override;

private:
    bool m_running;
    dWorldID m_worldID;
};
}
}

QT_END_NAMESPACE

#endif
