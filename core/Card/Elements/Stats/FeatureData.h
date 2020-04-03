#ifndef FEATUREDATA_H
#define FEATUREDATA_H

#include <QObject>

class FeatureData : public QObject
{
    Q_OBJECT
public:
    explicit FeatureData(QObject *parent = nullptr);

    QString name() const;
    QString description() const;

signals:

public slots:
    void setName(const QString &name);
    void setDescription(const QString &description);

private:
    QString m_name;
    QString m_description;
};

#endif // FEATUREDATA_H
