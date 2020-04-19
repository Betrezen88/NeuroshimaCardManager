#ifndef TRICKWRAPPER_H
#define TRICKWRAPPER_H

#include <QObject>

class TrickData;

class TrickWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QString action READ action CONSTANT)

public:
    explicit TrickWrapper(QObject *parent = nullptr);
    explicit TrickWrapper(TrickData *trickData, QObject *parent = nullptr);

    QString name() const;
    QString description() const;
    QString action() const;

private:
    TrickData *m_pTrickData{nullptr};
};

#endif // TRICKWRAPPER_H
