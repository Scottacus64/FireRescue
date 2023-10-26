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
    void checkSmokeFire(int location);
    void placeFire(int location);
    void refreshBoard();
    void cycleDoor(int location, int direction);
    void checkBreach(int location);
    void shockWave(int direction, int location);
    void damageWall(int direction, int location, int base); 
    void placeHotSpot(int location);
    void flareUpCheck(int location);
    void rollDice(int slot);
    bool checkNewSpot(int slot);
    void delayTimer(int delay);
    void moveFF(int location, int direction);
    void spray(int location, int direction);
    void chop(int location, int direction);
    void carry(int slot, int location, int obj, int direction);
    void placeFF();
    void nextPlayer();
    void fireTurn();
    void universalAction(int direction);
    int  newPoiLocation();
    void sortPoi();
    void makePoiLabel(int slot, int multPoi);
    void ffDialog();
    int  carryDialog();
    void carryPoi(int slot, int poiSlot, int offset);
    void carryHazmat(int slot, int hazmatSlot, int offset);
    void placeNewPoi(int slot);
    void gameOver();
    void resetGame();
    void textUpdate();

private:
    Ui::FireRescue *ui;
    Dice die;
    QPixmap fire;
    QPixmap smoke;
    QPixmap hotSpot;
    QPixmap hazmat;
    QPixmap doorOpen;
    QPixmap doorClosed;
    QPixmap poi[12];
    QPixmap poiBlank;
    QPixmap ff[6];
    QPixmap greyCube;
    QPixmap blackCube;
    QPixmap D6[7];
    QPixmap D8[9];

    QLabel *damageSquare[40];
    QLabel *ffExtra[6];
    QLabel *poiExtra[3];
    QLabel *hazmatLabel[4];
    QLabel *hotSpotLabel[12];

    QPushButton *carryPoiButton;
    QPushButton *carryHazmatButton;

    std::vector<MapCell*> adjacentCells(int location);
    std::vector<int> poiList;   // list of all POI's to be shuffled at start of game

    bool ffBlock = true;        // blocker to keep rb's inactive while setting the number of ff
    bool setUpGameOn;
    bool fireOn = false;
    bool doorOn = false;
    bool smokeOn = false;
    bool flareUp = false;
    bool flareUpOn = false;

    int* m_MapArray;
    int* m_WallArray;
    int  doorArray[8] = {35,58,71,76,101,109,142,144};  
    int  baseOffset[4]= {0,10,11,21};
    int  wallDamage = 0;
    int  action;                // 0 = move, 1 = spray, 2 = chop, 3 = carry, 4 = open, 5 = close
    int  ffNumber;              // number of FF for this game
    int  ffStart = 0;
    int  activeFF = 0;          // current FF
    int  ffMoves;               // number of actions a FF has   
    int  hotSpots = 12;
    int  gridLocation;
    int  gameState = 0;
    int  baseValue(int position);
    int  getOthersideOfWall(int direction, int location);
    int  value8;
    int  value6;
    int  poiSaved = 0;
    int  poiLost = 0;
    int  lastPoi;
    int  ambulance[8]= {5,6,30,40,39,49,73,74};
    int  smokeRecursion = 0;

    struct ffStruct {int ff; int location; int moves;};
    ffStruct ffArray[6];
    struct poiStruct {int poi; int location; int state;};
    poiStruct poiArray[3];
    poiStruct poiTemp;
    int  hazmatArray[4] = {100, 100, 100, 100};
    int  hotSpotArray[12] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    QList<QLabel *> labels;
    Board m_theBoard;

private slots:
    void on_tableWidget_cellClicked(int row, int column);
    void on_utility_clicked();
    void on_rbMove_clicked();
    void on_rbSpray_clicked();
    void on_rbChop_clicked();
    void on_rbCarry_clicked();
    void on_rbOpen_clicked();
    void on_rbClose_clicked();
    void on_arrowU_clicked();
    void on_arrowD_clicked();
    void on_arrowL_clicked();
    void on_arrowR_clicked();
};
#endif // FIRERESCUE_H
