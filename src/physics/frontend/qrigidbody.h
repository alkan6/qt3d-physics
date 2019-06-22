#ifndef QT3DPHYSICS_QRIGIDBODY_H
#define QT3DPHYSICS_QRIGIDBODY_H

#include <Qt3DPhysics/qt3dphysics_global.h>
#include <Qt3DCore/qcomponent.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

class QRigidBodyPrivate;

class QT3DPHYSICSSHARED_EXPORT QRigidBody : public Qt3DCore::QComponent
{
    Q_OBJECT
    Q_PROPERTY(float mass READ mass WRITE setMass NOTIFY massChanged)

public:
    explicit QRigidBody(QNode *parent = nullptr);
    ~QRigidBody();

    float mass() const;

public Q_SLOTS:
    void setMass(float mass);

Q_SIGNALS:
    void massChanged(float mass);

protected:
    explicit QRigidBody(QRigidBodyPrivate &dd, QNode *parent = nullptr);
    void sceneChangeEvent(const Qt3DCore::QSceneChangePtr &change) override;

private:
    Q_DECLARE_PRIVATE(QRigidBody)
    Qt3DCore::QNodeCreatedChangeBasePtr createNodeCreationChange() const override;

};

}

QT_END_NAMESPACE

#endif // QRIGIDBODY_H
