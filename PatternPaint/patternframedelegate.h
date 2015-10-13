#ifndef PATTERNFRAMEDELEGATE_H
#define PATTERNFRAMEDELEGATE_H

#include <QStyledItemDelegate>
#include "QPainter"
#include "QImage"

class PatternFrameDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    PatternFrameDelegate(QObject* parent = 0);

    QWidget * createEditor(QWidget *, const QStyleOptionViewItem &, const QModelIndex &) const { return NULL; }

    virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex & index ) const;
    QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const;
};


#endif // PATTERNFRAMEDELEGATE_H
