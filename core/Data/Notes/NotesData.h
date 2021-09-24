#ifndef NOTESDATA_H
#define NOTESDATA_H

#include <QString>
#include <QVector>

#include "QuestionData.h"
#include "core_global.h"

struct CORE_EXPORT NotesData {
    QString biography;
    QString notes;
    QVector<QuestionData> questions;
};

#endif // NOTESDATA_H
