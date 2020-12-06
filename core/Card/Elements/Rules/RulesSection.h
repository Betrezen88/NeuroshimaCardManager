#ifndef RULESSECTION_H
#define RULESSECTION_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT RulesSection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title CONSTANT)
    Q_PROPERTY(QList<QStringList> rows READ rows CONSTANT)

public:
    explicit RulesSection(QObject *parent = nullptr);
    explicit RulesSection(const QString& title,
                          const QList<QStringList>& rows,
                          QObject* parent = nullptr);


    QString title() const;
    QList<QStringList> rows() const;

private:
    QString m_title;
    QList<QStringList> m_rows;
};

#endif // RULESSECTION_H
