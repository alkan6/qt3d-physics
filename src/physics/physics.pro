TARGET  = Qt3DPhysics
MODULE  = 3dphysics

QT      = core-private gui-private 3dcore-private

DEFINES += QT3DPHYSICS_LIBRARY
DEFINES += QT_NO_FOREACH

include(frontend/frontend.pri)
include(backend/backend.pri)

HEADERS += \
    $$PWD/qt3dphysics_global.h \
    $$PWD/qt3dphysics_global_p.h

SOURCES +=

MODULE_PLUGIN_TYPES = \
    engines

load(qt_module)
