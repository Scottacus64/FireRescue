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
#include <QRadioButton>
#include <QDialog>

QT_BEGIN_NAMESPACE

class Ui_FireRescue
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *centerDisk[80];
    QLabel *leftUpperDisk[80];
    QLabel *door[9];
    QLabel *cube[43];
    QLabel *hs[12];
    QLabel *D6;
    QLabel *D8;
    QLabel *damage;
    QLabel *personsSaved;
    QLabel *personsLost;
    QLabel *ffUp;
    QLabel *ffUpIcon;
    QLabel *information;
    QPushButton *arrowL;
    QPushButton *arrowU;
    QPushButton *arrowD;
    QPushButton *arrowR;

    QPushButton *utility;

    QRadioButton *rbMove;
    QRadioButton *rbSpray;
    QRadioButton *rbChop;
    QRadioButton *rbCarry;
    QRadioButton *rbOpen;
    QRadioButton *rbClose;

    QDialog *ffDialog;
    

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

 /********************** set up the grid tokens ********************/
        for (int row=0; row<8; row++)
        {
            for (int col=0; col<10; col++)
            {
                int x = (row*10)+col;
                leftUpperDisk[x] = new QLabel(FireRescue); 
                leftUpperDisk[x]->setObjectName("leftUpperDisk"+QString::number(x));
                leftUpperDisk[x]->setPixmap(QPixmap());
                leftUpperDisk[x]->setGeometry(QRect(332+(col*127), 5+(row*125), 60, 60));                
            }
        }
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
        QPixmap hotSpot("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sHotSpot.png");
        QPixmap doorClosed("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sDoorClosed.png");
        QPixmap doorOpen("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sDoorOpen.png");
        QPixmap square("/Users/scottmiller/VSC/CPP/FireRescue/Resources/blackCube.png");
        QPixmap r1("/Users/scottmiller/VSC/CPP/FireRescue/Resources/r1.png");
        QPixmap b1("/Users/scottmiller/VSC/CPP/FireRescue/Resources/b1.png");
        QPixmap aU("/Users/scottmiller/VSC/CPP/FireRescue/Resources/aU.png");
        QPixmap aD("/Users/scottmiller/VSC/CPP/FireRescue/Resources/aD.png");
        QPixmap aL("/Users/scottmiller/VSC/CPP/FireRescue/Resources/aL.png");
        QPixmap aR("/Users/scottmiller/VSC/CPP/FireRescue/Resources/aR.png");
        QPixmap ffR("/Users/scottmiller/VSC/CPP/FireRescue/Resources/ffR.png");
       
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

        /********************** set up the damage cubes ********************/
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

        /*********************** set up the Damage markers ********************/
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

        utility = new QPushButton(FireRescue);
        utility->setObjectName("utility");
        utility->setGeometry(QRect(50, 775, 100, 50));
        utility->setText("Start Game");
        utility->setCheckable(false);

        /************** set up the game value displays ********************/
        damage = new QLabel(FireRescue);
        personsLost = new QLabel(FireRescue);
        personsSaved = new QLabel(FireRescue);
        ffUp = new QLabel(FireRescue);
        ffUpIcon = new QLabel(FireRescue);
        information = new QLabel(FireRescue);
        damage->setGeometry(QRect(30,150, 150, 40));
        damage->setText("Damage = 0");
        personsSaved->setGeometry(QRect(30,190,150,40));
        personsSaved->setText("Persons Saved = 0");
        personsLost->setGeometry(QRect(30,230,150,40));
        personsLost->setText("Persons Lost = 0");
        ffUp->setGeometry(QRect(30,260,150,40));

        ffUpIcon->setGeometry(QRect(50,310,50,50));

        information->setGeometry(QRect(10,370,180,150));
        information->setStyleSheet("border: 2px solid black;");
        information->setWordWrap(true);

        /************** set up the Arrows ***************/
        arrowL = new QPushButton(FireRescue);
        arrowL->setObjectName("arrowL");
        arrowL->setGeometry(QRect(30, 880, 50, 50));
        arrowL->setCheckable(false);
        arrowL->setIcon(QIcon(aL));
        arrowL->setIconSize(QSize(50, 50));
        arrowL->setStyleSheet("border: none; background-color: transparent;");

        arrowR = new QPushButton(FireRescue);
        arrowR->setObjectName("arrowR");
        arrowR->setGeometry(QRect(110, 880, 50, 50));
        arrowR->setCheckable(false);
        arrowR->setIcon(QIcon(aR));
        arrowR->setIconSize(QSize(50, 50));
        arrowR->setStyleSheet("border: none; background-color: transparent;");

        arrowU = new QPushButton(FireRescue);
        arrowU->setObjectName("arrowU");
        arrowU->setGeometry(QRect(70, 840, 50, 50));
        arrowU->setCheckable(false);
        arrowU->setIcon(QIcon(aU));
        arrowU->setIconSize(QSize(50, 50));
        arrowU->setStyleSheet("border: none; background-color: transparent;");

        arrowD = new QPushButton(FireRescue);
        arrowD->setObjectName("arrowD");
        arrowD->setGeometry(QRect(70, 920, 50, 50));
        arrowD->setCheckable(false);
        arrowD->setIcon(QIcon(aD));
        arrowD->setIconSize(QSize(50, 50));
        arrowD->setStyleSheet("border: none; background-color: transparent;");

        /*************** set up radio buttons ****************/

        rbMove = new QRadioButton(FireRescue);
        rbSpray = new QRadioButton(FireRescue);
        rbChop = new QRadioButton(FireRescue);
        rbCarry = new QRadioButton(FireRescue);
        rbOpen = new QRadioButton(FireRescue);
        rbClose = new QRadioButton(FireRescue);


        rbMove->setText("Move");
        rbSpray->setText("Spray");
        rbChop->setText("Chop");
        rbCarry->setText("Carry");
        rbOpen->setText("Open");
        rbClose->setText("Close");


        rbMove->setGeometry(50, 520, 150, 40);
        rbSpray->setGeometry(50, 560, 150, 40);
        rbChop->setGeometry(50, 600, 150, 40);
        rbCarry->setGeometry(50, 640, 150, 40);
        rbOpen->setGeometry(50, 680, 150, 40);
        rbClose->setGeometry(50, 720, 150, 40);


        rbMove->setObjectName("rbMove");
        rbSpray->setObjectName("rbSpray");
        rbChop->setObjectName("rbChop");
        rbCarry->setObjectName("rbCarry");
        rbOpen->setObjectName("rbOpen");
        rbClose->setObjectName("rbClose");

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
