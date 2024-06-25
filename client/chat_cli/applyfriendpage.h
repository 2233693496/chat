#ifndef APPLYFRIENDPAGE_H
#define APPLYFRIENDPAGE_H

#include <QWidget>

namespace Ui {
class ApplyFriendPage;
}

class ApplyFriendPage : public QWidget
{
    Q_OBJECT

public:
    explicit ApplyFriendPage(QWidget *parent = nullptr);
    ~ApplyFriendPage();
protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::ApplyFriendPage *ui;
};

#endif // APPLYFRIENDPAGE_H
