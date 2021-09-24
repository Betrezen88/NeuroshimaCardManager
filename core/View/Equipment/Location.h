#ifndef LOCATION_H
#define LOCATION_H

#include <QObject>

#include "../../Data/Equipment/LocationData.h"

#include "core_global.h"

class CORE_EXPORT Location : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int armor READ armor CONSTANT)
    Q_PROPERTY(int cutting READ cutting CONSTANT)

public:
    explicit Location(QObject *parent = nullptr);
    explicit Location(LocationData* data, QObject *parent = nullptr);

    const QString &name() const;
    int armor() const;
    int cutting() const;

private:
    LocationData* m_data{nullptr};
};

#endif // LOCATION_H
