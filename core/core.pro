QT -= gui
QT += qml

TEMPLATE = lib
DEFINES += CORE_LIBRARY

CONFIG += c++11
CONFIG += plugin

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
    Creators/ItemCreator.cpp \
    Edit/Pages/StatsEditor.cpp \
    Edit/Stats/AttributeEdit.cpp \
    Edit/Stats/ExperienceEditor.cpp \
    Edit/Stats/OtherSkillEdit.cpp \
    Edit/Stats/ReputationEdit.cpp \
    Edit/Stats/SkillEdit.cpp \
    Edit/Stats/SkillpackEdit.cpp \
    Managers/CardManager.cpp \
    Managers/MainManager.cpp \
    Managers/SettingsManager.cpp \
    Utils/CardBuilder.cpp \
    Utils/Converter.cpp \
    Utils/DataBuilder.cpp \
    Utils/DataReader.cpp \
    Utils/DataWriter.cpp \
    View/Card.cpp \
    View/Common/Penalty.cpp \
    View/Common/Requirement.cpp \
    View/Equipment/ArmorFeature.cpp \
    View/Equipment/DexterityBonus.cpp \
    View/Equipment/Durability.cpp \
    View/Equipment/Item.cpp \
    View/Equipment/ItemStats.cpp \
    View/Equipment/Location.cpp \
    View/Equipment/Special.cpp \
    View/Notes/Question.cpp \
    View/Pages/Equipment.cpp \
    View/Pages/Notes.cpp \
    View/Pages/Stats.cpp \
    View/Stats/Attribute.cpp \
    View/Stats/Disease.cpp \
    View/Stats/Experience.cpp \
    View/Stats/Feature.cpp \
    View/Stats/Origin.cpp \
    View/Stats/OtherSkill.cpp \
    View/Stats/Profession.cpp \
    View/Stats/Reputation.cpp \
    View/Stats/Skill.cpp \
    View/Stats/Skillpack.cpp \
    View/Stats/Specialization.cpp \
    View/Stats/Symptom.cpp \
    View/Stats/Trick.cpp \
    View/Stats/Wound.cpp

HEADERS += \
    Creators/ItemCreator.h \
    Data/Common/PenaltyData.h \
    Data/Common/RequirementData.h \
    Data/Equipment/ArmorFeatureData.h \
    Data/Equipment/DexterityBonusData.h \
    Data/Equipment/DurabilityData.h \
    Data/Equipment/EquipmentData.h \
    Data/Equipment/ItemData.h \
    Data/Equipment/ItemStatsData.h \
    Data/Equipment/LocationData.h \
    Data/Equipment/SpecialData.h \
    Data/Notes/NotesData.h \
    Data/Notes/QuestionData.h \
    Data/Stats/AttributeData.h \
    Data/Stats/DiseaseData.h \
    Data/Stats/ExperienceData.h \
    Data/Stats/FeatureData.h \
    Data/Stats/OriginData.h \
    Data/Stats/OtherSkillData.h \
    Data/Stats/ProfessionData.h \
    Data/Stats/ReputationData.h \
    Data/Stats/SkillData.h \
    Data/Stats/SkillpackData.h \
    Data/Stats/SpecializationData.h \
    Data/Stats/StatsData.h \
    Data/Stats/SymptomData.h \
    Data/Stats/TrickData.h \
    Data/Stats/WoundData.h \
    Edit/Pages/StatsEditor.h \
    Edit/Stats/AttributeEdit.h \
    Edit/Stats/ExperienceEditor.h \
    Edit/Stats/OtherSkillEdit.h \
    Edit/Stats/ReputationEdit.h \
    Edit/Stats/SkillEdit.h \
    Edit/Stats/SkillpackEdit.h \
    Managers/CardManager.h \
    Managers/MainManager.h \
    Managers/SettingsManager.h \
    Utils/CardBuilder.h \
    Utils/Converter.h \
    Utils/DataBuilder.h \
    Utils/DataReader.h \
    Utils/DataWriter.h \
    Utils/Dice.h \
    View/Card.h \
    View/Common/Penalty.h \
    View/Common/Requirement.h \
    View/Equipment/ArmorFeature.h \
    View/Equipment/DexterityBonus.h \
    View/Equipment/Durability.h \
    View/Equipment/Item.h \
    View/Equipment/ItemStats.h \
    View/Equipment/Location.h \
    View/Equipment/Special.h \
    View/Notes/Question.h \
    View/Pages/Equipment.h \
    View/Pages/Notes.h \
    View/Pages/Page.h \
    View/Pages/Stats.h \
    View/Stats/Attribute.h \
    View/Stats/Disease.h \
    View/Stats/Experience.h \
    View/Stats/Feature.h \
    View/Stats/Origin.h \
    View/Stats/OtherSkill.h \
    View/Stats/Profession.h \
    View/Stats/Reputation.h \
    View/Stats/Skill.h \
    View/Stats/Skillpack.h \
    View/Stats/Specialization.h \
    View/Stats/Symptom.h \
    View/Stats/Trick.h \
    View/Stats/Wound.h \
    core_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DESTDIR += $$OUT_PWD/../core/
