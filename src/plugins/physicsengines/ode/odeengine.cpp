#include "odeengine.h"

#include <QVector3D>
#include <QMutex>
#include <QMutexLocker>
#include <QThread>

#include <QDebug>


QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Engine {

static QMutex lock;

OdeEngine::OdeEngine()
    : QPhysicsEngine()
    , m_running(false)
    , m_worldID(nullptr)
{
    qDebug() << __PRETTY_FUNCTION__ << QThread::currentThreadId();
}

OdeEngine::~OdeEngine()
{
    qDebug() << __PRETTY_FUNCTION__<< QThread::currentThreadId();
}


void OdeEngine::init()
{
    qDebug() << __PRETTY_FUNCTION__<< QThread::currentThreadId();

    dInitODE();
    m_worldID = dWorldCreate();
    m_running = true;
}

void OdeEngine::close()
{
    qDebug() << __PRETTY_FUNCTION__<< QThread::currentThreadId();

    dWorldDestroy(m_worldID);
    dCloseODE();
    m_running = false;
}

void OdeEngine::startup()
{
    qDebug() << __PRETTY_FUNCTION__ << QThread::currentThreadId();
    if(m_worldID == nullptr) init();
    m_running = true;
}

void OdeEngine::shutdown()
{
    qDebug() << __PRETTY_FUNCTION__ << QThread::currentThreadId();
    m_running = false;
}

void OdeEngine::setGravity(const QVector3D &gravity)
{
    QMutexLocker locker(&lock);

    qDebug() << __PRETTY_FUNCTION__;
    if(m_worldID == nullptr){
        qWarning() << tr("Engine was not initialized!");
        return;
    }

    dWorldSetGravity(m_worldID, gravity.x(), gravity.y(), gravity.z());
}

void OdeEngine::step(double dt)
{
    QMutexLocker locker(&lock);

    if(!m_running) return;
    if(m_worldID == nullptr){
        qWarning() << tr("Engine was not initialized!");
        return;
    }

    dWorldStep(m_worldID, dt);
}

}
}

QT_END_NAMESPACE
