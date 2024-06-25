#ifndef APPLYFRIENDITEM_H
#define APPLYFRIENDITEM_H

#include <QWidget>
#include <listitembase.h>

namespace Ui {
class ApplyFriendItem;
}

class ApplyFriendItem : public ListItemBase
{
    Q_OBJECT

public:
    explicit ApplyFriendItem(QWidget *parent = nullptr);
    ~ApplyFriendItem();
    void SetInfo(QString name, QString head, QString msg);
private:
    Ui::ApplyFriendItem *ui;
    QString _name;
    QString _head;
    QString _msg;

signals:
    void sig_auth_friend(QString name);
};

#endif // APPLYFRIENDITEM_H
