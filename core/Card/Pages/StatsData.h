#ifndef STATSDATA_H
#define STATSDATA_H

#include <QObject>

class PersonalData;

class StatsData : public QObject
{
    Q_OBJECT
public:
    explicit StatsData(QObject *parent = nullptr);

    PersonalData *personal() const;

signals:

public slots:
    void setPersonal(PersonalData *personal);

private:
    PersonalData *m_personal{nullptr};
};

#endif // STATSDATA_H
