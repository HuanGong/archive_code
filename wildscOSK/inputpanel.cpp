#include "inputpanel.h"
#include "ui_inputpanel.h"
#include <QDebug>
#include <QDesktopWidget>


InputPanel::InputPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputPanel)
{
    ui->setupUi(this);

    keyEventDispatcher = NULL;
    m_MousePressed = false;
    ui->lineEdit_pinyin->hide();
    ui->columnView_character->hide();
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->resize(this->size().width(),this->size().height()-ui->lineEdit_pinyin->height()-ui->columnView_character->height());

    QString qss;
    QFile qssFile(":/skin/BW");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        this->setStyleSheet(qss);
        qssFile.close();
    }
    m_shiftModifier = false;
    m_symbolModifier = false;
    m_pinyinModifier = false;

    connect(ui->bt_key_q,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_w,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_e,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_r,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_t,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_y,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_u,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_i,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_o,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_p,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);

    connect(ui->bt_key_a,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_s,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_d,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_f,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_g,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_h,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_j,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_k,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_l,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_z,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_x,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_c,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_v,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_b,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_n,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_m,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_dot,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_comma,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);

    connect(ui->bt_key_space,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);
    connect(ui->bt_key_del,&ClickedLabel::clicked,this,&InputPanel::slot_LabelkeyClicked);

    QDesktopWidget* desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2, desktop->height() - this->height());
}

InputPanel::~InputPanel()
{
    delete ui;
}


void InputPanel::slot_LabelkeyClicked(ClickedLabel *bt_key)
{
    //ClickedLabel* btn= qobject_cast<ClickedLabel *>(sender());
    if(0 ==  bt_key)
        return ;
    if("bt_key_space" == bt_key->objectName())
    {
        this->keyEventDispatcher->sendKeyToFocusItem(" ");
        return;
    }

    if("bt_key_del" == bt_key->objectName())
    {
        this->keyEventDispatcher->sendKeyToFocusItem("\x7F");
        return ;
    }

    this->keyEventDispatcher->sendKeyToFocusItem(bt_key->text());
}

void InputPanel::on_bt_key_enter_clicked()
{
    if(m_pinyinModifier)
    {
        return;// do a pinyin matching and commit a chinese character
    }
    else
    {// just using for "\n"
        this->keyEventDispatcher->sendKeyToFocusItem("\n");
    }
}

void InputPanel::on_bt_key_lang_clicked()
{
    m_pinyinModifier = !m_pinyinModifier;
    QDesktopWidget* desktop = QApplication::desktop();
    if(m_pinyinModifier)
    {
        ui->lineEdit_pinyin->setVisible(true);
        ui->columnView_character->setVisible(true);
    }
    else
    {
        ui->lineEdit_pinyin->setVisible(false);
        ui->columnView_character->setVisible(false);
    }
    move((desktop->width() - this->width())/2, desktop->height() - this->height());
}


void InputPanel::on_bt_key_number_clicked()
{
    //m_symbolModifier ? m_symbolModifier = false : m_symbolModifier = true;
    m_symbolModifier = !m_symbolModifier;
    switch(m_symbolModifier)
    {
        case true:
            ui->bt_key_q->setText(tr("1"));
            ui->bt_key_w->setText(tr("2"));
            ui->bt_key_e->setText(tr("3"));
            ui->bt_key_r->setText(tr("4"));
            ui->bt_key_t->setText(tr("5"));
            ui->bt_key_y->setText(tr("6"));
            ui->bt_key_u->setText(tr("7"));
            ui->bt_key_i->setText(tr("8"));
            ui->bt_key_o->setText(tr("9"));
            ui->bt_key_p->setText(tr("0"));
            ui->bt_key_a->setText(tr("!"));
            ui->bt_key_s->setText(tr("@"));
            ui->bt_key_d->setText(tr("#"));
            ui->bt_key_f->setText(tr("$"));
            ui->bt_key_g->setText(tr("%"));
            ui->bt_key_h->setText(tr("&"));
            ui->bt_key_j->setText(tr("*"));
            ui->bt_key_k->setText(tr("?"));
            ui->bt_key_l->setText(tr("/"));
            ui->bt_key_z->setText(tr("_"));
            ui->bt_key_x->setText(tr("\""));
            ui->bt_key_c->setText(tr("'"));
            ui->bt_key_v->setText(tr("("));
            ui->bt_key_b->setText(tr(")"));
            ui->bt_key_n->setText(tr("-"));
            ui->bt_key_m->setText(tr("+"));
            ui->bt_key_space->setText(tr("数字"));
            ui->bt_key_number->setText(tr("返回"));

            break;
        case false:
            m_shiftModifier = !m_shiftModifier;
            on_bt_key_uper_clicked();
            ui->bt_key_space->setText(tr("字母"));
            ui->bt_key_number->setText(tr("123#"));
            break;
    }

}

void InputPanel::on_bt_key_uper_clicked()
{
    //m_shiftModifier ? m_shiftModifier = false : m_shiftModifier = true;
    m_shiftModifier = !m_shiftModifier;
    switch(m_shiftModifier)
    {
        case true:
            ui->bt_key_q->setText(tr("Q"));
            ui->bt_key_w->setText(tr("W"));
            ui->bt_key_e->setText(tr("E"));
            ui->bt_key_r->setText(tr("R"));
            ui->bt_key_t->setText(tr("T"));
            ui->bt_key_y->setText(tr("Y"));
            ui->bt_key_u->setText(tr("U"));
            ui->bt_key_i->setText(tr("I"));
            ui->bt_key_o->setText(tr("O"));
            ui->bt_key_p->setText(tr("O"));
            ui->bt_key_a->setText(tr("A"));
            ui->bt_key_s->setText(tr("S"));
            ui->bt_key_d->setText(tr("D"));
            ui->bt_key_f->setText(tr("F"));
            ui->bt_key_g->setText(tr("G"));
            ui->bt_key_h->setText(tr("H"));
            ui->bt_key_j->setText(tr("J"));
            ui->bt_key_k->setText(tr("K"));
            ui->bt_key_l->setText(tr("L"));
            ui->bt_key_z->setText(tr("Z"));
            ui->bt_key_x->setText(tr("X"));
            ui->bt_key_c->setText(tr("C"));
            ui->bt_key_v->setText(tr("V"));
            ui->bt_key_b->setText(tr("B"));
            ui->bt_key_n->setText(tr("N"));
            ui->bt_key_m->setText(tr("M"));
            break;
        case false:
            ui->bt_key_q->setText(tr("q"));
            ui->bt_key_w->setText(tr("w"));
            ui->bt_key_e->setText(tr("e"));
            ui->bt_key_r->setText(tr("r"));
            ui->bt_key_t->setText(tr("t"));
            ui->bt_key_y->setText(tr("y"));
            ui->bt_key_u->setText(tr("u"));
            ui->bt_key_i->setText(tr("i"));
            ui->bt_key_o->setText(tr("o"));
            ui->bt_key_p->setText(tr("p"));
            ui->bt_key_a->setText(tr("a"));
            ui->bt_key_s->setText(tr("s"));
            ui->bt_key_d->setText(tr("d"));
            ui->bt_key_f->setText(tr("f"));
            ui->bt_key_g->setText(tr("g"));
            ui->bt_key_h->setText(tr("h"));
            ui->bt_key_j->setText(tr("j"));
            ui->bt_key_k->setText(tr("k"));
            ui->bt_key_l->setText(tr("l"));
            ui->bt_key_z->setText(tr("z"));
            ui->bt_key_x->setText(tr("x"));
            ui->bt_key_c->setText(tr("c"));
            ui->bt_key_v->setText(tr("v"));
            ui->bt_key_b->setText(tr("b"));
            ui->bt_key_n->setText(tr("n"));
            ui->bt_key_m->setText(tr("m"));
            break;
    }

}

void InputPanel::on_bt_key_hide_clicked()
{
    this->hide();
}



void InputPanel::mousePressEvent(QMouseEvent *lpEvent)
{
    if (lpEvent->button() == Qt::LeftButton)
    {
        m_WindowPos = this->pos();
        m_MousePos = lpEvent->globalPos();
        this->m_MousePressed = true;
    }
    lpEvent->accept();
}

void InputPanel::mouseReleaseEvent(QMouseEvent *lpEvent)
{
    //__super::mouseReleaseEvent(lpEvent);
    if (lpEvent->button() == Qt::LeftButton)
    {
        this->m_MousePressed = false;
    }
    lpEvent->accept();
}

void InputPanel::mouseMoveEvent(QMouseEvent *lpEvent)
{
    if (m_MousePressed)
    {
        this->move(m_WindowPos + (lpEvent->globalPos() - m_MousePos));
    }
    lpEvent->accept();
}

