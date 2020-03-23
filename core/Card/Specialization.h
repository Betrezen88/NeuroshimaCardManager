#ifndef SPECIALIZATION_H
#define SPECIALIZATION_H

#include <QObject>

class Specialization : public QObject
{
    Q_OBJECT
public:
    explicit Specialization(QObject *parent = nullptr);

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

#endif // SPECIALIZATION_H
