#ifndef ATTRIBUTEDATA_H
#define ATTRIBUTEDATA_H

#include <QObject>
#include <QMap>

class SkillpackData;

class AttributeData : public QObject
{
    Q_OBJECT
public:
    explicit AttributeData(QObject *parent = nullptr);

    QString name() const;
    int value() const;

    QMap<QString, SkillpackData*> skillpacks() const;

    bool hasSkillpack(const QString &name) const;

signals:

public slots:
    void setName(const QString &name);
    void setValue(const int &value);
    void setSkillpacks(const QMap<QString, SkillpackData*> skillpacks);

private:
    QString m_name;
    int m_value;
    QMap<QString, SkillpackData*> m_skillpacks;
};

#endif // ATTRIBUTEDATA_H
