#ifndef FINDSUCCESSDLG_H
#define FINDSUCCESSDLG_H

#include <QDialog>
#include <memory>
namespace Ui {
class FindSuccessDlg;
}

class FindSuccessDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FindSuccessDlg(QWidget *parent = nullptr);
    ~FindSuccessDlg();

private slots:
    void on_add_friend_btn_clicked();

private:
    Ui::FindSuccessDlg *ui;
    QWidget * _parent;
};

#endif // FINDSUCCESSDLG_H
