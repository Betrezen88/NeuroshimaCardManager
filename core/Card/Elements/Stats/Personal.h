#ifndef PERSONAL_H
#define PERSONAL_H

#include <QObject>
#include <QMap>

class Origin;
class Profession;
class Specialization;
class Disease;

class Personal : public QObject
{
    Q_OBJECT
public:
    explicit Personal(QObject *parent = nullptr);

    QString name() const;
    QString surname() const;
    QString nickname() const;
    QString fullname() const;

    Origin *origin() const;
    Profession *profession() const;
    Specialization *specialization() const;
    Disease *disease() const;

public slots:
    void setName(const QString &name);
    void setSurname(const QString &surname);
    void setNickname(const QString &nickname);

    void setOrigin(Origin *origin);
    void setProfession(Profession *profession);
    void setSpecialization(Specialization *specialization);
    void setDisease(Disease *disease);

    void setReputation(const QString &place, const int &value);

private:
    QString m_name;
    QString m_surname;
    QString m_nickname;

    Origin *m_origin{nullptr};
    Profession *m_profession{nullptr};
    Specialization *m_specialization{nullptr};
    Disease *m_disease{nullptr};

    QMap<QString, int> m_reputation;
    int m_fame{0};
};

#endif // PERSONAL_H
