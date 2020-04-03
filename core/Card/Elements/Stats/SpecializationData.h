#ifndef SPECIALIZATIONDATA_H
#define SPECIALIZATIONDATA_H

#include <QObject>

class SpecializationData : public QObject
{
    Q_OBJECT
public:
    explicit SpecializationData(const QString &name,
                                const QString &description,
                                QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // SPECIALIZATIONDATA_H
