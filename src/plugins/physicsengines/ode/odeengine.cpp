#include "odeengine.h"

#include <QVector3D>

#include <QDebug>
#include <QThread>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Engine {

OdeEngine::OdeEngine()
    : QPhysicsEngine()
    , m_running(false)
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
    m_running = false;
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
    m_running = true;
}

void OdeEngine::shutdown()
{
    qDebug() << __PRETTY_FUNCTION__ << QThread::currentThreadId();
    m_running = false;
}

void OdeEngine::setGravity(const QVector3D &gravity)
{
    qDebug() << __PRETTY_FUNCTION__ << QThread::currentThreadId();

    dWorldSetGravity(m_worldID, gravity.x(), gravity.y(), gravity.z());
}

void OdeEngine::step(float dt)
{
    if(!m_running) return;

    dWorldStep(m_worldID, dt);
}

}
}

QT_END_NAMESPACE
