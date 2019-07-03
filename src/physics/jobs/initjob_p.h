#ifndef QT3DPHYSICS_JOBS_INITJOB_P_H
#define QT3DPHYSICS_JOBS_INITJOB_P_H

#include <Qt3DCore/qaspectjob.h>
#include <QtCore/qsharedpointer.h>

QT_BEGIN_NAMESPACE
namespace Qt3DPhysics {
namespace Engine {
class QPhysicsEngine;
}

namespace Jobs {

class InitJob : public Qt3DCore::QAspectJob
{
public:
    InitJob(QSharedPointer<Engine::QPhysicsEngine> engine);

protected:
    void run() final;

private:
    QSharedPointer<Engine::QPhysicsEngine> m_engine;
};

typedef QSharedPointer<InitJob> InitJobPtr;

}
}

QT_END_NAMESPACE

#endif
