#ifndef QT3DPHYSICS_QPHYSICSENGINEPLUGIN_P_H
#define QT3DPHYSICS_QPHYSICSENGINEPLUGIN_P_H

#include <QtCore/qobject.h>
#include <QtCore/qstringlist.h>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

#define QPhysicsEngineFactoryInterface_iid "org.qt-project.Qt3DPhysics.QPhysicsEngineFactoryInterface 5.12"

class QPhysicsEngine;

class QQPhysicsEnginePlugin : public QObject
{
    Q_OBJECT
public:
    explicit QQPhysicsEnginePlugin(QObject *parent = nullptr);
    ~QQPhysicsEnginePlugin();

    virtual QPhysicsEngine *create(const QString &key, const QStringList &paramList);
};

}

QT_END_NAMESPACE

#endif // QPHYSICSENGINEPLUGIN_P_H
