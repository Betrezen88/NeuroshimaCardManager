#include "TricksSortFilterModel.h"
#include "../../../Card/Elements/Stats/Trick.h"
#include "../../../Validators/TrickValidator.h"

TricksSortFilterModel::TricksSortFilterModel(QObject *parent)
    : QObject(parent),
      m_pattern(""),
      m_order(Qt::AscendingOrder),
      m_caseSensitive(false)
{
    connect(this, &TricksSortFilterModel::patternChanged,
            this, &TricksSortFilterModel::filter);
    connect(this, &TricksSortFilterModel::orderChanged,
            this, &TricksSortFilterModel::sort);
    connect(this, &TricksSortFilterModel::caseSensitiveChanged,
            [this](){ filter(m_pattern); });
}

QQmlListProperty<Trick> TricksSortFilterModel::tricks()
{
    return QQmlListProperty<Trick>(this, m_tricks);
}

void TricksSortFilterModel::addTrick(Trick *trick)
{
    TrickValidator validator;
    m_sourceModel.push_back(trick);

    if ( containsPattern(trick, m_pattern, m_caseSensitive) ) {
        m_tricks.append(trick);
        emit tricksChanged();
    }
}

Trick *TricksSortFilterModel::trick(const int &index) const
{
    return m_tricks.at(index);
}

int TricksSortFilterModel::tricksCount() const
{
    return m_tricks.count();
}

QString TricksSortFilterModel::pattern() const
{
    return m_pattern;
}

Qt::SortOrder TricksSortFilterModel::order() const
{
    return m_order;
}

bool TricksSortFilterModel::caseSensitive() const
{
    return m_caseSensitive;
}

void TricksSortFilterModel::removeTrick(const int &index)
{
    Trick* pTrick = m_sourceModel.at(index);

    if ( m_tricks.contains(pTrick) )
        m_tricks.removeOne(pTrick);

    m_sourceModel.removeOne(pTrick);
    delete pTrick;
}

Trick* TricksSortFilterModel::findTrickSource(const QString &trickName)
{
    for ( Trick* trick: m_sourceModel ) {
        if ( trick->name() == trickName )
            return trick;
    }
    return nullptr;
}

void TricksSortFilterModel::setPattern(const QString &pattern)
{
    if (m_pattern == pattern)
        return;

    m_pattern = pattern;
    emit patternChanged(m_pattern);
}

void TricksSortFilterModel::setOrder(const Qt::SortOrder &order)
{
    if (m_order == order)
        return;

    m_order = order;
    emit orderChanged(m_order);
}

void TricksSortFilterModel::setCaseSensitive(bool caseSensitive)
{
    if (m_caseSensitive == caseSensitive)
        return;

    m_caseSensitive = caseSensitive;
    emit caseSensitiveChanged(m_caseSensitive);
}

void TricksSortFilterModel::sort(const Qt::SortOrder &order)
{
    auto lessThan = [order](Trick* left, Trick* right){
        if ( Qt::AscendingOrder == order )
            return left->name() < right->name();
        return left->name() > right->name();
    };
    std::sort(m_tricks.begin(), m_tricks.end(), lessThan);
    emit tricksChanged();
}

void TricksSortFilterModel::filter(const QString &pattern)
{
    m_tricks.clear();
    for ( Trick* pTrick: m_sourceModel ) {
        if ( containsPattern(pTrick, pattern, m_caseSensitive) )
            m_tricks.append(pTrick);
    }
    sort(m_order);
}

bool TricksSortFilterModel::containsPattern(Trick *trick,
                                            const QString &pattern,
                                            const bool &caseSensitive)
{
    if ( caseSensitive )
        return trick->name().contains(pattern);
    return trick->name().toUpper().contains(pattern.toUpper());
}
