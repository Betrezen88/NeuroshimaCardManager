#ifndef SPECIALIZATIONWRAPPER_H
#define SPECIALIZATIONWRAPPER_H

#include <QObject>

class SpecializationData;

class SpecializationWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)

public:
    explicit SpecializationWrapper(QObject *parent = nullptr);
    explicit SpecializationWrapper(SpecializationData *specializationData, QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    SpecializationData *m_pSpecializationData{nullptr};
};

#endif // SPECIALIZATIONWRAPPER_H
