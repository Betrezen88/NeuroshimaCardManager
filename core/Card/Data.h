#ifndef DATA_H
#define DATA_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT Data : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)

public:
    explicit Data(QObject *parent = nullptr);
    explicit Data(const QString &name,
                  const QString &description,
                  QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // DATA_H
