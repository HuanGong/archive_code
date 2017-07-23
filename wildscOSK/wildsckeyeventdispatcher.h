#ifndef WILDSCKEYEVENTDISPATCHER_H
#define WILDSCKEYEVENTDISPATCHER_H

#include <QObject>

class WildscKeyEventDispatcher : public QObject
{
    Q_OBJECT
public:
    explicit WildscKeyEventDispatcher(QObject *parent = 0);
    bool IsLower;
signals:

public slots:
    void setFocusItem(QObject *focusItem);
    void sendKeyToFocusItem(const QString &keyText);

private:
    QObject * m_focusItem;
};

#endif // WILDSCKEYEVENTDISPATCHER_H
