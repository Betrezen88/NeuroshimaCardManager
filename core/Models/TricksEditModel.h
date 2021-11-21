#ifndef TRICKSEDITMODEL_H
#define TRICKSEDITMODEL_H

#include <QObject>
#include <QQmlListProperty>

#include "../Edit/Stats/TrickEdit.h"

#include "core_global.h"

class StatsEditor;

class CORE_EXPORT TricksEditModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString sourceFile READ sourceFile WRITE setSourceFile NOTIFY sourceFileChanged)
    Q_PROPERTY(StatsEditor* stats READ stats WRITE setStats NOTIFY statsChanged)
    Q_PROPERTY(QQmlListProperty<TrickEdit> model READ model NOTIFY modelChanged)
    Q_PROPERTY(bool ascending READ ascending WRITE setAscending NOTIFY ascendingChanged)
    Q_PROPERTY(QString pattern READ pattern WRITE setPattern NOTIFY patternChanged)
    Q_PROPERTY(bool onlyAvailable READ onlyAvailable WRITE setOnlyAvailable NOTIFY onlyAvailableChanged)

public:
    explicit TricksEditModel(QObject *parent = nullptr);

    const QString &sourceFile() const;
    void setSourceFile(const QString &newSourceFile);

    StatsEditor *stats() const;
    void setStats(StatsEditor *newStats);

    QQmlListProperty<TrickEdit> model();
    int modelCount() const;
    TrickEdit* modelItem(const int index) const;

    bool ascending() const;
    void setAscending(bool newAscending);

    const QString &pattern() const;
    void setPattern(const QString &newPattern);

    bool onlyAvailable() const;
    void setOnlyAvailable(bool newOnlyAvailable);

signals:
    void sourceFileChanged(const QString& sourceFile);
    void statsChanged();
    void modelChanged();
    void ascendingChanged(const bool newAscending);
    void patternChanged(const QString& newPattern);
    void onlyAvailableChanged(const bool newOnlyAvailable);

public slots:
    void init(StatsEditor* statsEditor, const QString& sourceFile);
    void refreashTricks();

private slots:
    void showAvailable(const bool available);
    void filter(const QString& pattern);
    void loadTricks(const QString& file);
    void validateTricks();
    void sort(const bool ascending);
    void removeDoubles();

private:
    static int modelCount(QQmlListProperty<TrickEdit>* list);
    static TrickEdit* modelItem(QQmlListProperty<TrickEdit>* list, int index);

private:
    StatsEditor* m_pStatsEditor{nullptr};
    QVector<TrickEdit*> m_fullModel;
    QVector<TrickEdit*> m_model;
    QString m_sourceFile;
    bool m_ascending{true};
    QString m_pattern;
    bool m_onlyAvailable{false};
};

#endif // TRICKSEDITMODEL_H
