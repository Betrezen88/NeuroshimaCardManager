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

void HeroData::addFeature(Feature *feature)
{
    m_features.push_back(feature);
}

void HeroData::removeFeature(const QString &name)
{
    for ( int i=0; i<m_features.count(); ++i  )
        if ( name == m_features.at(i)->name() ) {
            Feature *pFeatute = m_features.takeAt(i);
            delete pFeatute;
            break;
        }
}
