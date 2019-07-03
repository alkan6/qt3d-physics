#include "simuljob_p.h"

#include <Qt3DPhysics/private/qphysicsengine_p.h>
#include <Qt3DPhysics/private/manager_p.h>

#include <QDebug>
#include <QThread>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Jobs {

SimulJob::SimulJob(Physics::Manager *manager)
    : Qt3DCore::QAspectJob()
    , m_manager(manager)
    , m_dt(1.0f/60.0f)
    , m_step(1.0f/60.0f)
{
    //qDebug() << __PRETTY_FUNCTION__;
}

void SimulJob::run()
{
    //qDebug() << __PRETTY_FUNCTION__ << QThread::currentThreadId();
    QSharedPointer<Engine::QPhysicsEngine> e = m_manager->engine();
    if(e.isNull()) return;

    float t = 0.0f;
    while(t<m_dt){
        e->step(m_step);
        t+= m_step;
    }
}

}
}

QT_END_NAMESPACE
