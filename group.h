#ifndef GROUP_H
#define GROUP_H

#include <QDialog>

namespace Ui {
class Group;
}

class Group : public QDialog
{
    Q_OBJECT

public:
    explicit Group(QWidget *parent = nullptr);
    ~Group();

private slots:

    void on_groupBack_button_clicked();

    void on_groupBack_button_pressed();

signals:
    void groupBack_buttonPressed();

private:
    Ui::Group *ui;

};

#endif // GROUP_H
