#ifndef ORIGINDATA_H
#define ORIGINDATA_H

#include <QString>

class OriginData
{
public:
    OriginData(const QString &name,
               const QString &description);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // ORIGINDATA_H
