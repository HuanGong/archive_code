#ifndef WILDSCINPUTCONTEXT_H
#define WILDSCINPUTCONTEXT_H

#include <QRectF>
#include <qpa/qplatforminputcontext.h>
#include "wildsckeyeventdispatcher.h"
#include "wildscinputcontextprivate.h"

class WildscInputContext : public QPlatformInputContext
{
    Q_OBJECT
public:
    WildscInputContext();
    ~WildscInputContext();

    //retur true if plugin is enabled
    bool isValid() const;

    //this value will be available in QGuiApplication::inputMethod()->keyboardRectangle()
    QRectF keyboardRect() const;


    //show and hide invoked by Qt when editor gets focus
    void showInputPanel();
    void hideInputPanel();

    //this value will be available in QGuiApplication::inputMethod()->isVisible()
    bool isInputPanelVisible() const;

    //editor pointer
    void setFocusObject(QObject *object);
    QObject *Sender;

public:
    static wildscInputContextPrivate *d;
};

#endif // WILDSCINPUTCONTEXT_H
