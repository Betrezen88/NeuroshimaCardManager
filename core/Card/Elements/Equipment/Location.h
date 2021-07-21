#ifndef LOCATION_H
#define LOCATION_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT Location : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString location READ location CONSTANT)
    Q_PROPERTY(int armor READ armor CONSTANT)
    Q_PROPERTY(int cutting READ cutting CONSTANT)

public:
    explicit Location(QObject *parent = nullptr);
    explicit Location(const QString& location,
                      const int& armor,
                      const int& cutting = 0,
                      QObject* parent = nullptr);

    QString location() const;
    int armor() const;
    int cutting() const;
    static QStringList locations();

private:
    QString m_location{};
    int m_armor{0};
    int m_cutting{0};
};

#endif // LOCATION_H
