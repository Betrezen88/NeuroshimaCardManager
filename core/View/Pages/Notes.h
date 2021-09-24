#ifndef NOTES_H
#define NOTES_H

#include <QQmlListProperty>

#include "Page.h"

#include "../../Data/Notes/NotesData.h"

#include "core_global.h"

class Question;

class CORE_EXPORT Notes : public Page
{
    Q_OBJECT
    Q_PROPERTY(QString biography READ biography WRITE setBiography NOTIFY biographyChanged)
    Q_PROPERTY(QString notes READ notes WRITE setNotes NOTIFY notesChanged)
    Q_PROPERTY(QQmlListProperty<Question> questions READ questions CONSTANT)

public:
    explicit Notes(QObject *parent = nullptr);
    explicit Notes(const NotesData& data, QObject *parent = nullptr);

    const QString &biography() const;
    void setBiography(const QString &newBiography);

    const QString &notes() const;
    void setNotes(const QString &newNotes);

    const NotesData& data() const;

    QQmlListProperty<Question> questions();
    int questionCount() const;
    Question* question(const int index) const;

signals:
    void biographyChanged();
    void notesChanged();

private:
    static int questionCount(QQmlListProperty<Question> *list);
    static Question* question(QQmlListProperty<Question> *list, int index);

private:
    NotesData m_data;
    QVector<Question*> m_questions;
};

#endif // NOTES_H
