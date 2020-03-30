#ifndef PROFESSION_H
#define PROFESSION_H

#include <QObject>

class Profession : public QObject
{
    Q_OBJECT
public:
    explicit Profession(const QString &name,
                        const QString &description,
                        QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // PROFESSION_H
