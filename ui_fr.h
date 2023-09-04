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
    QLabel *cube[43];
    QLabel *hs[12];
    QLabel *D6;
    QLabel *D8;
    QPushButton *startGame;
    QPushButton *doorB;
    QPushButton *fireB;
    QPushButton *smokeB;
    int theWalls[178] = {                0,0,0,0,0,0,0,0,0,0,
                                        0,0,0,0,0,0,0,0,0,0,0,
                                         0,1,2,3,4,5,0,6,7,0,
                                        0,8,0,0,0,0,9,0,0,10,0,
                                         0,0,0,0,0,0,0,0,0,0,
                                        0,11,0,0,12,0,0,0,0,13,0,
                                         0,0,0,14,15,16,17,18,0,0,
                                        0,0,0,0,0,0,0,19,0,20,0,
                                         0,0,0,0,0,0,0,0,0,0,
                                        0,21,0,22,0,0,0,0,0,0,0,
                                         0,23,24,25,0,26,27,28,29,0,
                                        0,30,0,0,0,0,31,0,32,33,0,
                                         0,0,0,0,0,0,0,0,0,0,
                                        0,34,0,0,0,0,0,0,0,35,0,
                                         0,36,37,0,38,39,40,41,42,0,
                                        0,0,0,0,0,0,0,0,0,0,0,  
                                         0,0,0,0,0,0,0,0,0,0     }; 

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



        label = new QLabel(FireRescue);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(80);
        label->setFont(font);
        label->setStyleSheet("background-color: rgb(201,79,19); color: white;");
        label->setAlignment(Qt::AlignCenter);
        label->setGeometry(QRect(620, 10, 675, 100));
        label->setText("Place Explosion 1");
        label->setVisible(false);

        QPixmap fire("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sFire.png");
        QPixmap smoke("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sSmoke.png");
        QPixmap hazmat("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sHazmat.png");
        QPixmap hotSpot("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sHotSpot.png");
        QPixmap poi3("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi3.png");
        QPixmap doorClosed("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sDoorClosed.png");
        QPixmap doorOpen("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sDoorOpen.png");
        QPixmap square("/Users/scottmiller/VSC/CPP/FireRescue/Resources/blackCube.png");
        QPixmap r1("/Users/scottmiller/VSC/CPP/FireRescue/Resources/r1.png");
        QPixmap b1("/Users/scottmiller/VSC/CPP/FireRescue/Resources/b1.png");
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

        /********************** set up the squares ********************/
        for (int i=0; i<43; i++)
        {
            cube[i] = new QLabel(FireRescue);
            cube[i]->setObjectName("square"+QString::number(i));
            cube[i]->setPixmap(QPixmap());
        }
        int location = 0;
        int xOffset;
        int yOffset;
        for (int i=0; i<178; i++)
        {
            if (theWalls[i]>0)
            {
                int row = i/21;
                int col = i%21;
                if (col<10)
                {
                    xOffset = 63 + (col*127);
                    yOffset = (row*125)-10;
                }
                else
                {
                    xOffset = (col-10)*127 ;
                    yOffset = (row*125)+53;
                    if (col>15){xOffset+=6;}
                    
                }
                //std::cout << location << ") Col = " << col << " Row =" << row << "\n";
                cube[location]->setGeometry(QRect(325+xOffset, yOffset, 20, 20));
                location ++;
            }
        }

        /*********************** set up the HotSpot markers ********************/
        int slot = 0;
        int k = 0;
        for (int i=0; i<4; i++)
        {
            if (i > 1){k=285;}
            for (int j=0; j<3; j++)
            {
                hs[slot] = new QLabel(FireRescue);
                hs[slot]->setObjectName("square"+QString::number(i));
                hs[slot]->setPixmap(hotSpot);   
                hs[slot]->setGeometry(QRect(217+(j*38), 285+(i*38)+k, 30, 30));
                slot += 1;
            }
        }

        /*********************** set up the Dice ********************/
        D6 = new QLabel(FireRescue);
        D6->setObjectName("D6");
        D6->setPixmap(r1); 
        D6->setGeometry(QRect(30, 30, 60, 60));
        D8 = new QLabel(FireRescue);
        D8->setObjectName("D8");
        D8->setPixmap(b1); 
        D8->setGeometry(QRect(110, 30, 60, 60));

       
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
