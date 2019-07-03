#include "qphysicsenginefactory_p.h"
#include "qphysicsengineplugin_p.h"
#include "qphysicsengine_p.h"

#include <QtCore/private/qfactoryloader_p.h>
#include <QtCore/qcoreapplication.h>
#include <QtCore/qpluginloader.h>
#include <QtCore/qdir.h>

#include <QtDebug>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {
namespace Engine {

Q_GLOBAL_STATIC_WITH_ARGS(QFactoryLoader, loader, (QPhysicsEngineFactoryInterface_iid, QLatin1String("/physicsengines"), Qt::CaseInsensitive))
#ifndef QT_NO_LIBRARY
Q_GLOBAL_STATIC_WITH_ARGS(QFactoryLoader, directLoader, (QPhysicsEngineFactoryInterface_iid, QLatin1String(""), Qt::CaseInsensitive))
#endif

QStringList QPhysicsEngineFactory::keys(const QString &pluginPath)
{

    qDebug() << __PRETTY_FUNCTION__ << QCoreApplication::applicationFilePath();
    QStringList list;
    if(!pluginPath.isEmpty()){
#if QT_CONFIG(library)
        QCoreApplication::addLibraryPath(pluginPath);
        list = directLoader()->keyMap().values();
        qDebug() << list;
        if (!list.isEmpty()) {
            const QString postFix = QLatin1String(" (from ")
                    + QDir::toNativeSeparators(pluginPath)
                    + QLatin1Char(')');
            const QStringList::iterator end = list.end();
            for (QStringList::iterator it = list.begin(); it != end; ++it)
                (*it).append(postFix);
        }
#else
        qWarning() << QPhysicsEngine::tr("Cannot query QPhysicsEngine plugins at %1. "
                                         "Library loading is disabled.").arg(pluginPath);
#endif

    }
    list.append(loader()->keyMap().values());

    return list;
}

QPhysicsEngine * QPhysicsEngineFactory::create(const QString &name, const QStringList &args, const QString &pluginPath)
{
    qDebug() << __PRETTY_FUNCTION__;
    if (!pluginPath.isEmpty()) {
#if QT_CONFIG(library)
        QCoreApplication::addLibraryPath(pluginPath);
        if (QPhysicsEngine *ret = qLoadPlugin<QPhysicsEngine, QPhysicsEnginePlugin>(directLoader(), name, args))
            return ret;
#else
        qWarning() << QPhysicsEngine::tr("Cannot load QPhysicsEngine plugin from %1. "
                                         "Library loading is disabled.").arg(pluginPath);
#endif
    }
    return qLoadPlugin<QPhysicsEngine, QPhysicsEnginePlugin>(loader(), name, args);
}

}
}

QT_END_NAMESPACE
