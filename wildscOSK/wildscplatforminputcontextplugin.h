#ifndef WILDSCPLATFORMINPUTCONTEXTPLUGIN_H
#define WILDSCPLATFORMINPUTCONTEXTPLUGIN_H

#include <qpa/qplatforminputcontextplugin_p.h>
#include "wildscVKB_global.h"


class WILDSCVIRTUALKEYBOARDSHARED_EXPORT wildscPlatformInputContextPlugin : public QPlatformInputContextPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QPlatformInputContextFactoryInterface" FILE "wildsc.json")

public:
    QPlatformInputContext *create(const QString&, const QStringList&);
};

#endif // WILDSCPLATFORMINPUTCONTEXTPLUGIN_H


/*
class MOCKUPVIRTUALKEYBOARDSHARED_EXPORT MockupPlatformInputContextPlugin: public QPlatformInputContextPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QPlatformInputContextFactoryInterface" FILE "mockup.json")

public:
    QPlatformInputContext *create(const QString&, const QStringList&);
};
*/
