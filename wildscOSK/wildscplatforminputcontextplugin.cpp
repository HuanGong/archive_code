#include "wildscplatforminputcontextplugin.h"
#include "wildscInputcontext.h"

QPlatformInputContext *wildscPlatformInputContextPlugin::create(const QString& system, const QStringList& paramList)
{
    Q_UNUSED(paramList);

    if (system.compare(system, QStringLiteral("wildsc"), Qt::CaseInsensitive) == 0)
        return new WildscInputContext;
    return 0;
}
