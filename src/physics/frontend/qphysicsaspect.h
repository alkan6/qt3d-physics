#ifndef QT3DPHYSICS_QPHYSICSASPECT_H
#define QT3DPHYSICS_QPHYSICSASPECT_H

#include <Qt3DPhysics/qt3dphysics_global.h>
#include <Qt3DCore/qabstractaspect.h>
#include <QtCore/qvector.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

class QPhysicsAspectPrivate;

class QT3DPHYSICSSHARED_EXPORT QPhysicsAspect : public Qt3DCore::QAbstractAspect
{
    Q_OBJECT
public:
    explicit QPhysicsAspect(QObject *parent = nullptr);
    ~QPhysicsAspect() override;

protected:
    explicit QPhysicsAspect(QPhysicsAspectPrivate &dd, QObject *parent);

private:
    QVector<Qt3DCore::QAspectJobPtr> jobsToExecute(qint64 time) override;
    void onRegistered() override;
    void onUnregistered() override;
    void onEngineStartup() override;
    void onEngineShutdown() override;

private:
    Q_DECLARE_PRIVATE(QPhysicsAspect)

};

}

QT_END_NAMESPACE

#endif
