#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <QObject>
#include "../../Data/Stats/ExperienceData.h"

#include "core_global.h"

class CORE_EXPORT Experience : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int gathered READ gathered NOTIFY gatheredChanged)
    Q_PROPERTY(int spended READ spended CONSTANT)
    Q_PROPERTY(int availble READ availble CONSTANT)

public:
    explicit Experience(QObject *parent = nullptr);
    explicit Experience(ExperienceData* data, QObject *parent = nullptr);

    int gathered() const;
    int spended() const;
    int availble() const;

signals:
    void gatheredChanged();

public slots:
    void addExperience(const int experience);

private:
    ExperienceData* m_data{nullptr};
};

#endif // EXPERIENCE_H
