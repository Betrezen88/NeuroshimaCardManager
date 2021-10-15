#ifndef EXPERIENCEEDITOR_H
#define EXPERIENCEEDITOR_H

#include <QObject>

#include "core_global.h"

class ExperienceData;

class CORE_EXPORT ExperienceEditor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int available READ available NOTIFY availableChanged)
    Q_PROPERTY(int spended READ spended NOTIFY spendedChanged)

public:
    explicit ExperienceEditor(QObject *parent = nullptr);
    explicit ExperienceEditor(const QString& costFile,
                              ExperienceData* data,
                              QObject* parent = nullptr);

    int available() const;
    int spended() const;

    int attributeCost(const int level) const;

signals:
    void availableChanged();
    void spendedChanged();

public slots:
    bool isAttributeAfordable(const int level) const;
    bool isSkillAfordable(const int level, const QStringList& specializations) const;

    void attributeIncreased(const int level);
    void attributeDecreased(const int level);

    void increaseSpended(const int value);
    void decreaseSpended(const int value);

private:
    void loadCostData(const QString& costFile);

private:
    QString m_costFile;
    ExperienceData* m_data{nullptr};

    QVector<int> m_skillCost;
    QVector<int> m_attributeCost;

    QPair<int, int> m_reputationCost;
    QPair<int, int> m_trickCost;
};

#endif // EXPERIENCEEDITOR_H
