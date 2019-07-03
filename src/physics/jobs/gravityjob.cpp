#include "gravityjob_p.h"

#include <Qt3DPhysics/private/qphysicsengine_p.h>
#include <Qt3DPhysics/private/manager_p.h>

#include <QDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Jobs {

GravityJob::GravityJob(Physics::Manager *manager, const QVector3D &gravity)
    : Qt3DCore::QAspectJob()
    , m_manager(manager)
    , m_gravity(gravity)
{
    qDebug() << __PRETTY_FUNCTION__;
}

void GravityJob::run()
{
    qDebug() << __PRETTY_FUNCTION__;
    QSharedPointer<Engine::QPhysicsEngine> e = m_manager->engine();
    if(e.isNull()) return;
    e->setGravity(m_gravity);
}

}
}

QT_END_NAMESPACE
