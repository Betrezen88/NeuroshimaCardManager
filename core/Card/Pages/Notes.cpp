#include "Notes.h"

Notes::Notes(QObject *parent) : Page(Page::Type::NOTES, parent)
{

}

Notes::Notes(const QString &biography,
             const QString &notes,
             const QVector<Question *> &questions,
             QObject *parent)
    : Page(Page::Type::NOTES, parent)
    , m_biography(biography)
    , m_notes(notes)
    , m_questions(questions)
{

}

const QString &Notes::biography() const
{
    return m_biography;
}

void Notes::setBiography(const QString &newBiography)
{
    if (m_biography == newBiography)
        return;
    m_biography = newBiography;
    emit biographyChanged();
}

const QString &Notes::notes() const
{
    return m_notes;
}

void Notes::setNotes(const QString &newNotes)
{
    if (m_notes == newNotes)
        return;
    m_notes = newNotes;
    emit notesChanged();
}

const QVector<Question *> &Notes::questions() const
{
    return m_questions;
}

QQmlListProperty<Question> Notes::questions()
{
    return QQmlListProperty<Question>(this, this,
                                      &Notes::questionsCount,
                                      &Notes::question);
}

int Notes::questionsCount() const
{
    return m_questions.count();
}

Question *Notes::question(const int index)
{
    return m_questions.at(index);
}

int Notes::questionsCount(QQmlListProperty<Question> *list)
{
    return reinterpret_cast<Notes*>(list->data)->questionsCount();
}

Question* Notes::question(QQmlListProperty<Question> *list, const int index)
{
    return reinterpret_cast<Notes*>(list->data)->question(index);
}
