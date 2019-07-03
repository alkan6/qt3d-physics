#ifndef QT3DPHYSICS_JOBS_STOPJOB_P_H
#define QT3DPHYSICS_JOBS_STOPJOB_P_H

#include <Qt3DCore/qaspectjob.h>
#include <QtCore/qsharedpointer.h>

QT_BEGIN_NAMESPACE
namespace Qt3DPhysics {
namespace Engine {
class QPhysicsEngine;
}

namespace Jobs {

class StopJob : public Qt3DCore::QAspectJob
{
public:
    StopJob(QSharedPointer<Engine::QPhysicsEngine> engine);

protected:
    void run() final;

private:
    QSharedPointer<Engine::QPhysicsEngine> m_engine;
};

typedef QSharedPointer<StopJob> StopJobPtr;

}
}

QT_END_NAMESPACE

#endif
