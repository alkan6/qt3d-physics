TARGET  = Qt3DPhysics
MODULE  = 3dphysics

QT      = core-private gui-private 3dcore-private 3dcore

DEFINES += QT3DPHYSICS_LIBRARY
DEFINES += QT_NO_FOREACH

include(frontend/frontend.pri)
include(backend/backend.pri)
include(engine/engine.pri)
include(jobs/jobs.pri)

HEADERS += \
    $$PWD/qt3dphysics_global.h \
    $$PWD/qt3dphysics_global_p.h

SOURCES +=

MODULE_PLUGIN_TYPES = \
    physicsengines

load(qt_module)
