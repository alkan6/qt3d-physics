#ifndef QT3DPHYSICS_JOBS_SIMULJOB_P_H
#define QT3DPHYSICS_JOBS_SIMULJOB_P_H

#include <Qt3DCore/qaspectjob.h>
#include <QtCore/qsharedpointer.h>

QT_BEGIN_NAMESPACE
namespace Qt3DPhysics {
namespace Physics {
class Manager;
}

namespace Jobs {

class SimulJob : public Qt3DCore::QAspectJob
{
public:
    SimulJob(Physics::Manager *manager, qint64 step);

    void setStep(qint64 step) { m_step = step; }
    qint64 step() const { return m_step; }

protected:
    void run() final;

private:
    Physics::Manager * m_manager;
    qint64 m_step;
};

typedef QSharedPointer<SimulJob> SimulJobPtr;

}
}

QT_END_NAMESPACE

#endif
