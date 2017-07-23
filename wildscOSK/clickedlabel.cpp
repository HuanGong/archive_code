#include "clickedlabel.h"
#include <QMouseEvent>


void ClickedLabel::mouseReleaseEvent(QMouseEvent *evt)
{
    emit clicked(this);
    evt->accept();
}

void ClickedLabel::mousePressEvent(QMouseEvent *lpEvent)
{
    lpEvent->accept();
}

void ClickedLabel::mouseMoveEvent(QMouseEvent *lpEvent)
{
    lpEvent->accept();
}
