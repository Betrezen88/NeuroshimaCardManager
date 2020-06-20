#include "HeroData.h"
#include "Feature.h"

HeroData::HeroData(QObject *parent) : Data(parent)
{

}

HeroData::HeroData(const QString &name,
                   const QString &description,
                   const QString &image,
                   QObject *parent)
    : Data(name, description, parent),
      m_image(image)
{

}

QString HeroData::image() const
{
    return m_image;
}

void HeroData::addFeature(Feature *feature)
{
    m_features.push_back(feature);
    emit featuresChanged();
}

void HeroData::removeFeature(const QString &name)
{
    for ( int i=0; i<m_features.count(); ++i  )
        if ( name == m_features.at(i)->name() ) {
            Feature *pFeatute = m_features.takeAt(i);
            delete pFeatute;
            emit featuresChanged();
            break;
        }
}

QQmlListProperty<Feature> HeroData::features()
{
    return QQmlListProperty<Feature>(reinterpret_cast<Data*>(this), this,
                                     &HeroData::featuresCount,
                                     &HeroData::feature);
}

Feature *HeroData::feature(const int &index) const
{
    return m_features.at(index);
}

int HeroData::featuresCount() const
{
    return m_features.count();
}

Feature *HeroData::feature(QQmlListProperty<Feature> *list, int index)
{
    return reinterpret_cast<HeroData*>(list->data)->feature(index);
}

int HeroData::featuresCount(QQmlListProperty<Feature> *list)
{
    return reinterpret_cast<HeroData*>(list->data)->featuresCount();
}
