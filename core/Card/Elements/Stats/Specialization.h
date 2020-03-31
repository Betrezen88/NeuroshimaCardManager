#ifndef SPECIALIZATION_H
#define SPECIALIZATION_H

#include <QObject>

class Specialization : public QObject
{
    Q_OBJECT
public:
    explicit Specialization(const QString &name,
                            const QString &description,
                            QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // SPECIALIZATION_H
