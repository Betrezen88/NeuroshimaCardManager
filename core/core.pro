QT -= gui

TEMPLATE = lib
DEFINES += CORE_LIBRARY

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Card/Attribute.cpp \
    Card/Card.cpp \
    Card/Disease.cpp \
    Card/Feature.cpp \
    Card/Origin.cpp \
    Card/Pages/Stats.cpp \
    Card/Personal.cpp \
    Card/Profession.cpp \
    Card/Skill.cpp \
    Card/Skillpack.cpp \
    Card/Specialization.cpp \

HEADERS += \
    Card/Attribute.h \
    Card/Card.h \
    Card/Disease.h \
    Card/Feature.h \
    Card/Origin.h \
    Card/Pages/Stats.h \
    Card/Personal.h \
    Card/Profession.h \
    Card/Skill.h \
    Card/Skillpack.h \
    Card/Specialization.h \
    core_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
