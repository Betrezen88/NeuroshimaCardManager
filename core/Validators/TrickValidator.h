#ifndef TRICKVALIDATOR_H
#define TRICKVALIDATOR_H

#include <QObject>

class StatsEditor;
class TrickEdit;
class Requirement;

class TrickValidator : public QObject
{
    Q_OBJECT
public:
    explicit TrickValidator(QObject *parent = nullptr);
    explicit TrickValidator(StatsEditor* statsEditor, QObject *parent = nullptr);

    void trickMeetsRequirements(TrickEdit* trick);

private:
    bool meetsAttributes(const QVector<Requirement*>& requirements);
    bool meetsSkills(const QVector<Requirement *> &requirements);

private:
    StatsEditor* m_pStatsEditor{nullptr};
};

#endif // TRICKVALIDATOR_H
