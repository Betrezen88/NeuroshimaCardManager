#ifndef EXPERIENCEEDITOR_H
#define EXPERIENCEEDITOR_H

#include <QObject>

#include "core_global.h"

class ExperienceData;
class SpecializationData;

class CORE_EXPORT ExperienceEditor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int available READ available NOTIFY availableChanged)
    Q_PROPERTY(int spended READ spended NOTIFY spendedChanged)
    Q_PROPERTY(bool isNewSkillAffortable READ isNewSkillAffortable NOTIFY isNewSkillAffortableChanged)

public:
    explicit ExperienceEditor(QObject *parent = nullptr);
    explicit ExperienceEditor(const QString& costFile,
                              ExperienceData* data,
                              SpecializationData* specialization,
                              QObject* parent = nullptr);

    int available() const;
    int spended() const;
    bool isNewSkillAffortable() const;

signals:
    void availableChanged();
    void spendedChanged();
    void isNewSkillAffortableChanged();

public slots:
    bool isAttributeAfordable(const int level) const;
    bool isSkillAfordable(const int level, const QStringList& specializations) const;

    void attributeIncreased(const int level);
    void attributeDecreased(const int level);

    void skillIncreased(const int level, const QStringList& specializations);
    void skillDecreased(const int level, const QStringList& specializations);

    void increaseSpended(const int value);
    void decreaseSpended(const int value);

private slots:
    void checkIfNewSkillIsAffortable();

private:
    void loadCostData(const QString& costFile);
    int attributeCost(const int level) const;
    int skillCost(const int level, const bool discount) const;

private:
    QString m_costFile;
    ExperienceData* m_data{nullptr};
    SpecializationData* m_specialization{nullptr};

    QVector<int> m_skillCost;
    QVector<int> m_attributeCost;

    QPair<int, int> m_reputationCost;
    QPair<int, int> m_trickCost;

    const double m_discount{0.2};
    bool m_isNewSkillAffortable;
};

#endif // EXPERIENCEEDITOR_H
