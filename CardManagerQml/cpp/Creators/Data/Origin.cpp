#include "Origin.h"

Origin::Origin(QObject *parent) : QObject(parent)
{

}

Origin::Origin(const QString &name,
               const QString &description,
               const QString &attribute,
               const int &value,
               const QString &image,
               QObject *parent)
    : QObject(parent),
      m_name(name),
      m_description(description),
      m_bonus(attribute, value),
      m_image(image)
{

}

QString Origin::name() const
{
    return m_name;
}

QString Origin::description() const
{
    return m_description;
}

QString Origin::attribute() const
{
    return m_bonus.first;
}

int Origin::value() const
{
    return m_bonus.second;
}

QString Origin::image() const
{
    return m_image;
}

QQmlListProperty<Feature> Origin::features()
{
    return QQmlListProperty<Feature>(this, this,
                                     &Origin::appendFeature,
                                     &Origin::featuresCount,
                                     &Origin::feature,
                                     &Origin::clearFeatures);
}

void Origin::appendFeature(Feature *feature)
{
    m_features.push_back(feature);
}

int Origin::featuresCount() const
{
    return m_features.count();
}

Feature *Origin::feature(int index) const
{
    return m_features.at(index);
}

void Origin::clearFeatures()
{
    m_features.clear();
}

void Origin::appendFeature(QQmlListProperty<Feature> *list, Feature *feature)
{
    reinterpret_cast<Origin*>(list->data)->appendFeature(feature);
}

int Origin::featuresCount(QQmlListProperty<Feature> *list)
{
    return reinterpret_cast<Origin*>(list->data)->featuresCount();
}

Feature *Origin::feature(QQmlListProperty<Feature> *list, int index)
{
    return reinterpret_cast<Origin*>(list->data)->feature(index);
}

void Origin::clearFeatures(QQmlListProperty<Feature> *list)
{
    reinterpret_cast<Origin*>(list->data)->clearFeatures();
}
