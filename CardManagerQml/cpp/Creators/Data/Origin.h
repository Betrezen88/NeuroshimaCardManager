#ifndef ORIGIN_H
#define ORIGIN_H

#include <QObject>
#include <QQmlListProperty>

class Feature;

class Origin : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QString attribute READ attribute CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(QString image READ image CONSTANT)
    Q_PROPERTY(QQmlListProperty<Feature> features READ features NOTIFY featuresChanged)

public:
    explicit Origin(QObject *parent = nullptr);
    explicit Origin(const QString &name,
                    const QString &description,
                    const QString &attribute,
                    const int &value,
                    const QString &image,
                    QObject *parent = nullptr);

    QString name() const;
    QString description() const;
    QString attribute() const;
    int value() const;
    QString image() const;

    QQmlListProperty<Feature> features();
    void appendFeature(Feature *);
    int featuresCount() const;
    Feature *feature(int) const;
    void clearFeatures();

signals:
    void featuresChanged();

private:
    static void appendFeature(QQmlListProperty<Feature> *, Feature *);
    static int featuresCount(QQmlListProperty<Feature> *);
    static Feature *feature(QQmlListProperty<Feature> *, int);
    static void clearFeatures(QQmlListProperty<Feature> *);

private:
    QString m_name;
    QString m_description;
    QPair<QString, int> m_bonus;
    QString m_image;
    QList<Feature*> m_features;
};

#endif // ORIGIN_H
