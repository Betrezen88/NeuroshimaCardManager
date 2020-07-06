#ifndef DIFFICULTY_H
#define DIFFICULTY_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT Difficulty : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString shortname READ shortname CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)

public:
    explicit Difficulty(QObject *parent = nullptr);
    explicit Difficulty(const QString &name,
                        const QString &shortname,
                        const int &value,
                        QObject *parent = nullptr);

    QString name() const;
    QString shortname() const;
    int value() const;

private:
    QString m_name;
    QString m_shortname;
    int m_value{0};
};

#endif // DIFFICULTY_H
