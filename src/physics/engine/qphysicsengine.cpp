#include "qphysicsengine_p.h"

#include <QDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Engine {

QPhysicsEngine::QPhysicsEngine()
    :QObject()
{
    qDebug() << __PRETTY_FUNCTION__;

}

QPhysicsEngine::~QPhysicsEngine()
{
    qDebug() << __PRETTY_FUNCTION__;

}

}
}

QT_END_NAMESPACE

