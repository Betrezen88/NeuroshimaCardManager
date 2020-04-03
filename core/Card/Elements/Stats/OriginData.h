#ifndef ORIGINDATA_H
#define ORIGINDATA_H

#include <QObject>

class OriginData : public QObject
{
    Q_OBJECT
public:
    explicit OriginData(const QString &name,
                        const QString &description,
                        QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // ORIGINDATA_H
