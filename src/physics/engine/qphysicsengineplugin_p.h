#ifndef QT3DPHYSICS_QPHYSICSENGINEPLUGIN_P_H
#define QT3DPHYSICS_QPHYSICSENGINEPLUGIN_P_H

#include <Qt3DPhysics/private/qt3dphysics_global_p.h>

#include <QtCore/QObject>
#include <QtCore/QtPlugin>
#include <QtCore/QStringList>
#include <QtCore/QFactoryInterface>

QT_BEGIN_NAMESPACE

namespace Qt3DPhysics {

#define QPhysicsEngineFactoryInterface_iid "org.qt-project.Qt3DPhysics.QPhysicsEngineFactoryInterface 5.12"

class QPhysicsEngine;

class QT3DPHYSICS_PRIVATE_EXPORT QPhysicsEnginePlugin : public QObject
{
    Q_OBJECT

public:
    explicit QPhysicsEnginePlugin(QObject *parent = nullptr);
    ~QPhysicsEnginePlugin();

    virtual QPhysicsEngine *create(const QString &key, const QStringList &paramList);
};

}

QT_END_NAMESPACE

#endif // QPHYSICSENGINEPLUGIN_P_H
