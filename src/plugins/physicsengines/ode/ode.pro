TARGET = odephysics
QT += core-private 3dcore-private 3dphysics-private

HEADERS += \
    odeengine.h

SOURCES += \
    main.cpp \
    odeengine.cpp

DISTFILES += \
    ode.json

PLUGIN_TYPE = physicsengines
PLUGIN_CLASS_NAME = OdePhysicsPlugin
load(qt_plugin)

