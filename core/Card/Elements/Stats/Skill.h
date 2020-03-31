#ifndef SKILL_H
#define SKILL_H

#include <QObject>

class Skill : public QObject
{
    Q_OBJECT
public:
    explicit Skill(QObject *parent = nullptr);

    QString name() const;
    int value() const;

signals:

public slots:
    void setName(const QString &name);
    void setValue(const int &value);

private:
    QString m_name;
    int m_value{0};
};

#endif // SKILL_H
