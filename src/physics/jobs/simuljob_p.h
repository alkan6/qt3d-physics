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
    SimulJob(Physics::Manager *manager);

    void setStep(float step) { m_step = step; }
    void setDeltaTime(float dt) { m_dt = dt; }

protected:
    void run() final;

private:
    Physics::Manager * m_manager;
    float m_dt;
    float m_step;
};

typedef QSharedPointer<SimulJob> SimulJobPtr;

}
}

QT_END_NAMESPACE

#endif
