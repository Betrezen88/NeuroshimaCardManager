#ifndef ORIGIN_H
#define ORIGIN_H

#include <QObject>
#include <QString>

class Origin : public QObject
{
    Q_OBJECT
public:
    explicit Origin(QObject *parent = nullptr);

    QString name() const;

signals:

private:
    QString m_name;
};

#endif // ORIGIN_H
