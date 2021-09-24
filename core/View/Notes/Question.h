#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>

#include "../../Data/Notes/QuestionData.h"

#include "core_global.h"

class CORE_EXPORT Question : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString question READ question CONSTANT)
    Q_PROPERTY(QString subquestion READ subquestion CONSTANT)
    Q_PROPERTY(QString answer READ answer WRITE setAnswer NOTIFY answerChanged)

public:
    explicit Question(QObject *parent = nullptr);
    explicit Question(QuestionData* data, QObject* parent = nullptr);

    const QString &question() const;
    const QString &subquestion() const;
    const QString &answer() const;
    void setAnswer(const QString &newAnswer);

signals:
    void answerChanged();

private:
    QuestionData* m_data{nullptr};
};

#endif // QUESTION_H
