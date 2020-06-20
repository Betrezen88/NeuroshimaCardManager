#ifndef HERODATA_H
#define HERODATA_H

#include <QQmlListProperty>

#include "../../../Card/Data.h"

#include "core_global.h"

class Feature;

class CORE_EXPORT HeroData : public Data
{
    Q_OBJECT
    Q_PROPERTY(QString image READ image CONSTANT)
    Q_PROPERTY(QQmlListProperty<Feature> features READ features NOTIFY featuresChanged)

public:
    explicit HeroData(QObject *parent = nullptr);
    explicit HeroData(const QString &name,
                      const QString &description,
                      const QString &image,
                      QObject *parent = nullptr);

    QString image() const;

    void addFeature(Feature *feature);
    void removeFeature(const QString &name);

    QQmlListProperty<Feature> features();
    Feature* feature(const int &index) const;
    int featuresCount() const;

signals:
    void featuresChanged();

private:
    static Feature* feature(QQmlListProperty<Feature> *list, int index);
    static int featuresCount(QQmlListProperty<Feature> *list);

private:
    QString m_image;
    QVector<Feature*> m_features;
};

#endif // HERODATA_H
