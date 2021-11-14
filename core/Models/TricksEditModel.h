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

public:
    explicit TricksEditModel(QObject *parent = nullptr);

    const QString &sourceFile() const;
    void setSourceFile(const QString &newSourceFile);

    StatsEditor *stats() const;
    void setStats(StatsEditor *newStats);

    QQmlListProperty<TrickEdit> model();
    int modelCount() const;
    TrickEdit* modelItem(const int index) const;

signals:
    void sourceFileChanged(const QString& sourceFile);
    void statsChanged();
    void modelChanged();

//public slots:
//    void filterAvailable();

private slots:
    void loadTricks(const QString& file);

private:
    static int modelCount(QQmlListProperty<TrickEdit>* list);
    static TrickEdit* modelItem(QQmlListProperty<TrickEdit>* list, int index);

private:
    StatsEditor* m_pStatsEditor{nullptr};
    QVector<TrickEdit*> m_hidden;
    QVector<TrickEdit*> m_model;
    QString m_sourceFile;
};

#endif // TRICKSEDITMODEL_H
