#include "Question.h"

Question::Question(QObject *parent) : QObject(parent)
{

}

Question::Question(QuestionData *data, QObject *parent)
    : QObject(parent)
    , m_data( data )
{

}

const QString &Question::question() const
{
    if ( m_data )
        return m_data->question;
    return std::move(QString());
}

const QString &Question::subquestion() const
{
    if ( m_data )
        return m_data->subquestion;
    return std::move(QString());
}

const QString &Question::answer() const
{
    if ( m_data )
        return m_data->answer;
    return std::move(QString());
}

void Question::setAnswer(const QString &newAnswer)
{
    if (m_data->answer == newAnswer)
        return;
    m_data->answer = newAnswer;
    emit answerChanged();
}
