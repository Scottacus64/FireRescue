#ifndef FFDIALOG_H
#define FFDIALOG_H

#include <QDialog>
#include <QRadioButton>
#include <QPushButton>

class FfDialog : public QDialog
{
    Q_OBJECT

public:
    FfDialog(QWidget *parent = nullptr);
    QRadioButton *player[6];
    QPushButton *start;
    int selectedButtonIndex;
};

#endif // FFDIALOG_H
