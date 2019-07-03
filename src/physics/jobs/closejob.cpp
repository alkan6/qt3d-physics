#include "closejob_p.h"

#include <Qt3DPhysics/private/qphysicsengine_p.h>

#include <QDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Jobs {

CloseJob::CloseJob(QSharedPointer<Engine::QPhysicsEngine> engine)
    : Qt3DCore::QAspectJob()
    , m_engine(engine)
{
    qDebug() << __PRETTY_FUNCTION__;
}

void CloseJob::run()
{
    qDebug() << __PRETTY_FUNCTION__;

    m_engine->close();
}

}
}

QT_END_NAMESPACE
