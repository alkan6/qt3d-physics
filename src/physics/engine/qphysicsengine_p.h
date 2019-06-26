#ifndef QT3DPHYSICS_QPHYSICSENGINE_P_H
#define QT3DPHYSICS_QPHYSICSENGINE_P_H

#include <QtCore/qobject.h>

QT_BEGIN_NAMESPACE
namespace Qt3Dphysics {

class QPhysicsEngine : public QObject
{
    Q_OBJECT
public:
    explicit QPhysicsEngine(QObject *parent = nullptr);
    ~QPhysicsEngine();

};


}


QT_END_NAMESPACE

#endif // QPHYSICSPLUGIN_P_H
