#include "CardBuilder.h"

#include "Card/Data.h"
#include "Card/Card.h"
#include "Card/Elements/Stats/Attribute.h"
#include "Card/Elements/Stats/Skillpack.h"
#include "Card/Elements/Stats/Skill.h"
#include "Card/Elements/Stats/Disease.h"
#include "Card/Elements/Stats/Trick.h"
#include "Card/Elements/Stats/OtherSkill.h"

#include "Card/Pages/Rules.h"
#include "Card/Pages/Stats.h"
#include "Card/Pages/Equipment.h"

#include "Card/Elements/Equipment/Item.h"
#include "Card/Elements/Rules/RulesSection.h"

#include "../Creators/ItemCreator.h"

#include <QJsonValue>

#include <QDebug>

CardBuilder::CardBuilder(QObject *parent) : QObject(parent)
{

}

Card *CardBuilder::build(const QString &filePath, const QJsonObject &json)
{
    Card *pCard = new Card(filePath);

    if ( json.contains("stats") )
        pCard->addPage( statsPage(json.value("stats").toObject()) );
    if ( json.contains("equipment") )
        pCard->addPage( equipmentPage(json.value("equipment").toObject()) );

    return pCard;
}

Stats *CardBuilder::statsPage(const QJsonObject &stats)
{
    const QJsonObject &personal = stats.value("personal").toObject();
    const QJsonObject &name = personal.value("name").toObject();
    const QJsonObject &origin = personal.value("origin").toObject();
    const QJsonObject &profession = personal.value("profession").toObject();
    const QJsonObject &specialization = personal.value("specialization").toObject();
    const QJsonObject &disease = personal.value("disease").toObject();
    const QJsonObject &features = personal.value("features").toObject();
    const QJsonObject &fOrigin = features.value("origin").toObject();
    const QJsonObject &fProfession = features.value("profession").toObject();

    QVector<Symptom*> symptoms;
    QVector<Attribute*> attributes;

    for ( const QJsonValue &attribute: stats.value("attributes").toArray() ) {
        const QJsonObject &tAttribute = attribute.toObject();

        QVector<Skillpack*> skillpacks;

        for ( const QJsonValue skillpack: tAttribute.value("skillpacks").toArray() ) {
            const QJsonObject &tSkillpack = skillpack.toObject();

            QStringList specializations;
            for ( const QJsonValue &spec: tSkillpack.value("specializations").toArray() ) {
                specializations.push_back( spec.toString() );
            }

            QVector<Skill*> skills;

            for ( const QJsonValue &skill: tSkillpack.value("skills").toArray() ) {
                const QJsonObject &tSkill = skill.toObject();
                skills.push_back( new Skill(tSkill.value("name").toString(),
                                            tSkill.value("value").toInt(),
                                            tSkill.value("used").toBool()) );
            }
            const Skillpack::Type &type = (skills.count() != 3)
                    ? Skillpack::Type::CHOOSABLE
                    : Skillpack::Type::CONSTANT;

            skillpacks.push_back( new Skillpack(tSkillpack.value("name").toString(),
                                                specializations,
                                                skills,
                                                type) );
        }
        attributes.push_back( new Attribute(tAttribute.value("name").toString(),
                                            tAttribute.value("value").toInt(),
                                            skillpacks) );
    }

    QVector<Trick*> tricks;
    for ( const QJsonValue &trick: stats.value("tricks").toArray() ) {
        const QJsonObject &tTrick = trick.toObject();

        tricks.push_back( new Trick(tTrick.value("name").toString(),
                                    tTrick.value("description").toString(),
                                    tTrick.value("action").toString()) );
    }

    QVector<OtherSkill*> otherSkills;
    for ( const QJsonValue &otherSkill: stats.value("otherSkills").toArray() ) {
        const QJsonObject &tOtherSkill = otherSkill.toObject();

        otherSkills.push_back( new OtherSkill(tOtherSkill.value("name").toString(),
                                              tOtherSkill.value("value").toInt(),
                                              tOtherSkill.value("used").toBool(),
                                              tOtherSkill.value("attribute").toString()) );
    }
    const QJsonObject &experience = stats.value("experience").toObject();

    return new Stats(name.value("name").toString(),
                     name.value("surname").toString(),
                     name.value("nickname").toString(),
                     new Data(origin.value("name").toString(),
                              origin.value("description").toString()),
                     new Data(profession.value("name").toString(),
                              profession.value("description").toString()),
                     new Data(fOrigin.value("name").toString(),
                              fOrigin.value("description").toString()),
                     new Data(fProfession.value("name").toString(),
                              fProfession.value("description").toString()),
                     new Data(specialization.value("name").toString(),
                              specialization.value("description").toString()),
                     new Disease(disease.value("name").toString(),
                                 disease.value("disease").toString(),
                                 disease.value("cure").toString(),
                                 QVector<Symptom*>()),
                     attributes,
                     tricks,
                     otherSkills,
                     QPair<int, int>(experience.value("gathered").toInt(),
                                     experience.value("spended").toInt()) );
}

Equipment *CardBuilder::equipmentPage(const QJsonObject &equipment)
{
    QList<Item*> backpack;
    ItemCreator creator;
    for ( const QJsonValue& backpackItem: equipment.value("backpack").toArray() ) {
        const QJsonObject& tBackpackItem = backpackItem.toObject();

        backpack.append( creator.create(tBackpackItem) );
    }

    return new Equipment(backpack);
}

Rules *CardBuilder::rulesPage(const QJsonArray &rules)
{
    Rules* pRules = new Rules();

    for (const QJsonValue &section: rules) {
        const QJsonObject &tSection = section.toObject();

        QList<QStringList> rows;

        for ( const QJsonValue &row: tSection.value("rows").toArray() ) {
            const QJsonArray& tRow = row.toArray();
            QStringList cells;
            for ( const QJsonValue& cell: tRow )
                cells << cell.toString();
            rows.append(cells);
        }

        pRules->addSection(tSection.value("section").toString(),
                           rows);
    }

    return pRules;
}
