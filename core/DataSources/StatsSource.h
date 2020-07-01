#ifndef STATSSOURCE_H
#define STATSSOURCE_H

#include <QQmlListProperty>

#include "DataSource.h"

#include "core_global.h"

class Origin;
class Profession;
class Data;
class Disease;
class Attribute;
class NSTrick;

class CORE_EXPORT StatsSource : public DataSource
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Origin> origins READ origins NOTIFY originsChanged)
    Q_PROPERTY(QQmlListProperty<Profession> professions READ professions NOTIFY professionsChanged)
    Q_PROPERTY(QQmlListProperty<Data> specializations READ specializations NOTIFY specializationsChanged)
    Q_PROPERTY(QQmlListProperty<Disease> diseases READ diseases NOTIFY diseasesChanged)
    Q_PROPERTY(QQmlListProperty<Attribute> attributes READ attributes NOTIFY attributesChanged)
    Q_PROPERTY(QQmlListProperty<NSTrick> tricks READ tricks NOTIFY tricksChanged)

public:
    explicit StatsSource(QObject *parent = nullptr);

    QQmlListProperty<Origin> origins();
    void addOrigin(Origin* origin);
    int originsCount() const;
    Origin* origin(const int &index) const;
    void clearOrigins();

    QQmlListProperty<Profession> professions();
    void addProfession(Profession* profession);
    int professionsCount() const;
    Profession* profession(const int &index) const;
    void clearProfessions();

    QQmlListProperty<Data> specializations();
    void addSpecialization(Data* specialization);
    int specializationsCount() const;
    Data* specialization(const int &index) const;
    void clearSpecializations();

    QQmlListProperty<Disease> diseases();
    void addDisease(Disease* disease);
    int diseasesCount() const;
    Disease* disease(const int &index) const;
    void clearDiseases();

    QQmlListProperty<Attribute> attributes();
    void addAttribute(Attribute* attribute);
    int attributesCount() const;
    Attribute* attribute(const int &index) const;
    void clearAttributes();

    Q_INVOKABLE Attribute* attribute(const QString &name) const;

    QQmlListProperty<NSTrick> tricks();
    void addTrick(NSTrick* trick);
    int tricksCount() const;
    NSTrick* trick(const int &index) const;
    void clearTricks();

signals:
    void originsChanged();
    void professionsChanged();
    void specializationsChanged();
    void diseasesChanged();
    void attributesChanged();
    void tricksChanged();

private:
    static void addOrigin(QQmlListProperty<Origin> *list, Origin *origin);
    static int originsCount(QQmlListProperty<Origin> *list);
    static Origin* origin(QQmlListProperty<Origin> *list, int index);
    static void clearOrigins(QQmlListProperty<Origin> *list);

    static void addProfession(QQmlListProperty<Profession> *list, Profession *profession);
    static int professionsCount(QQmlListProperty<Profession> *list);
    static Profession* profession(QQmlListProperty<Profession> *list, int index);
    static void clearProfessions(QQmlListProperty<Profession> *list);

    static void addSpecialization(QQmlListProperty<Data> *list, Data* specialization);
    static int specializationsCount(QQmlListProperty<Data> *list);
    static Data* specialization(QQmlListProperty<Data> *list, int index);
    static void clearSpecializations(QQmlListProperty<Data> *list);

    static void addDisease(QQmlListProperty<Disease> *list, Disease* disease);
    static int diseasesCount(QQmlListProperty<Disease> *list);
    static Disease* disease(QQmlListProperty<Disease> *list, int index);
    static void clearDiseases(QQmlListProperty<Disease> *list);

    static void addAttribute(QQmlListProperty<Attribute> *list, Attribute* attribute);
    static int attributesCount(QQmlListProperty<Attribute> *list);
    static Attribute* attribute(QQmlListProperty<Attribute> *list, int index);
    static void clearAttributes(QQmlListProperty<Attribute> *list);

    static void addTrick(QQmlListProperty<NSTrick> *list, NSTrick* trick);
    static int tricksCount(QQmlListProperty<NSTrick> *list);
    static NSTrick* trick(QQmlListProperty<NSTrick> *list, int index);
    static void clearTricks(QQmlListProperty<NSTrick> *list);

private:
    QVector<Origin*> m_origins;
    QVector<Profession*> m_professions;
    QVector<Data*> m_specializations;
    QVector<Disease*> m_diseases;
    QVector<Attribute*> m_attributes;
    QVector<NSTrick*> m_tricks;
};

#endif // STATSSOURCE_H
