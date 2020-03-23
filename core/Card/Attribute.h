#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <QObject>

class Attribute : public QObject
{
    Q_OBJECT
public:
    explicit Attribute(QObject *parent = nullptr);

    QString name() const;
    int value() const;

signals:

public slots:
    void setName(const QString &name);
    void setValue(const int &value);

private:
    QString m_name;
    int m_value;
};

#endif // ATTRIBUTE_H
