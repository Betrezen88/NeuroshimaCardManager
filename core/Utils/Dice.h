#ifndef DICE_H
#define DICE_H

#include <QRandomGenerator>

#include "core_global.h"

class CORE_EXPORT Dice
{
public:
    Dice(int max) : m_max(max) {
        m_pGenerator = QRandomGenerator::system();
    }

    ~Dice() {}

    int roll() const {
        return m_pGenerator->bounded(m_min, m_max+m_min);
    }

private:
    int m_min{1};
    int m_max{0};
    QRandomGenerator *m_pGenerator{nullptr};
};

#endif // DICE_H
