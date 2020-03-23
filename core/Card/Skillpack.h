#ifndef SKILLPACK_H
#define SKILLPACK_H

#include <QObject>

class Skillpack : public QObject
{
    Q_OBJECT
public:
    explicit Skillpack(QObject *parent = nullptr);

    QString name() const;
    QStringList specializations() const;

    bool hasSpecialization(const QString &specialization) const;

signals:

public slots:
    void setName(const QString &name);
    void setSpecializations(const QStringList &specializations);

private:
    QString m_name;
    QStringList m_specializations;
};

#endif // SKILLPACK_H
