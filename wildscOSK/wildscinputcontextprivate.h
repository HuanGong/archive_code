#ifndef WILDSCINPUTCONTEXTPRIVATE_H
#define WILDSCINPUTCONTEXTPRIVATE_H
#include "wildsckeyeventdispatcher.h"
#include "inputpanel.h"
class wildscInputContextPrivate
{
public:
    wildscInputContextPrivate();
    ~wildscInputContextPrivate();

    // input panel ui here
    InputPanel *view;
    WildscKeyEventDispatcher keyEventDispatcher;
};

#endif // WILDSCINPUTCONTEXTPRIVATE_H
