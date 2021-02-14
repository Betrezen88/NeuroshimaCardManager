#ifndef WOUND_H
#define WOUND_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT Wound : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString location READ location CONSTANT)
    Q_PROPERTY(QString type READ type CONSTANT)
    Q_PROPERTY(int modifier READ modifier WRITE setModifier NOTIFY modifierChanged)

public:
    explicit Wound(QObject *parent = nullptr);
    explicit Wound(const QString& location,
                   const QString& type,
                   const int& modifier,
                   QObject* parent = nullptr);

    QString location() const;
    QString type() const;
    int modifier() const;

public slots:
    void setModifier(int modifier);

signals:
    void modifierChanged(int modifier);

private:
    QString m_location;
    QString m_type;
    int m_modifier;
};

#endif // WOUND_H
