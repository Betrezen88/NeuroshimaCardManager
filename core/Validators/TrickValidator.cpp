#include "TrickValidator.h"

#include "../Edit/Pages/StatsEditor.h"
#include "../Edit/Stats/TrickEdit.h"

TrickValidator::TrickValidator(QObject *parent) : QObject(parent)
{

}

TrickValidator::TrickValidator(StatsEditor *statsEditor, QObject *parent)
    : QObject(parent)
    , m_pStatsEditor(statsEditor)
{

}

void TrickValidator::trickMeetsRequirements(TrickEdit *trick)
{
    if ( !m_pStatsEditor || !trick )
        return;

    trick->setMeetsRequirements( meetsAttributes(trick->attributes())
                                 && meetsSkills(trick->skills(false))
                                 && meetsSkills(trick->skills(true)) );
}

bool TrickValidator::meetsAttributes(const QVector<Requirement*>& requirements)
{
    for ( Requirement* requirement : requirements ) {
        if ( m_pStatsEditor->attribute(requirement->name())->value() < requirement->value() )
            return false;
    }
    return true;
}

bool TrickValidator::meetsSkills(const QVector<Requirement*>& requirements)
{
    const QHash<QString, SkillEdit*> skills = m_pStatsEditor->skills();
    for ( Requirement* requirement : requirements ) {
        if ( !skills.contains(requirement->name()) || skills.value(requirement->name())->value() < requirement->value()  ) {
            return false;
        }
    }
    return true;
}
