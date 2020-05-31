#ifndef HEROCREATORMANAGER_H
#define HEROCREATORMANAGER_H

#include <QObject>

class CardData;
class StatsData;
class PersonalData;
class OriginData;
class ProfessionData;
class SpecializationData;
class DiseaseData;
class FeatureData;

class HeroCreatorData;

class HeroCreatorManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(HeroCreatorData *heroCreatorData READ heroCreatorData CONSTANT)

public:
    explicit HeroCreatorManager(QObject *parent = nullptr);

    CardData *cardData() const;

    HeroCreatorData *heroCreatorData();

signals:
    void originFeatureChanged();
    void professionFeatureChanged();

public slots:
    Q_INVOKABLE void setName(const QString &name);
    Q_INVOKABLE void setSurname(const QString &surname);
    Q_INVOKABLE void setNickname(const QString &nickname);
    Q_INVOKABLE void setOrigin(OriginData *origin);
    Q_INVOKABLE void setOriginFeature(FeatureData *feature);
    Q_INVOKABLE void setProfession(ProfessionData *profession);
    Q_INVOKABLE void setProfessionFeature(FeatureData *feature);

private:
    HeroCreatorData *m_pHeroCreatorData{nullptr};
    CardData *m_pCardData{nullptr};
    StatsData *m_pStatsData{nullptr};
    PersonalData *m_pPersonalData{nullptr};
};

#endif // HEROCREATORMANAGER_H
