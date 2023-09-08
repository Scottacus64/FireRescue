#ifndef FIRERESCUE_H
#define FIRERESCUE_H

#include "dice.h"
#include "ui_fr.h"
#include "Board.h"
#include <QtWidgets/QLabel>


QT_BEGIN_NAMESPACE
namespace Ui { class FireRescue; }
QT_END_NAMESPACE

class FireRescue : public QWidget
{
    Q_OBJECT

public:
    FireRescue(QWidget *parent = nullptr);
    ~FireRescue();
    void setUpGame();
    void explosion(int location);
    void placeSmoke(int location);
    void placeFire(int location);
    void refreshBoard();
    void cycleDoor(int location, int direction);
    void checkBreach(int location);
    std::vector<MapCell*> adjacentCells(int location);
    std::vector<int> poiList;
    std::vector<std::pair<int, int>> poiPair;
    void printSmoke(int location);
    void printFire(int location);
    int  baseValue(int position);
    int  getOthersideOfWall(int direction, int location);
    int  value8;
    int  value6;
    void shockWave(int direction, int location);
    void damageWall(int direction, int location, int base); 
    void placeHotSpot(int location);
    void rollDice(int slot);
    bool checkNewSpot(int slot);
    void placeHazmat(int location);
    void placePOI(int location);
    void delayTimer(int delay);
    void movePlyer(int slot, int location, int direction);
    void spray(int location, int direction);
    void chop(int location, int direction);
    void carry(int slot, int location, int obj, int direction);
    void placeFF();

    

    void ffDialog();
    
    int  doorArray[8] = {35,58,71,76,101,109,142,144};  
    int  baseOffset[4]= {0,10,11,21};
    int  wallDamage = 0;
    int* m_MapArray;
    int* m_WallArray;
    std::vector<int> players;
    int  action;            // 0 = move, 1 = spray, 2 = chop, 3 = carry, 4 = open, 5 = close
    int  ffNumber;
    int  activeFF = 0;
    bool ffBlock = true;
    QLabel *damageSquare[40];
    QCursor cursorFF1;


private:
    Ui::FireRescue *ui;
    Dice die;
    QPixmap fire;
    QPixmap smoke;
    QPixmap hotSpot;
    QPixmap hazmat;
    QPixmap doorOpen;
    QPixmap doorClosed;
    QPixmap poi0;
    QPixmap poi1;
    QPixmap poi2;
    QPixmap poi3;
    QPixmap poi4;
    QPixmap poi5;
    QPixmap poi6;
    QPixmap poi7;
    QPixmap poi8;
    QPixmap poi9;
    QPixmap poi10;
    QPixmap poiBlank;

    QPixmap cursorIconFF1;


    QPixmap ff[6];

    QPixmap greySquare;
    QPixmap blackSquare;

    QPixmap D6[7];
    QPixmap D8[9];

    bool fireOn = false;
    bool doorOn = false;
    bool smokeOn = false;
    int  hotSpots = 12;
    int  gridLocation;


    Board m_theBoard;
    

private slots:
    void on_tableWidget_cellClicked(int row, int column);
    void on_startGame_clicked();
    void on_rbMove_clicked();
    void on_rbSpray_clicked();
    void on_rbChop_clicked();
    void on_rbCarry_clicked();
    void on_rbOpen_clicked();
    void on_rbClose_clicked();
    void on_rbEndTurn_clicked();
    void on_arrowU_clicked();
    void on_arrowD_clicked();
    void on_arrowL_clicked();
    void on_arrowR_clicked();

};
#endif // FIRERESCUE_H
