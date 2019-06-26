#include "odeengine.h"

#include <QDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

OdeEngine::OdeEngine()
    : QPhysicsEngine()
{
    qDebug() << __PRETTY_FUNCTION__;
}

OdeEngine::~OdeEngine()
{
    qDebug() << __PRETTY_FUNCTION__;
}

}

QT_END_NAMESPACE
