#ifndef PROFESSIONWRAPPER_H
#define PROFESSIONWRAPPER_H

#include <QObject>

class ProfessionData;

class ProfessionWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)

public:
    explicit ProfessionWrapper(QObject *parent = nullptr);
    explicit ProfessionWrapper(ProfessionData *professionData, QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    ProfessionData *m_pProfessionData{nullptr};
};

#endif // PROFESSIONWRAPPER_H
