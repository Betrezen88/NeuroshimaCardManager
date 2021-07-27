#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT Question : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString question READ question CONSTANT)
    Q_PROPERTY(QString subquestion READ subquestion CONSTANT)
    Q_PROPERTY(QString answer READ answer WRITE setAnswer NOTIFY answerChanged)

public:
    explicit Question(QObject *parent = nullptr);
    explicit Question(const QString& question,
                      const QString& subquestion,
                      const QString& answer,
                      QObject *parent = nullptr);

    const QString &question() const;
    const QString &subquestion() const;
    const QString &answer() const;
    void setAnswer(const QString &newAnswer);

signals:
    void answerChanged();

private:
    QString m_question;
    QString m_subquestion;
    QString m_answer;
};

#endif // QUESTION_H
