#ifndef CONVERTER_H
#define CONVERTER_H

#include <QJsonObject>

class Card;
class Data;
class Stats;
class Equipment;

class Disease;
class Symptom;
class Penalty;
class Skill;
class Skillpack;
class Attribute;
class Trick;
class OtherSkill;

class Item;

class Converter
{
public:
    Converter();
    ~Converter() = default;

    QJsonObject toJson(const Card* card);

private:
    QJsonObject fromStats(const Stats* stats);
    QJsonObject fromData(const Data* data);
    QJsonObject fromDisease(const Disease* disease);
    QJsonObject fromSymptom(const Symptom* symptom);
    QJsonObject fromPenalty(const Penalty* penalty);
    QJsonObject fromSkill(const Skill* skill);
    QJsonObject fromSkillpack(const Skillpack* skillpack);
    QJsonObject fromAttribute(const Attribute* attribute);
    QJsonObject fromTrick(const Trick* trick);
    QJsonObject fromOtherSkill(const OtherSkill* otherSkill);

    QJsonObject fromEquipment(const Equipment* equipment);
    QJsonObject fromItem(const Item* item);
};

#endif // CONVERTER_H
