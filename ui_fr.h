/********************************************************************************
** Form generated from reading UI file 'FireRescue.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FR_H
#define UI_FR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <iostream>
#include <QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FireRescue
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *centerDisk[80];
    QLabel *leftUpperDisk[80];
    QLabel *leftLowerDisk[80];
    QLabel *rightUpperDisk[80];
    QLabel *rightLowerDisk[80];
    QLabel *door[9];
    QPushButton *startGame;
    QPushButton *doorB;
    QPushButton *fireB;
    QPushButton *smokeB;

    void setupUi(QWidget *FireRescue)
    {
        if (FireRescue->objectName().isEmpty())
            FireRescue->setObjectName("FireRescue");
        FireRescue->resize(1600, 1000);

        // Set the background image using a QLabel
        QLabel *backgroundLabel = new QLabel(FireRescue);
        backgroundLabel->setObjectName("backgroundLabel");
        QPixmap bkgnd("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sFireBoard.jpg");
        bkgnd = bkgnd.scaled(1400, 1000, Qt::KeepAspectRatioByExpanding);
        backgroundLabel->setPixmap(bkgnd);
        backgroundLabel->setGeometry(QRect(200, 0, 1400, 1000));

        label = new QLabel(FireRescue);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 200, 100));
        label->setText("Testing");

       
        /*for (int i = 0; i < 80; ++i) 
        {
            centerDisk[i] = new QLabel();  // Allocate memory for each QLabel
        }*/

        QPixmap fire("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sFire.png");
        QPixmap smoke("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sSmoke.png");
        QPixmap hazmat("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sHazmat.png");
        QPixmap hotSpot("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sHotSpot.png");
        QPixmap poi3("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi3.png");
        QPixmap doorClosed("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sDoorClosed.png");
        QPixmap doorOpen("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sDoorOpen.png");

        /********************** set up the grid tokens ********************/
        for (int row=0; row<8; row++)
        {
            for (int col=0; col<10; col++)
            {
                int x = (row*10)+col;
                centerDisk[x] = new QLabel(FireRescue); 
                centerDisk[x]->setObjectName("centerDisk"+QString::number(x));
                centerDisk[x]->setPixmap(QPixmap());
                centerDisk[x]->setGeometry(QRect(378+(col*127), 35+(row*125), 60, 60));

                leftUpperDisk[x] = new QLabel(FireRescue); 
                leftUpperDisk[x]->setObjectName("leftUpperDisk"+QString::number(x));
                leftUpperDisk[x]->setPixmap(QPixmap());
                leftUpperDisk[x]->setGeometry(QRect(332+(col*127), 5+(row*125), 60, 60));

                leftLowerDisk[x] = new QLabel(FireRescue); 
                leftLowerDisk[x]->setObjectName("leftLowerDisk"+QString::number(x));
                leftLowerDisk[x]->setPixmap(QPixmap());
                leftLowerDisk[x]->setGeometry(QRect(332+(col*127), 65+(row*125), 60, 60));

                rightLowerDisk[x] = new QLabel(FireRescue); 
                rightLowerDisk[x]->setObjectName("rightLowerDisk"+QString::number(x));
                rightLowerDisk[x]->setPixmap(QPixmap());
                rightLowerDisk[x]->setGeometry(QRect(392+(col*127), 65+(row*125), 60, 60));

                rightUpperDisk[x] = new QLabel(FireRescue); 
                rightUpperDisk[x]->setObjectName("rightUpperDisk"+QString::number(x));
                rightUpperDisk[x]->setPixmap(QPixmap());
                rightUpperDisk[x]->setGeometry(QRect(392+(col*127), 5+(row*125), 60, 60));

                
            }
        }

        /********************** set up the doors ********************/
        for (int i=0; i<9; i++)
        {
            door[i] = new QLabel(FireRescue);
            door[i]->setObjectName("door"+QString::number(i));
            door[i]->setPixmap(doorClosed);
        }
        door[0]->setGeometry(QRect(0,0,0,0));
        door[1]->setGeometry(QRect( 810, 170 ,60, 60));
        door[2]->setGeometry(QRect( 1075, 270 ,60, 60));
        door[4]->setGeometry(QRect( 685, 420 ,60, 60));
        door[3]->setGeometry(QRect( 1365, 345 ,60, 60));
        door[5]->setGeometry(QRect( 1195, 520 ,60, 60));
        door[6]->setGeometry(QRect( 855, 593 ,60, 60));
        door[7]->setGeometry(QRect( 1065, 770 ,60, 60));
        door[8]->setGeometry(QRect( 1325, 775 ,60, 60));

        /*********************** set up the QTable ********************/

        tableWidget = new QTableWidget(FireRescue);
        if (tableWidget->columnCount() < 10)
            tableWidget->setColumnCount(10);
        if (tableWidget->rowCount() < 8)
            tableWidget->setRowCount(8);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(330, 0, 1400, 1000));
        tableWidget->setRowCount(8);
        tableWidget->setColumnCount(10);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(127);

        

        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setDefaultSectionSize(125);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        tableWidget->setStyleSheet("QTableWidget { background-color: transparent; }"
                           "QTableWidget::item { selection-background-color: transparent; }"
                           "QTableWidget::item:selected { background-color: transparent; }");

        startGame = new QPushButton(FireRescue);
        startGame->setObjectName("startGame");
        startGame->setGeometry(QRect(50, 200, 100, 100));
        startGame->setText("Start Game");
        startGame->setCheckable(false);

        doorB = new QPushButton(FireRescue);
        doorB->setObjectName("doorB");
        doorB->setGeometry(QRect(50, 350, 100, 100));
        doorB->setText("Door");
        doorB->setCheckable(false);

        fireB = new QPushButton(FireRescue);
        fireB->setObjectName("fireB");
        fireB->setGeometry(QRect(50, 500, 100, 100));
        fireB->setText("Fire");
        fireB->setCheckable(false);

        startGame = new QPushButton(FireRescue);
        startGame->setObjectName("smokeB");
        startGame->setGeometry(QRect(50, 650, 100, 100));
        startGame->setText("Smoke");
        startGame->setCheckable(false);
        
        retranslateUi(FireRescue);

        QMetaObject::connectSlotsByName(FireRescue);
    } // setupUi

    void retranslateUi(QWidget *FireRescue)
    {
        FireRescue->setWindowTitle(QCoreApplication::translate("FireRescue", "FireRescue", nullptr));
    } // retranslateUi
    

};

namespace Ui {
    class FireRescue: public Ui_FireRescue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FR_H
