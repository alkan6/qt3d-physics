#ifndef QT3D_ODEENGINE_H
#define QT3D_ODEENGINE_H

#include <Qt3DPhysics/private/qphysicsengine_p.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

class OdeEngine : public QPhysicsEngine
{
    Q_OBJECT
public:
    OdeEngine();
    ~OdeEngine();
};

}


QT_END_NAMESPACE

#endif
