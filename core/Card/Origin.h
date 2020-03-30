#ifndef ORIGIN_H
#define ORIGIN_H

#include <QObject>

class Origin : public QObject
{
    Q_OBJECT
public:
    explicit Origin(const QString &name,
                    const QString &description,
                    QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // ORIGIN_H
