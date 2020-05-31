#ifndef HEROCREATORDATA_H
#define HEROCREATORDATA_H

#include <QObject>
#include <QQmlListProperty>

class Origin;
class Feature;

class HeroCreatorData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Origin> origins READ origins NOTIFY originsChanged)

public:
    explicit HeroCreatorData(QObject *parent = nullptr);

    QQmlListProperty<Origin> origins();
    void appendOrigin(Origin*);
    int originsCount() const;
    Origin *origin(int) const;
    void clearOrigins();

signals:
    void originsChanged();
    void errorMessage(const QString &message);

private:
    static void appendOrigin(QQmlListProperty<Origin>*, Origin*);
    static int originsCount(QQmlListProperty<Origin>*);
    static Origin *origin(QQmlListProperty<Origin>*, int);
    static void clearOrigins(QQmlListProperty<Origin>*);

private:
    QList<Origin*> m_origins;
};

#endif // HEROCREATORDATA_H
