#ifndef STATS_H
#define STATS_H

#include <QObject>

class Personal;

class Stats : public QObject
{
    Q_OBJECT
public:
    explicit Stats(QObject *parent = nullptr);

    Personal *personal() const;

signals:

public slots:
    void setPersonal(Personal *personal);

private:
    Personal *m_personal{nullptr};
};

#endif // STATS_H
