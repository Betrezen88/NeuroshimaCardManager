QT -= gui
QT += qml

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
    Card/Data.cpp \
    Card/Elements/Stats/Attribute.cpp \
    Card/Elements/Stats/Disease.cpp \
    Card/Elements/Stats/OtherSkill.cpp \
    Card/Elements/Stats/Penalty.cpp \
    Card/Elements/Stats/Requirement.cpp \
    Card/Elements/Stats/Skill.cpp \
    Card/Elements/Stats/Skillpack.cpp \
    Card/Elements/Stats/Symptom.cpp \
    Card/Elements/Stats/Trick.cpp \
    Card/Pages/Page.cpp \
    Card/Pages/Stats.cpp \
    Managers/CardManager.cpp \
    Managers/MainManager.cpp \
    Utils/CardBuilder.cpp \
    Utils/DataReader.cpp

HEADERS += \
    Card/Card.h \
    Card/Data.h \
    Card/Elements/Stats/Attribute.h \
    Card/Elements/Stats/Disease.h \
    Card/Elements/Stats/OtherSkill.h \
    Card/Elements/Stats/Penalty.h \
    Card/Elements/Stats/Requirement.h \
    Card/Elements/Stats/Skill.h \
    Card/Elements/Stats/Skillpack.h \
    Card/Elements/Stats/Symptom.h \
    Card/Elements/Stats/Trick.h \
    Card/Pages/Page.h \
    Card/Pages/Stats.h \
    Managers/CardManager.h \
    Managers/MainManager.h \
    Utils/CardBuilder.h \
    Utils/DataReader.h \
    core_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
