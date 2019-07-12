#include "simuljob_p.h"

#include <Qt3DPhysics/private/qphysicsengine_p.h>
#include <Qt3DPhysics/private/manager_p.h>

#include <QDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Jobs {

SimulJob::SimulJob(Physics::Manager *manager, qint64 step)
    : Qt3DCore::QAspectJob()
    , m_manager(manager)
    , m_step(step)
{
    //qDebug() << __PRETTY_FUNCTION__;
}

void SimulJob::run()
{

    QSharedPointer<Engine::QPhysicsEngine> e = m_manager->engine();
    if(e.isNull()) return;

    e->step(static_cast<double>(m_step)/1.0E9);
}

}
}

QT_END_NAMESPACE
