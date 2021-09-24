#ifndef WOUND_H
#define WOUND_H

#include <QObject>

#include "../../Data/Stats/WoundData.h"

#include "core_global.h"

class CORE_EXPORT Wound : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString location READ location CONSTANT)
    Q_PROPERTY(QString type READ type CONSTANT)
    Q_PROPERTY(int modifier READ modifier CONSTANT)

public:
    explicit Wound(QObject *parent = nullptr);
    explicit Wound(WoundData* data, QObject *parent = nullptr);

    const QString &location() const;
    const QString &type() const;
    int modifier() const;

    const WoundData *data() const;

private:
    WoundData* m_data{nullptr};
};

#endif // WOUND_H
