#include "wildscInputcontext.h"
#include <QDebug>
#include <QEvent>
#include <QGuiApplication>
#include "inputpanel.h"
//#include "pinyininputmethod.h"

wildscInputContextPrivate *WildscInputContext::d = new wildscInputContextPrivate();

WildscInputContext::WildscInputContext() : QPlatformInputContext()
{
    // here do something input method config
    ;
}

WildscInputContext::~WildscInputContext()
{

}

bool WildscInputContext::isValid() const
{
    return true;
}


QRectF WildscInputContext::keyboardRect() const
{
    return d->view ? d->view->geometry() : QRectF();
}


void WildscInputContext::showInputPanel()
{
    // show the inputmethod panel
    if (!d->view)
    {
        //d->view = new InputPanel();
        d->view = new InputPanel();
        // let the dispatcher have the access to send key event
        d->view->keyEventDispatcher = &d->keyEventDispatcher;
/*      chinese character input initialize
        d->view->engine()->rootContext()->setContextProperty("pinyinInput", pinyinInput);
        pinyinInput->Update();
        */

        d->view->setWindowFlags(d->view->windowFlags()| Qt::Tool | Qt::FramelessWindowHint |
                                Qt::WindowStaysOnTopHint | Qt::WindowDoesNotAcceptFocus);
    }

    d->view->show();
    QPlatformInputContext::showInputPanel();

}


void WildscInputContext::hideInputPanel()
{
    if(d->view)
        d->view->hide();

}

bool WildscInputContext::isInputPanelVisible() const
{
    return (d->view) ? d->view->isVisible() : false;
}


void WildscInputContext::setFocusObject(QObject *object)
{
    d->keyEventDispatcher.setFocusItem(object);
}


