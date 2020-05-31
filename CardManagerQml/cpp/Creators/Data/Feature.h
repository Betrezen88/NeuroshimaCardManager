#ifndef FEATURE_H
#define FEATURE_H

#include <QObject>

class Feature : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)

public:
    explicit Feature(QObject *parent = nullptr);
    explicit Feature(const QString &name,
                     const QString &description,
                     QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // FEATURE_H
