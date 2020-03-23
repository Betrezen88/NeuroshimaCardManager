#ifndef PROFESSION_H
#define PROFESSION_H

#include <QObject>

class Profession : public QObject
{
    Q_OBJECT
public:
    explicit Profession(QObject *parent = nullptr);

    QString name() const;

signals:

private:
    QString m_name;
};

#endif // PROFESSION_H
