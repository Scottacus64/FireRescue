#ifndef FFDIALOG_H
#define FFDIALOG_H

#include <QDialog>
#include <QRadioButton>

class FfDialog : public QDialog
{
    Q_OBJECT

public:
    FfDialog(QWidget *parent = nullptr);
    QRadioButton *player[6];
    int selectedButtonIndex;
};

#endif // FFDIALOG_H
