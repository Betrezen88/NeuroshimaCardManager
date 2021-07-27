#ifndef NOTES_H
#define NOTES_H

#include <QObject>
#include <QQmlListProperty>

#include "Page.h"
#include "../Elements/Notes/Question.h"

#include "core_global.h"

class CORE_EXPORT Notes : public Page
{
    Q_OBJECT
    Q_PROPERTY(QString biography READ biography WRITE setBiography NOTIFY biographyChanged)
    Q_PROPERTY(QString notes READ notes WRITE setNotes NOTIFY notesChanged)
    Q_PROPERTY(QQmlListProperty<Question> questions READ questions CONSTANT)

public:
    explicit Notes(QObject *parent = nullptr);
    explicit Notes(const QString& biography,
                   const QString& notes,
                   const QVector<Question*> &questions,
                   QObject *parent = nullptr);

    const QString &biography() const;
    void setBiography(const QString &newBiography);

    const QString &notes() const;
    void setNotes(const QString &newNotes);

    const QVector<Question*> &questions() const;
    QQmlListProperty<Question> questions();
    int questionsCount() const;
    Question* question(const int index);

signals:
    void biographyChanged();
    void notesChanged();

private:
    static int questionsCount(QQmlListProperty<Question> *list);
    static Question *question(QQmlListProperty<Question> *list, const int index);

private:
    QString m_biography;
    QString m_notes;
    QVector<Question*> m_questions;
};

#endif // NOTES_H
