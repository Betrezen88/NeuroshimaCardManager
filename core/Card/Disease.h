#ifndef DISEASE_H
#define DISEASE_H

#include <QObject>

class Disease : public QObject
{
    Q_OBJECT
public:
    explicit Disease(QObject *parent = nullptr);

    QString name() const;

signals:

private:
    QString m_name;
};

#endif // DISEASE_H
