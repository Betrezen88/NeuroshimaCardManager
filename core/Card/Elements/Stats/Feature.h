#ifndef FEATURE_H
#define FEATURE_H

#include <QObject>

class Feature : public QObject
{
    Q_OBJECT
public:
    explicit Feature(QObject *parent = nullptr);

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

#endif // FEATURE_H
