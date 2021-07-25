#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QCoreApplication>
#include <QObject>
#include <QSettings>

#include "core_global.h"

class CORE_EXPORT SettingsManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString defaultCardFolder READ defaultCardFolder WRITE setDefaultCardFolder NOTIFY defaultCardFolderChanged)
public:
    explicit SettingsManager(QObject *parent = nullptr);

    const QString defaultCardFolder() const;
    void setDefaultCardFolder(const QString &newDefaultCardFolder);

signals:
    void defaultCardFolderChanged();

private:
    QSettings m_settings;
    QStringList m_keys{ "defaultCardFolder" };
};

#endif // SETTINGSMANAGER_H
