#ifndef STATSDATA_H
#define STATSDATA_H

#include <QObject>
#include <QPair>
#include <QString>
#include <QVarLengthArray>
#include <QSharedPointer>
#include <QVector>

#include "OriginData.h"
#include "ProfessionData.h"
#include "DiseaseData.h"
#include "AttributeData.h"
#include "OtherSkillData.h"
#include "TrickData.h"
#include "WoundData.h"
#include "ReputationData.h"
#include "SpecializationData.h"
#include "ExperienceData.h"

#include "core_global.h"

struct CORE_EXPORT StatsData {
    Q_GADGET

public:
    QString name;
    QString surname;
    QString nickname;

    OriginData origin;
    ProfessionData profession;
    SpecializationData specialization;
    DiseaseData disease;
    QVarLengthArray<AttributeData, 5> attributes;
    QVector<QSharedPointer<OtherSkillData>> otherSkills;
    QVector<TrickData> tricks;
    QVector<QSharedPointer<WoundData>> wounds;
    QVector<ReputationData> reputation;
    ExperienceData experience;
};

Q_DECLARE_METATYPE(StatsData)

#endif // STATSDATA_H
