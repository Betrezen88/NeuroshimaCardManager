#ifndef RULES_H
#define RULES_H

#include <QObject>
#include <QQmlListProperty>

#include "Page.h"
#include "../Data.h"

#include "core_global.h"

class RulesSection;

class CORE_EXPORT Rules : public Page
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<RulesSection> sections READ sections CONSTANT)

public:
    explicit Rules(QObject *parent = nullptr);

    void addSection(const QString& title, const QList<QStringList>& rows);

    QQmlListProperty<RulesSection> sections();

private:
    QList<RulesSection*> m_sections;
};

#endif // RULES_H
