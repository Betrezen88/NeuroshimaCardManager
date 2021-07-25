#include "SettingsManager.h"

#include <QDir>
#include <QUrl>

SettingsManager::SettingsManager(QObject *parent) : QObject(parent)
{

}

const QString SettingsManager::defaultCardFolder() const
{
    return m_settings.value(m_keys.at(0), QDir::homePath()).toString();
}

void SettingsManager::setDefaultCardFolder(const QString &newDefaultCardFolder)
{
    const QUrl defaultCardFolderUrl{newDefaultCardFolder};
    const QString &defaultCardFolder = m_settings.value(m_keys.at(0), QDir::homePath()).toString();
    if (defaultCardFolder == defaultCardFolderUrl.toLocalFile())
        return;

    m_settings.setValue(m_keys.at(0), defaultCardFolderUrl.toLocalFile());
    emit defaultCardFolderChanged();
}
