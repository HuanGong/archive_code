#include "wildscinputcontextprivate.h"

wildscInputContextPrivate::wildscInputContextPrivate(): view(0)
{

}

wildscInputContextPrivate::~wildscInputContextPrivate()
{
    if (view) {
        delete view;
    }
}
