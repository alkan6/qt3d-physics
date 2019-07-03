#include "qrigidbody.h"
#include "qrigidbody_p.h"

#include <Qt3DCore/qpropertyupdatedchange.h>
#include <Qt3DCore/qcomponentaddedchange.h>

#include <QDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {


QRigidBodyPrivate::QRigidBodyPrivate()
    : Qt3DCore::QComponentPrivate()
    , m_mass(0.0f)
{
    qDebug() << __PRETTY_FUNCTION__;
    m_shareable = false;
}

QRigidBodyPrivate::~QRigidBodyPrivate()
{
    qDebug() << __PRETTY_FUNCTION__;
}

QRigidBody::QRigidBody(Qt3DCore::QNode *parent)
    : QRigidBody(*new QRigidBodyPrivate, parent)
{
    qDebug() << __PRETTY_FUNCTION__;
}

QRigidBody::QRigidBody(QRigidBodyPrivate &dd, Qt3DCore::QNode *parent)
    : Qt3DCore::QComponent(dd, parent)
{
    qDebug() << __PRETTY_FUNCTION__;
}


QRigidBody::~QRigidBody()
{
    qDebug() << __PRETTY_FUNCTION__;
}

void QRigidBody::setMass(float mass)
{
    qDebug() << __PRETTY_FUNCTION__;
    Q_D(QRigidBody);
    if(mass != d->m_mass) {
        d->m_mass = mass;
        emit massChanged(mass);
    }
}

float QRigidBody::mass() const
{
    qDebug() << __PRETTY_FUNCTION__;
    Q_D(const QRigidBody);
    return d->m_mass;
}

Qt3DCore::QNodeCreatedChangeBasePtr QRigidBody::createNodeCreationChange() const
{
    qDebug() << __PRETTY_FUNCTION__;

    Q_D(const QRigidBody);
    QSharedPointer<Qt3DCore::QNodeCreatedChange<QRigidBodyData>> creationChange;
    creationChange= Qt3DCore::QNodeCreatedChangePtr<QRigidBodyData>::create(this);
    QRigidBodyData &data = creationChange->data;
    data.mass = d->m_mass;

    return Qt3DCore::QNodeCreatedChangeBasePtr(creationChange);

}

void QRigidBody::sceneChangeEvent(const Qt3DCore::QSceneChangePtr &change)
{
    qDebug() << __PRETTY_FUNCTION__ << change->type();

    Q_D(QRigidBody);
    if(change->type() == Qt3DCore::PropertyUpdated){
        Qt3DCore::QPropertyUpdatedChangePtr c =
                qSharedPointerCast<Qt3DCore::QPropertyUpdatedChange>(change);

        if(c->propertyName() == QByteArrayLiteral("mass")){
            d->m_mass = c->value().toFloat();
        }
    }
    if(change->type() == Qt3DCore::ComponentAdded){
        Qt3DCore::QComponentAddedChangePtr c =
                qSharedPointerCast<Qt3DCore::QComponentAddedChange>(change);
    }
    Qt3DCore::QComponent::sceneChangeEvent(change);
}

}

QT_END_NAMESPACE
