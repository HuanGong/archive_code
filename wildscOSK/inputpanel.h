#ifndef INPUTPANEL_H
#define INPUTPANEL_H
#include "wildsckeyeventdispatcher.h"
#include <qpa/qplatforminputcontext.h>

#include <QDialog>
#include <QPoint>
#include <QMouseEvent>
#include "clickedlabel.h"


namespace Ui {
class InputPanel;
}

class InputPanel : public QDialog
{
    Q_OBJECT

public:
    explicit InputPanel(QWidget *parent = 0);
    ~InputPanel();

    WildscKeyEventDispatcher *keyEventDispatcher;
private slots:

    void on_bt_key_number_clicked();

    void on_bt_key_uper_clicked();

    void on_bt_key_hide_clicked();

    void slot_keyClicked();
    void slot_LabelkeyClicked(ClickedLabel *bt_key=0);
    void on_bt_key_enter_clicked();

    void on_bt_key_lang_clicked();

private:
    Ui::InputPanel *ui;



    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

    bool	m_MousePressed;
    QPoint	m_MousePos;
    QPoint	m_WindowPos;

    bool m_shiftModifier;
    bool m_symbolModifier;
    bool m_pinyinModifier;  // zh / english switcher
};

#endif // INPUTPANEL_H
