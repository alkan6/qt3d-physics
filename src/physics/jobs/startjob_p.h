#ifndef QT3DPHYSICS_JOBS_STARTJOB_P_H
#define QT3DPHYSICS_JOBS_STARTJOB_P_H

#include <Qt3DCore/qaspectjob.h>
#include <QtCore/qsharedpointer.h>

QT_BEGIN_NAMESPACE
namespace Qt3DPhysics {
namespace Engine {
class QPhysicsEngine;
}

namespace Jobs {

class StartJob : public Qt3DCore::QAspectJob
{
public:
    StartJob(QSharedPointer<Engine::QPhysicsEngine> engine);

protected:
    void run() final;

private:
    QSharedPointer<Engine::QPhysicsEngine> m_engine;
};

typedef QSharedPointer<StartJob> StartJobPtr;

}
}

QT_END_NAMESPACE

#endif
