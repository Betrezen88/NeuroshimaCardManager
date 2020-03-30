#ifndef DISEASE_H
#define DISEASE_H

#include <QObject>

class Disease : public QObject
{
    Q_OBJECT
public:
    explicit Disease(const QString &name,
                     const QString &description,
                     QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // DISEASE_H
