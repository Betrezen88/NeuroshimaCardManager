#ifndef PROFESSIONDATA_H
#define PROFESSIONDATA_H

#include <QObject>

class ProfessionData : public QObject
{
    Q_OBJECT
public:
    explicit ProfessionData(const QString &name,
                            const QString &description,
                            QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // PROFESSIONDATA_H
