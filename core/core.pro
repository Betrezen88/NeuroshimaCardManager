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
    Card/Elements/Equipment/Item.cpp \
    Card/Elements/Equipment/Location.cpp \
    Card/Elements/Rules/RulesSection.cpp \
    Card/Elements/Stats/Attribute.cpp \
    Card/Elements/Stats/Difficulty.cpp \
    Card/Elements/Stats/Disease.cpp \
    Card/Elements/Stats/OtherSkill.cpp \
    Card/Elements/Stats/Penalty.cpp \
    Card/Elements/Stats/Skill.cpp \
    Card/Elements/Stats/Skillpack.cpp \
    Card/Elements/Stats/Symptom.cpp \
    Card/Elements/Stats/Trick.cpp \
    Card/Elements/Stats/Wound.cpp \
    Card/Pages/Equipment.cpp \
    Card/Pages/Page.cpp \
    Card/Pages/Rules.cpp \
    Card/Pages/Stats.cpp \
    Creators/CardCreator.cpp \
    Creators/DataSourceCreator.cpp \
    Creators/ItemCreator.cpp \
    Creators/StatsCreator.cpp \
    DataSources/Elements/Stats/AttributeMod.cpp \
    DataSources/Elements/Stats/Bonus.cpp \
    DataSources/Elements/Stats/Feature.cpp \
    DataSources/Elements/Stats/HeroData.cpp \
    DataSources/Elements/Stats/Origin.cpp \
    DataSources/Elements/Stats/Profession.cpp \
    DataSources/Elements/Stats/Requirement.cpp \
    DataSources/Elements/Stats/SkillMod.cpp \
    DataSources/Elements/Stats/SkillpackMod.cpp \
    DataSources/Elements/Stats/TricksSortFilterModel.cpp \
    DataSources/StatsSource.cpp \
    Managers/CardManager.cpp \
    Managers/CreationPointsManager.cpp \
    Managers/MainManager.cpp \
    Utils/CardBuilder.cpp \
    Utils/Converter.cpp \
    Utils/DataReader.cpp \
    Utils/DataWriter.cpp \
    Validators/TrickValidator.cpp

HEADERS += \
    Card/Card.h \
    Card/Data.h \
    Card/Elements/Equipment/Item.h \
    Card/Elements/Equipment/Location.h \
    Card/Elements/Rules/RulesSection.h \
    Card/Elements/Stats/Attribute.h \
    Card/Elements/Stats/Difficulty.h \
    Card/Elements/Stats/Disease.h \
    Card/Elements/Stats/OtherSkill.h \
    Card/Elements/Stats/Penalty.h \
    Card/Elements/Stats/Skill.h \
    Card/Elements/Stats/Skillpack.h \
    Card/Elements/Stats/Symptom.h \
    Card/Elements/Stats/Trick.h \
    Card/Elements/Stats/Wound.h \
    Card/Pages/Equipment.h \
    Card/Pages/Page.h \
    Card/Pages/Rules.h \
    Card/Pages/Stats.h \
    Creators/CardCreator.h \
    Creators/DataSourceCreator.h \
    Creators/ItemCreator.h \
    Creators/PageCreator.h \
    Creators/StatsCreator.h \
    DataSources/DataSource.h \
    DataSources/Elements/Stats/AttributeMod.h \
    DataSources/Elements/Stats/Bonus.h \
    DataSources/Elements/Stats/Feature.h \
    DataSources/Elements/Stats/HeroData.h \
    DataSources/Elements/Stats/Origin.h \
    DataSources/Elements/Stats/OriginBonus.h \
    DataSources/Elements/Stats/Profession.h \
    DataSources/Elements/Stats/Requirement.h \
    DataSources/Elements/Stats/SkillMod.h \
    DataSources/Elements/Stats/SkillpackMod.h \
    DataSources/Elements/Stats/TricksSortFilterModel.h \
    DataSources/StatsSource.h \
    Managers/CardManager.h \
    Managers/CreationPointsManager.h \
    Managers/MainManager.h \
    Utils/CardBuilder.h \
    Utils/Converter.h \
    Utils/DataReader.h \
    Utils/DataWriter.h \
    Utils/Dice.h \
    Validators/TrickValidator.h \
    core_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DESTDIR += $$OUT_PWD/../core/
