#ifndef ITEM_H
#define ITEM_H

#include <QMap>
#include <QVariant>

#include "../../Data.h"
#include "core_global.h"

class CORE_EXPORT Item : public Data
{
    Q_OBJECT
    Q_PROPERTY(QString type READ type CONSTANT)
    Q_PROPERTY(int price READ price CONSTANT)
    Q_PROPERTY(int quantity
               READ quantity
               WRITE setQuantity
               NOTIFY quantityChanged)
    Q_PROPERTY(int requiredBody READ requiredBody CONSTANT)
    Q_PROPERTY(QStringList damage READ damage CONSTANT)
    Q_PROPERTY(int penetration READ penetration CONSTANT)
    Q_PROPERTY(int durability READ durability CONSTANT)
    Q_PROPERTY(int reputation READ reputation CONSTANT)
    Q_PROPERTY(QMap<QString, QVariant> dexBonus READ dexBonus CONSTANT)
    Q_PROPERTY(QString magazine READ magazine CONSTANT)
    Q_PROPERTY(QString bullet READ bullet CONSTANT)
    Q_PROPERTY(int rateOfFire READ rateOfFire CONSTANT)
    Q_PROPERTY(int ammunition READ ammunition CONSTANT)
    Q_PROPERTY(QList<QVariant> special READ special CONSTANT)
    Q_PROPERTY(QMap<QString, QVariant> locations READ locations CONSTANT)
    Q_PROPERTY(QList<QVariant> penalties READ penalties CONSTANT)
    Q_PROPERTY(QList<QVariant> features READ features CONSTANT)
    Q_PROPERTY(int armor READ armor CONSTANT)
    Q_PROPERTY(QString jam READ jam CONSTANT)

public:
    friend class ItemCreator;

    explicit Item(QObject* parent = nullptr);
    explicit Item(const QString& type,
                  const QString& name,
                  const QString& description,
                  const int& price,
                  const int& quantity,
                  const QMap<QString, QVariant>& stats = QMap<QString, QVariant>(),
                  QObject* parent = nullptr);

    int price() const;
    int quantity() const;
    QString type() const;
    int requiredBody() const;
    QStringList damage() const;
    int penetration() const;
    int durability() const;
    int reputation() const;
    QString magazine() const;
    QString bullet() const;
    int rateOfFire() const;
    int ammunition() const;
    QMap<QString, QVariant> dexBonus() const;
    QList<QVariant> special() const;
    QMap<QString, QVariant> locations() const;
    QList<QVariant> penalties() const;
    QList<QVariant> features() const;
    int armor() const;
    QString jam() const;

    Q_INVOKABLE bool hasStat(const QString& stat) const;

    void setStat(const QString& stat, const QVariant& value);

signals:
    void quantityChanged(int quantity);

public slots:
    void setQuantity(int quantity);

private:
    QString m_type;
    int m_price{0};
    int m_quantity{0};
    QMap<QString, QVariant> m_stats;
};

#endif // ITEM_H
