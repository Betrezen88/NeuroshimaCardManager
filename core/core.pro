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
    Card/Card.cpp \
    Card/Pages/Stats.cpp \
    Card/Elements/Stats/Attribute.cpp \
    Card/Elements/Stats/Disease.cpp \
    Card/Elements/Stats/Feature.cpp \
    Card/Elements/Stats/Origin.cpp \
    Card/Elements/Stats/Personal.cpp \
    Card/Elements/Stats/Profession.cpp \
    Card/Elements/Stats/Skill.cpp \
    Card/Elements/Stats/Skillpack.cpp \
    Card/Elements/Stats/Specialization.cpp \
    Utils/CardBuilder.cpp \
    Utils/DataReader.cpp

HEADERS += \
    Card/Card.h \
    Card/Pages/Stats.h \
    Card/Elements/Stats/Attribute.h \
    Card/Elements/Stats/Disease.h \
    Card/Elements/Stats/Feature.h \
    Card/Elements/Stats/Origin.h \
    Card/Elements/Stats/Personal.h \
    Card/Elements/Stats/Profession.h \
    Card/Elements/Stats/Skill.h \
    Card/Elements/Stats/Skillpack.h \
    Card/Elements/Stats/Specialization.h \
    Utils/CardBuilder.h \
    Utils/DataReader.h \
    core_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
