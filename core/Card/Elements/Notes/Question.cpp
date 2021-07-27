#include "Question.h"

Question::Question(QObject *parent) : QObject(parent)
{

}

Question::Question(const QString &question,
                   const QString &subquestion,
                   const QString &answer,
                   QObject *parent)
    : QObject(parent)
    , m_question(question)
    , m_subquestion(subquestion)
    , m_answer(answer)
{

}

const QString &Question::question() const
{
    return m_question;
}

const QString &Question::subquestion() const
{
    return m_subquestion;
}

const QString &Question::answer() const
{
    return m_answer;
}

void Question::setAnswer(const QString &newAnswer)
{
    if ( m_answer == newAnswer )
        return;

    m_answer = newAnswer;
    emit answerChanged();
}
