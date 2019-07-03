#include "startjob_p.h"

#include <Qt3DPhysics/private/qphysicsengine_p.h>

#include <QDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Jobs {

StartJob::StartJob(QSharedPointer<Engine::QPhysicsEngine> engine)
    : Qt3DCore::QAspectJob()
    , m_engine(engine)
{
    qDebug() << __PRETTY_FUNCTION__;
}

void StartJob::run()
{
    qDebug() << __PRETTY_FUNCTION__;

    m_engine->startup();
}

}
}

QT_END_NAMESPACE
