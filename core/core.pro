QT -= gui

TARGET = core
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
    Card/CardData.cpp \
    Card/Elements/Stats/AttributeData.cpp \
    Card/Elements/Stats/DiseaseData.cpp \
    Card/Elements/Stats/FeatureData.cpp \
    Card/Elements/Stats/OriginData.cpp \
    Card/Elements/Stats/PersonalData.cpp \
    Card/Elements/Stats/ProfessionData.cpp \
    Card/Elements/Stats/SkillData.cpp \
    Card/Elements/Stats/SkillpackData.cpp \
    Card/Elements/Stats/SpecializationData.cpp \
    Card/Pages/StatsData.cpp \
    Utils/CardBuilder.cpp \
    Utils/DataReader.cpp

HEADERS += \
    Card/CardData.h \
    Card/Elements/Stats/AttributeData.h \
    Card/Elements/Stats/DiseaseData.h \
    Card/Elements/Stats/FeatureData.h \
    Card/Elements/Stats/OriginData.h \
    Card/Elements/Stats/PersonalData.h \
    Card/Elements/Stats/ProfessionData.h \
    Card/Elements/Stats/SkillData.h \
    Card/Elements/Stats/SkillpackData.h \
    Card/Elements/Stats/SpecializationData.h \
    Card/Pages/StatsData.h \
    Utils/CardBuilder.h \
    Utils/DataReader.h \
    core_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
