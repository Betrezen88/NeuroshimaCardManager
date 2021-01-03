#ifndef LOCATION_H
#define LOCATION_H

#include <QObject>

class Location : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Type type READ type CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(int specialValue READ specialValue CONSTANT)
    Q_PROPERTY(QString specialDescription READ specialDescription CONSTANT)

public:
    enum class Type{
        HEAD,
        TORSO,
        LEFT_HAND,
        RIGHT_HAND,
        LEFT_LEG,
        RIGHT_LEG
    };
    Q_ENUM(Type)

    explicit Location(QObject *parent = nullptr);
    explicit Location(const Type& type,
                      const int& value,
                      const QPair<int, QString>& special,
                      QObject* parent = nullptr);

    static Type stringToType(const QString& type);

    Type type() const;
    int value() const;
    int specialValue() const;
    QString specialDescription() const;

private:
    Type m_type;
    int m_value;
    QPair<int, QString> m_special;
    int m_specialValue;
    QString m_specialDescription;
};

#endif // LOCATION_H
