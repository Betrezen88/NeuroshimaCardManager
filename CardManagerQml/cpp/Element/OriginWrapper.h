#ifndef ORIGINWRAPPER_H
#define ORIGINWRAPPER_H

#include <QObject>

class OriginData;

class OriginWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)

public:
    explicit OriginWrapper(QObject *parent = nullptr);
    explicit OriginWrapper(OriginData *originData, QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    OriginData *m_pOriginData{nullptr};
};

#endif // ORIGINWRAPPER_H
