#ifndef PROFESSION_H
#define PROFESSION_H

#include <QObject>

#include "../../Data/Stats/ProfessionData.h"

#include "core_global.h"

class Feature;

class CORE_EXPORT Profession : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(Feature* feature READ feature CONSTANT)

public:
    explicit Profession(QObject *parent = nullptr);
    explicit Profession(ProfessionData* data, QObject *parent = nullptr);

    const QString &name() const;
    const QString &description() const;
    Feature *feature() const;

private:
    ProfessionData* m_data{nullptr};
    Feature *m_pFeature{nullptr};
};

#endif // PROFESSION_H
