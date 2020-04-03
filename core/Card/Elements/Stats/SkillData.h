#ifndef SKILLDATA_H
#define SKILLDATA_H

#include <QObject>

class SkillData : public QObject
{
    Q_OBJECT
public:
    explicit SkillData(QObject *parent = nullptr);

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

#endif // SKILLDATA_H
