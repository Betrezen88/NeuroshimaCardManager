#ifndef HERODATA_H
#define HERODATA_H

#include "../../../Card/Data.h"

#include "core_global.h"

class Feature;

class CORE_EXPORT HeroData : public Data
{
    Q_OBJECT
public:
    explicit HeroData(QObject *parent = nullptr);
    explicit HeroData(const QString &name,
                      const QString &description,
                      const QString &image,
                      QObject *parent = nullptr);

    void addFeature(Feature *feature);
    void removeFeature(const QString &name);

private:
    QString m_image;
    QVector<Feature*> m_features;
};

#endif // HERODATA_H
