#ifndef QT3DPHYSICS_QPHYSICSENGINE_P_H
#define QT3DPHYSICS_QPHYSICSENGINE_P_H

#include <Qt3DPhysics/private/qt3dphysics_global_p.h>
#include <QtCore/qobject.h>

QT_BEGIN_NAMESPACE
namespace Qt3DPhysics {

class QT3DPHYSICS_PRIVATE_EXPORT QPhysicsEngine : public QObject
{
    Q_OBJECT
public:
    QPhysicsEngine();
    virtual ~QPhysicsEngine();

};

}
QT_END_NAMESPACE

#endif // QPHYSICSPLUGIN_P_H
