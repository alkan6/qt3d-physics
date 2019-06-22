TARGET = odephysics

DISTFILES += \
    ode.json

PLUGIN_TYPE = engines
PLUGIN_CLASS_NAME = OdePhysicsPlugin
load(qt_plugin)
