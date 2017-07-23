#include "wildsckeyeventdispatcher.h"
#include <QInputMethodEvent>
#include <QCoreApplication>


WildscKeyEventDispatcher::WildscKeyEventDispatcher(QObject *parent) :
    QObject(parent),m_focusItem(0)
{
}

void WildscKeyEventDispatcher::setFocusItem(QObject *focusItem)
{
    m_focusItem = focusItem;
}

void WildscKeyEventDispatcher::sendKeyToFocusItem(const QString &keyText)
{
    if (!m_focusItem)
        return;

    QInputMethodEvent ev;
    if (keyText == QString("\x7F"))
    {
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyPress,Qt::Key_Backspace, Qt::NoModifier));
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyRelease, Qt::Key_Backspace, Qt::NoModifier));
        return;//ev.setCommitString("",-1,1);
    }
    else if (keyText == QString("\n"))
    {
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier));
        QCoreApplication::sendEvent(m_focusItem, new QKeyEvent(QEvent::KeyRelease, Qt::Key_Enter, Qt::NoModifier));
    }
    else
    {
        ev.setCommitString(keyText);
    }
    QCoreApplication::sendEvent(m_focusItem, &ev);
}
