TEMPLATE = subdirs

src_physics.subdir = $$PWD/physics
src_physics.target = sub-physics

src_plugins_engines.file = $$PWD/plugins/engines/engines.pro
src_plugins_engines.target = sub-plugins-engines
src_plugins_engines.depends = src_physics

SUBDIRS += src_physics

QT_FOR_CONFIG += 3dphysics
include($$OUT_PWD/physics/qt3dphysics-config.pri)

SUBDIRS += src_plugins_engines

