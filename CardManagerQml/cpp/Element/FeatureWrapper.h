#ifndef FEATUREWRAPPER_H
#define FEATUREWRAPPER_H

#include <QObject>

class FeatureData;

class FeatureWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)

public:
    explicit FeatureWrapper(QObject *parent = nullptr);
    explicit FeatureWrapper(FeatureData *featureData, QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    FeatureData *m_pFeatureData{nullptr};
};

#endif // FEATUREWRAPPER_H
