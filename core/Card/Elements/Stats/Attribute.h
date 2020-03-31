#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QObject>
#include <QMap>

class Skillpack;

class Attribute : public QObject
{
    Q_OBJECT
public:
    explicit Attribute(QObject *parent = nullptr);

    QString name() const;
    int value() const;

    QMap<QString, Skillpack*> skillpacks() const;

    bool hasSkillpack(const QString &name) const;

signals:

public slots:
    void setName(const QString &name);
    void setValue(const int &value);
    void setSkillpacks(const QMap<QString, Skillpack*> skillpacks);

private:
    QString m_name;
    int m_value;
    QMap<QString, Skillpack*> m_skillpacks;
};

#endif // ATTRIBUTE_H
