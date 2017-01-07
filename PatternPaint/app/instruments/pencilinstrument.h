/*
 * This source file is part of EasyPaint.
 *
 * Copyright (c) 2012 EasyPaint <https://github.com/Gr1N/EasyPaint>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef PENCILINSTRUMENT_H
#define PENCILINSTRUMENT_H

#include "abstractinstrument.h"

#include <QObject>
#include <QPixmap>

/**
 * @brief Pencil instrument class.
 *
 */
class PencilInstrument : public CustomCursorInstrument
{
    Q_OBJECT

public:
    explicit PencilInstrument(QObject *parent = 0);

    void mousePressEvent(QMouseEvent *event, FrameEditor &, const QPoint &);
    void mouseMoveEvent(QMouseEvent *event, FrameEditor &, const QPoint &);
    void mouseReleaseEvent(QMouseEvent *event, FrameEditor &, const QPoint &);
    QCursor cursor() const
    {
        return Qt::ArrowCursor;
    }

protected:
    void paint(FrameEditor &);
};

#endif // PENCILINSTRUMENT_H