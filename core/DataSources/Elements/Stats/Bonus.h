#ifndef BONUS_H
#define BONUS_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT Bonus : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Type type READ type CONSTANT)
    Q_PROPERTY(QStringList list READ list CONSTANT)

public:
    enum class Type {
        SKILLPACK,
        FEATURE,
        TRICK,
        SKILLS,
        PET,
        SKILLPOINTS,
        SKILLPACKPT,
        HEALTH,
        CONNECTIONS,
        FAME,
        REPUTATION,
        TOTEM
    };
    Q_ENUM(Type);

    explicit Bonus(QObject *parent = nullptr);
    explicit Bonus(const Type &type,
                   const QString &name,
                   const int &value,
                   const int &price,
                   const QStringList &list,
                   QObject *parent = nullptr);

    Type type() const;
    QString name() const;
    int value() const;
    int price() const;
    QStringList list() const;

signals:
    void nameChanged(Bonus* bonus,
                     const QString& oldName,
                     const QString& newName);

public slots:
    void setName(const QString& name);

private:
    Type m_type;
    QString m_name;
    int m_value;
    int m_price;
    QStringList m_list;
};

#endif // BONUS_H
