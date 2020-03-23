#ifndef PERSONAL_H
#define PERSONAL_H

#include <QObject>
#include <QString>

class Personal
{
    Q_OBJECT
public:
    Personal();

    QString name() const;
    QString surname() const;
    QString nickname() const;
    QString fullname() const;

public slots:
    void setName(const QString &name);
    void setSurname(const QString &surname);
    void setNickname(const QString &nickname);

private:
    QString m_name;
    QString m_surname;
    QString m_nickname;
};

#endif // PERSONAL_H
