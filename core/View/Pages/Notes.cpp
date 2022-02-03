#include "Notes.h"

#include "../Notes/Question.h"

Notes::Notes(QObject *parent) : Page(Type::NOTES, parent)
{

}

Notes::Notes(const NotesData &data, QObject *parent)
    : Page(Type::NOTES, parent)
    , m_data( data )
{
    for ( QuestionData& question : m_data.questions )
        m_questions.append( new Question(&question, this) );
}

const QString &Notes::biography() const
{
    return m_data.biography;
}

void Notes::setBiography(const QString &newBiography)
{
    if (m_data.biography == newBiography)
        return;
    m_data.biography = newBiography;
    emit biographyChanged();
    emit wasModified();
}

const QString &Notes::notes() const
{
    return m_data.notes;
}

void Notes::setNotes(const QString &newNotes)
{
    if (m_data.notes == newNotes)
        return;
    m_data.notes = newNotes;
    emit notesChanged();
    emit wasModified();
}

const NotesData &Notes::data() const
{
    return m_data;
}

QQmlListProperty<Question> Notes::questions()
{
    return QQmlListProperty<Question>(this, this,
                                      &Notes::questionCount,
                                      &Notes::question);
}

int Notes::questionCount() const
{
    return m_questions.count();
}

Question *Notes::question(const int index) const
{
    if ( index < 0 || index > m_questions.count() )
        return nullptr;

    return m_questions.at(index);
}

int Notes::questionCount(QQmlListProperty<Question> *list)
{
    return reinterpret_cast<Notes*>(list->data)->questionCount();
}

Question *Notes::question(QQmlListProperty<Question> *list, int index)
{
    return reinterpret_cast<Notes*>(list->data)->question(index);
}
