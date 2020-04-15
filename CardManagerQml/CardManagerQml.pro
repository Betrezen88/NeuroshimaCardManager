QT += quick

TARGET = NsCardManagerQml
TEMPLATE = app

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cpp/Card/CardWrapper.cpp \
        cpp/Element/AttributeWrapper.cpp \
        cpp/Element/DiseaseWrapper.cpp \
        cpp/Element/FeatureWrapper.cpp \
        cpp/Element/OriginWrapper.cpp \
        cpp/Element/ProfessionWrapper.cpp \
        cpp/Element/SkillWrapper.cpp \
        cpp/Element/SkillpackWrapper.cpp \
        cpp/Element/SpecializationWrapper.cpp \
        cpp/Page/StatsWrapper.cpp \
        cpp/Section/PersonalWrapper.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../core -lcore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../core -lcore
else:unix: LIBS += -L$$OUT_PWD/../core/ -lcore

INCLUDEPATH += $$PWD/../core
DEPENDPATH += $$PWD/../core

HEADERS += \
    cpp/Card/CardWrapper.h \
    cpp/Element/AttributeWrapper.h \
    cpp/Element/DiseaseWrapper.h \
    cpp/Element/FeatureWrapper.h \
    cpp/Element/OriginWrapper.h \
    cpp/Element/ProfessionWrapper.h \
    cpp/Element/SkillWrapper.h \
    cpp/Element/SkillpackWrapper.h \
    cpp/Element/SpecializationWrapper.h \
    cpp/Page/StatsWrapper.h \
    cpp/Section/PersonalWrapper.h
