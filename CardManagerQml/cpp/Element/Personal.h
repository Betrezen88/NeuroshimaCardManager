#ifndef PERSONAL_H
#define PERSONAL_H

#include <QObject>

class PersonalData;

class Personal : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString surname READ surname CONSTANT)
    Q_PROPERTY(QString nickname READ nickname CONSTANT)
    Q_PROPERTY(QString fullname READ fullname CONSTANT)
public:
    explicit Personal(PersonalData *personalData, QObject *parent = nullptr);

    QString name() const;
    QString surname() const;
    QString nickname() const;
    QString fullname() const;

signals:

private:
    PersonalData *m_pPersonalData{nullptr};
};

#endif // PERSONAL_H
