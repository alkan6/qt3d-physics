#ifndef QT3DPHYSICS_JOBS_GRAVITYJOB_P_H
#define QT3DPHYSICS_JOBS_GRAVITYJOB_P_H

#include <Qt3DCore/qaspectjob.h>
#include <QtCore/qsharedpointer.h>
#include <QtGui/qvector3d.h>

QT_BEGIN_NAMESPACE
namespace Qt3DPhysics {
namespace Physics {
class Manager;
}

namespace Jobs {

class GravityJob : public Qt3DCore::QAspectJob
{
public:
    GravityJob(Physics::Manager * manager, const QVector3D &gravity);

protected:
    void run() final;

private:
    Physics::Manager * m_manager;
    QVector3D m_gravity;
};

typedef QSharedPointer<GravityJob> GravityJobPtr;

}
}

QT_END_NAMESPACE

#endif
