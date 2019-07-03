#include "stopjob_p.h"

#include <Qt3DPhysics/private/qphysicsengine_p.h>

#include <QDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Jobs {

StopJob::StopJob(QSharedPointer<Engine::QPhysicsEngine> engine)
    : Qt3DCore::QAspectJob()
    , m_engine(engine)
{
    qDebug() << __PRETTY_FUNCTION__;
}

void StopJob::run()
{
    qDebug() << __PRETTY_FUNCTION__;

    m_engine->shutdown();
}

}
}

QT_END_NAMESPACE
