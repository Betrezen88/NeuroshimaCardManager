#ifndef SPECIAL_H
#define SPECIAL_H

#include <QObject>

#include "../../Data/Equipment/SpecialData.h"

#include "core_global.h"

class CORE_EXPORT Special : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)

public:
    explicit Special(QObject *parent = nullptr);
    explicit Special(SpecialData* data, QObject *parent = nullptr);

    const QString &name() const;
    const QString &description() const;

private:
    SpecialData* m_data{nullptr};
};

#endif // SPECIAL_H
