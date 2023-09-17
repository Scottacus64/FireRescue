#include "FireRescue.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <QTimer>
#include "ffDialog.h"
#include <QMap>
#include <cmath>
#include <QDialog>
#include <QRadioButton>
#include <QPushButton>

/* win is 7 POI rescued, loss is 4 POI lost or building collapse 24 damage markers*/

FireRescue::FireRescue(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FireRescue)
{
    fire.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sFire2.png");
    smoke.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sSmoke2.png");
    hotSpot.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sHotSpot.png");
    hazmat.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sHazmat.png");
    doorOpen.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sDoorOpen.png");
    doorClosed.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sDoorClosed.png");

    poi[11].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi0.png");

    poi[1].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi1.png");
    poi[2].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi2.png");
    poi[3].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi3.png");
    poi[4].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi4.png");
    poi[5].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi5.png");
    poi[6].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi6.png");
    poi[7].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi7.png");
    poi[8].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi8.png");
    poi[9].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi9.png");
    poi[10].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi10.png");

    poi[0].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sPOIblank.png");

    ff[0].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/ffB.png");
    ff[1].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/ffG.png");
    ff[2].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/ffR.png");
    ff[3].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/ffO.png");
    ff[4].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/ffY.png");
    ff[5].load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/ffW.png");

    D6[1] = QPixmap("/Users/scottmiller/VSC/CPP/FireRescue/Resources/r1.png");
    D6[2] = QPixmap("/Users/scottmiller/VSC/CPP/FireRescue/Resources/r2.png");
    D6[3] = QPixmap("/Users/scottmiller/VSC/CPP/FireRescue/Resources/r3.png");
    D6[4] = QPixmap("/Users/scottmiller/VSC/CPP/FireRescue/Resources/r4.png");
    D6[5] = QPixmap("/Users/scottmiller/VSC/CPP/FireRescue/Resources/r5.png");
    D6[6] = QPixmap("/Users/scottmiller/VSC/CPP/FireRescue/Resources/r6.png");

    D8[1] = QPixmap("/Users/scottmiller/VSC/CPP/FireRescue/Resources/b1.png");
    D8[2] = QPixmap("/Users/scottmiller/VSC/CPP/FireRescue/Resources/b2.png");
    D8[3] = QPixmap("/Users/scottmiller/VSC/CPP/FireRescue/Resources/b3.png");
    D8[4] = QPixmap("/Users/scottmiller/VSC/CPP/FireRescue/Resources/b4.png");
    D8[5] = QPixmap("/Users/scottmiller/VSC/CPP/FireRescue/Resources/b5.png");
    D8[6] = QPixmap("/Users/scottmiller/VSC/CPP/FireRescue/Resources/b6.png");
    D8[7] = QPixmap("/Users/scottmiller/VSC/CPP/FireRescue/Resources/b7.png");
    D8[8] = QPixmap("/Users/scottmiller/VSC/CPP/FireRescue/Resources/b8.png");

    greySquare.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/greyCube.png");
    blackSquare.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/blackCube.png");

    Board m_theBoard = Board();
    m_MapArray = MapCell::getMapArray();
    m_WallArray = MapCell::getWallArray();

    for (int i=1; i<11; i++)  
    {
        poiList.push_back(i);
    }
    for (int i=0; i<5; i++) {poiList.push_back(1);}         // 0 is a blank POI chip
    // Shuffle the vector
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(poiList.begin(), poiList.end(), rng);
    setUpGameOn = true;

    for (int i=0; i<6; i++)
    {
        ffArray[i].ff = i;
        ffArray[i].location = 100;
        ffArray[i].moves = 0;
    }
    ui->setupUi(this);
}


FireRescue::~FireRescue()
{
    delete ui;
}


void FireRescue::on_tableWidget_cellClicked(int row, int col)
{
    int carry = carryDialog();
    std::cout << "CARRY = " << carry << "\n";
    
    //std::cout << "setUpGame = " << setUpGameOn << "\n";
    gridLocation = (row*10) + col;
    MapCell* cell = m_theBoard.GetCell(gridLocation); 
    bool onFire = cell->getFire();
    /************* initial ff placement ****************/
    if ((gridLocation<11 || gridLocation>68 || gridLocation%10 == 0 || (gridLocation+1)%10 == 0) && ffBlock == true && onFire == false && setUpGameOn == false)
    {    
        ffArray[ffStart].location = gridLocation;
        if (ffStart+1 < ffNumber) 
        {
            ffStart ++;
            placeFF();
        }
        else 
        {
            ffBlock = false;
            gameState = 1;
            ui->utility->setText("End Turn");
            activeFF = ffNumber;
            nextPlayer();
        }
        
    }
    refreshBoard();
}


void FireRescue::nextPlayer()
{
    ffArray[activeFF].moves = ffMoves;
    activeFF ++;
    if (activeFF+1 > ffNumber) {activeFF = 0;}
    ffMoves = ffArray[activeFF].moves + 5;
    ui->ffUp->setText("Fire Fighter Moves = "+ QString::number(ffMoves));
    ui->ffUpIcon->setPixmap(ff[activeFF]);
    ui->information->setText("Fire Fighter " + QString::number(activeFF) + " is up!");
    flareUp = false;
}


void FireRescue::setUpGame()
{
    setUpGameOn = true;
    int row = 0;
    int col = 0;
    rollDice(0);
    bool onFire = false;
    int location;
    int poiSlot = 0;
    ui->label->setVisible(true);

    for (int i=0; i<3; i++) 
    {
        int poiValue = poiList.back();
        poiList.pop_back();
        poiArray[i] = {poiValue,100,0};
    }

    for (int startUpSequence=0; startUpSequence<13; startUpSequence++)
    {
        if (startUpSequence == 0)                            // explosion 1
        {
            if (value8 < 5)
            {
                row = 4;
                col = value8;
            }
            else
            {
                row = 5;
                col = 11-value8;
            }
            location = (row*8) + col;
            explosion(location);
            delayTimer(50);
        }
        if (startUpSequence == 1)                               // explosion 2
        {
            ui->label->setText("Place Explosion 2");
            onFire = true;
            while (onFire == true )
            {
                onFire = checkNewSpot(1);
                location = ((value6)*10)+(value8);
                //std::cout << "Fire Detected: " << value6 << "," << value8 << "\n";
            }
            explosion(location);
            delayTimer(50);
        }
        if (startUpSequence == 2)                               // explostion 3
        {
            ui->label->setText("Place Explosion 3");
            value8 = 9-value8;
            onFire = true;
            while (onFire == true )
            {
                onFire = checkNewSpot(2);
                location = ((value6)*10)+(value8);
                //std::cout << "Fire Detected: " << value6 << "," << value8 << "\n";
            }
            explosion(location);
            delayTimer(50);
        }
        if (startUpSequence >2 && startUpSequence <7)           // place Hazmats
        {
            ui->label->setText("Place Hazmat " + QString::number(startUpSequence-2));
            onFire = true;
            bool hazmatHere = false;
            int location;
            while (onFire == true || hazmatHere == true )
            {
                hazmatHere = false;
                onFire = checkNewSpot(3);
                location = ((value6)*10)+(value8);
                for (int i=0; i<4; i++)
                {
                    if (location == hazmatArray[i])
                    {
                        hazmatHere = true;
                    }
                }
            }
            hazmatArray[startUpSequence-3] = location;
            delayTimer(50);
        }
        if (startUpSequence >6 && startUpSequence <10)          // place POI
        {
            ui->label->setText("Place 3 Persons" + QString::number(startUpSequence-6));
            location = newPoiLocation();
            poiArray[poiSlot].location = location;
            poiSlot ++;
            delayTimer(50);
        }
        sortPoi();
        if (startUpSequence > 9 && startUpSequence <13)         // place Hot Spots
        {
            ui->label->setText("Place 3 Hot Spots" + QString::number(startUpSequence-9));
            onFire = true;
            bool hotSpotHere = false;
            int location;
            while (onFire == true || hotSpotHere == true )
            {
                hotSpotHere = false;
                onFire = checkNewSpot(3);
                location = ((value6)*10)+(value8);
                for (int i=0; i<4; i++)
                {
                    if (location == hotSpotArray[i])
                    {
                        hotSpotHere = true;
                    }
                }
            }
            placeHotSpot(location);
            delayTimer(50);
        }        
    }
    ui->label->setVisible(false);
    refreshBoard();
    setUpGameOn = false;
    placeFF();
}


int FireRescue::newPoiLocation()
{
    bool onFire = true;
    bool poiHere = false;
    int location;
    
    while (onFire == true || poiHere == true)
    {
        onFire = checkNewSpot(6);
        location = ((value6)*10)+(value8);
        int poiMatch = 0;
        for (int i=0; i<3; i++) 
        {
            if (poiArray[i].location == location){poiMatch++;}
        }
        MapCell* cell = m_theBoard.GetCell(location); 
        onFire = cell->getFire();
        if (poiMatch>0){poiHere = true;}
        else {poiHere = false;}
    }
    return location;
}

void FireRescue::sortPoi()
{
    for (int j=0; j<2; j++)
    {
        for (int i=0; i<2; i++)
        {
            if (poiArray[i].poi < poiArray[i+1].poi)
            {
                poiTemp = poiArray[i];
                poiArray[i] = poiArray[i+1];
                poiArray[i+1] = poiTemp;
            }
        }
    }
}


void FireRescue::placeFF()
{  
    ui->ffUp->setText("Fire Fighter "+ QString::number(ffStart));
    ui->ffUpIcon->setPixmap(ff[ffStart]);
    ui->information->setText("Please click on a street square to place the Fire Fighter");
}


void FireRescue::ffDialog() 
{
    FfDialog *ffDialog = new FfDialog(this);

    // Show the dialog modally
    int result = ffDialog->exec();
    //std::cout << "Result is " << result << "\n";
    if (ffDialog->selectedButtonIndex != -1) 
    {
    ffNumber = ffDialog->selectedButtonIndex + 1;
    //std::cout << "SELECTED = " << ffNumber << "\n";
    }
}


void FireRescue::delayTimer(int delay)
{
    QTimer timer;
    timer.setInterval(delay); 
    timer.start();
    // Use a loop to wait until the QTimer times out (25ms)
    QEventLoop loop;
    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    loop.exec();
}


bool FireRescue::checkNewSpot(int slot)
{
    rollDice(slot);
    int location = ((value6)*10)+(value8);
    MapCell* cell = m_theBoard.GetCell(location); 
    bool onFire = cell->getFire();
    return onFire;
}


void FireRescue::rollDice(int slot)
{
    for (int j=0; j<10; j++)
    {
        delayTimer(5);
        if (slot != 2){value8 = die.rollDie(8);}
        value6 = die.rollDie(6);
        ui->D6->setPixmap(D6[value6]);
        ui->D8->setPixmap(D8[value8]);
    }
}


void FireRescue::on_utility_clicked()
{
    static bool doubleCheck;
    if (gameState == 0)
    {
        ffDialog();
        setUpGame();
    }
    else if (gameState == 1)
    {
        if (ffBlock == false) 
        {
            if (ffMoves > 4)
            {
                ui->information->setText("Do you really want to end your turn??");
                doubleCheck = !doubleCheck;
            }
            if (ffMoves < 5){doubleCheck = false;}
            if (doubleCheck == false) {fireTurn();}
        }
    }
}


void FireRescue::on_rbMove_clicked()
{
    if (ffBlock == false) {action = 0;}
}


void FireRescue::on_rbSpray_clicked()
{

    if (ffBlock == false) {action = 1;}
}


void FireRescue::on_rbChop_clicked()
{
    if (ffBlock == false) {action = 2;}
}


void FireRescue::on_rbCarry_clicked()
{
    if (ffBlock == false) {action = 3;}
}


void FireRescue::on_rbOpen_clicked()
{
    if (ffBlock == false) {action = 4;}
}


void FireRescue::on_rbClose_clicked()
{
   if (ffBlock == false) {action = 5;}
}


void FireRescue::on_arrowU_clicked()
{
    if (ffBlock == false) {universalAction(0); }
}


void FireRescue::on_arrowD_clicked()
{
    if (ffBlock == false){universalAction(3);}
}


void FireRescue::on_arrowL_clicked()
{
    if (ffBlock == false){universalAction(1); }
}


void FireRescue::on_arrowR_clicked()
{
    if (ffBlock == false) {universalAction(2);}
}


void FireRescue::universalAction(int direction)
{
    int offest, limit;
    bool takeAction = false;
    if (direction==0){takeAction = ffArray[activeFF].location-10 > -1;}
    else if (direction==1){takeAction = ffArray[activeFF].location%10 != 0;}
    else if (direction==2){takeAction = (ffArray[activeFF].location+1)%10 != 0;}
    else {takeAction = (ffArray[activeFF].location+10)<80;}
    if (takeAction == true)
    {
        if (action==0)
        {
            moveFF(ffArray[activeFF].location, direction);
            ui->ffUp->setText("Fire Fighter Moves = "+ QString::number(ffMoves));
        }
        else if (action==1)
        {
            spray(ffArray[activeFF].location,direction);
            ui->ffUp->setText("Fire Fighter Moves = "+ QString::number(ffMoves));
        }
        else if (action==2)
        {
            chop(ffArray[activeFF].location,direction);
            ui->ffUp->setText("Fire Fighter Moves = "+ QString::number(ffMoves));
        }
        else if (action==3 && ffMoves >1)
        {
            carry(activeFF, ffArray[activeFF].location, 0, direction);
            ui->ffUp->setText("Fire Fighter Moves = "+ QString::number(ffMoves));
        }
        else if (action==4 || action==5) 
        {
            cycleDoor(ffArray[activeFF].location,direction);
            ui->ffUp->setText("Fire Fighter Moves = "+ QString::number(ffMoves));
        }
    }
    if (ffMoves == 0){fireTurn();}
}    


void FireRescue::moveFF(int location, int direction)   
{
    MapCell* cell = m_theBoard.GetCell(location);
    int base = baseValue(location);
    int barrier = m_MapArray[base + baseOffset[direction]];
    int offset;
    if (direction==0){offset = -10;}
    else if (direction==1){offset = -1;}
    else if (direction==2){offset = 1;}
    else {offset = 10;}
    MapCell* dCell = m_theBoard.GetCell(location+offset);
    if ((barrier==0 || barrier==3) && dCell->getFire()==false && ffMoves>0)
    {
        ffArray[activeFF].location +=offset;
        for (int i=0; i<3; i++)
        {
            if (poiArray[i].location == location+offset){poiArray[i].state = 1;}
        }
        ffMoves --;
        refreshBoard();
    }  
}



void FireRescue::spray(int location, int direction)
{
    MapCell* cell = m_theBoard.GetCell(location);
    int base = baseValue(location);
    int barrier = m_MapArray[base + baseOffset[direction]];
    int offset;
    if (direction==0){offset = -10;}
    else if (direction==1){offset = -1;}
    else if (direction==2){offset = 1;}
    else {offset = 10;}
    MapCell* dCell = m_theBoard.GetCell(location+offset);
    if ((barrier==0 || barrier==3) && dCell->getSmoke()==true && ffMoves>0)
    {
        dCell->setSmoke(false);
        ffMoves --;
    } 
    if ((barrier==0 || barrier==3) && dCell->getFire()==true && ffMoves>0)
    {
        dCell->setFire(false);
        dCell->setSmoke(true);
        ffMoves --;
    } 
    refreshBoard();
}


void FireRescue::chop(int location, int direction)
{
    MapCell* cell = m_theBoard.GetCell(location);
    int base = baseValue(location);
    int barrier = m_MapArray[base + baseOffset[direction]]; 
    if (barrier < 3 && barrier > 0 && ffMoves>0) 
    {
        m_MapArray[base + baseOffset[direction]] = barrier - 1;
        ffMoves--;
        wallDamage ++;
        if (wallDamage > 21){std::cout << "GAME OVER" << "\n";}
        ui->damage->setText("Damage = " + QString::number(wallDamage));
    }
    refreshBoard();
}


void FireRescue::carry(int slot, int location, int obj, int direction)
{
    MapCell* cell = m_theBoard.GetCell(location);
    int base = baseValue(location);
    int barrier = m_MapArray[base + baseOffset[direction]];
    int offset;
    int poiSlot = 20;
    for (int i=0; i<3; i++)
    {
        if (poiArray[i].location == location && poiArray[i].poi != 0) {poiSlot = i;}
    }
    if (direction==0){offset = -10;}
    else if (direction==1){offset = -1;}
    else if (direction==2){offset = 1;}
    else {offset = 10;}
    MapCell* dCell = m_theBoard.GetCell(location+offset);    
    if ((barrier==0 || barrier==3) && dCell->getFire()==false && dCell->getSmoke()==false && ffMoves>1 && poiSlot < 20)
    {
        bool amb = false;
        int target = poiArray[poiSlot].poi;
        ffArray[slot].location += offset;
        ffMoves -=2;
        for (int i=0; i<3; i++){if (poiArray[i].location == ffArray[slot].location){poiArray[i].state = 1;}}
        for (int i=0; i<8; i++)
        {
            if(ffArray[slot].location == ambulance[i]){amb = true;}
        }
        if (amb == true)
        {
            ui->personsSaved->setText("Persons Saved " + QString::number(poiSaved));
            for (int i=0; i<3; i++) 
            {
                if ((poiArray[i].poi == poiArray[poiSlot].poi) &&  poiArray[i].poi != 0) 
                {  
                    poiArray[i].location = 100;
                    lastPoi = i;
                    poiSaved ++;
                    ui->personsSaved->setText("Persons Saved = " + QString::number(poiSaved));
                    break;
                }
            }
            if (poiSaved > 6){std::cout << "WIN!!\n";}
        }
        else
        {
            poiArray[poiSlot].location = location + offset; 
            poiArray[poiSlot].state = 1;        
        }
    refreshBoard();
    } 
}


void FireRescue::refreshBoard()
{
    for (QLabel* label : labels)  
    {
        if (label != nullptr) 
        {
            label->hide();
            delete label;
        }
    }
    labels.clear();

    int slot = 0;
    int extra = 0;
    /******** show fire fighters ***********/
    for (int i=0; i<ffNumber; i++) 
    {
        bool match = false;
        if (ffArray[i].location < 80)
        {
            for (int j=0; j<i; j++)
            {  
                if (ffArray[i].location == ffArray[j].location)     // if the locations are the same
                {
                    int row = ffArray[i].location / 10;
                    int col = ffArray[i].location % 10;
                    ffExtra[slot] = new QLabel( this);
                    ffExtra[slot]->setGeometry(QRect(332+(col*127)+((extra+1)*7), 65+(row*125), 60, 60));
                    ffExtra[slot]->setPixmap(ff[i]);
                    ffExtra[slot]->show();
                    labels.push_back(ffExtra[slot]);
                    match = true;
                    slot++;
                    extra++;
                    j=i;
                } 
            } 
            if (match == false)
            {
                int row = ffArray[i].location / 10;
                int col = ffArray[i].location % 10;
                ffExtra[slot] = new QLabel(this);
                ffExtra[slot]->setGeometry(QRect(332+(col*127), 65+(row*125), 60, 60));
                ffExtra[slot]->setPixmap(ff[i]);
                ffExtra[slot]->show();
                labels.push_back(ffExtra[slot]);  
                match = false;
                slot++;
            }
        }
    }
    /********** show smoke and fire ***********/
    bool found;
    for (int i=0; i<80; i++)
    {
        MapCell* cell = m_theBoard.GetCell(i); 
        bool iSmoke = cell->getSmoke();
        bool iFire = cell->getFire();
        if (iSmoke == true){ui->leftUpperDisk[i]->setPixmap(smoke);}
        if (iFire == true){ui->leftUpperDisk[i]->setPixmap(fire);}
        if (iSmoke==false && iFire==false){ui->leftUpperDisk[i]->setPixmap(QPixmap());}
    }
    /********** show pois ************/
    int multPoi = 0;
    for (int i=0; i<2; i++)
    {
        for (int j=i+1; j<3; j++)
        {
            if (poiArray[i].location == poiArray[j].location){multPoi++;}
        }
    }
    if (multPoi>2){multPoi = 2;}
    for (int i=0; i<3; i++)
    {
        if (poiArray[i].location < 80)
        {
            if (poiArray[i].state == 0)
            {
                makePoiLabel(i, 0);
            }
            else
            {
                if (multPoi > 0)
                {
                    makePoiLabel(i, multPoi);
                    multPoi --;
                }
                else
                {makePoiLabel(i,0);}
            }
        }
    }
    /********** show hazmats ***********/
    for (int i=0; i<4; i++)
    {
        int row = hazmatArray[i] / 10;
        int col = hazmatArray[i] % 10;
        hazmatLabel[i] = new QLabel(this);
        hazmatLabel[i]->setGeometry(QRect(392+(col*127), 5+(row*125), 60, 60));
        hazmatLabel[i]->setPixmap(hazmat);

        hazmatLabel[i]->show();
        labels.push_back(hazmatLabel[i]);
    } 
    /********** show hotSpots ***********/
    for (int i=0; i<12; i++)
    {
        int row = hotSpotArray[i] / 10;
        int col = hotSpotArray[i] % 10;
        hotSpotLabel[i] = new QLabel(this);
        hotSpotLabel[i]->setGeometry(QRect(378+(col*127), 35+(row*125), 60, 60));
        hotSpotLabel[i]->setPixmap(hotSpot);

        hotSpotLabel[i]->show();
        labels.push_back(hotSpotLabel[i]);
    } 
    

    int doorNum;
    for (int i=0; i<178; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (i== doorArray[j]) 
            {
                found = true;
                doorNum = j+1;
                break; 
            }
        }
        if (found == true)
        {
            if (m_MapArray[i] == 0)
            {
                ui->door[doorNum]->setPixmap(QPixmap());
            }
            if (m_MapArray[i] == 3){ui->door[doorNum]->setPixmap(doorOpen);}
            if (m_MapArray[i] == 4){ui->door[doorNum]->setPixmap(doorClosed);}
            found = false;
        }
        if (m_WallArray[i] > 0)
        {
            if (m_MapArray[i]== 1){ui->cube[m_WallArray[i]-1]->setPixmap(greySquare);}
            if (m_MapArray[i]== 0){ui->cube[m_WallArray[i]-1]->setPixmap(blackSquare);}
        }
    }
    ui->tableWidget->raise();
}

void FireRescue::makePoiLabel(int slot, int multPoi)
{
    int row = poiArray[slot].location / 10;
    int col = poiArray[slot].location % 10;
    poiExtra[slot] = new QLabel(this);
    poiExtra[slot]->setGeometry(QRect(392+(col*127)+(multPoi*7), 65+(row*125), 60, 60));
    if (poiArray[slot].state == 0)
    {poiExtra[slot]->setPixmap(poi[11]);}
    else
    {poiExtra[slot]->setPixmap(poi[poiArray[slot].poi]);}

    poiExtra[slot]->show();
    labels.push_back(poiExtra[slot]);
}


void FireRescue::placeSmoke(int location)
{
    bool flareUpOn = false;
    std::cout << "Smoke Location = " << location << "\n";
    MapCell* cell = m_theBoard.GetCell(location);
    for (int i=0; i<12; i++)
    {
        if (location == hotSpotArray[i])
        {
            flareUpCheck(location);
            flareUpOn = true;
            std::cout << "Hot Spot Hit at " << location << "\n";
            for (int j=0; j<12; j++){std::cout << hotSpotArray[j] << " ";}
            std::cout << "\n";
        }
    }
    cell->setSmoke(true);
    if (cell->getFire() == false) 
    {
        checkSmokeFire(location);
    }
    else if (cell->getSmoke() == true && cell->getFire() == false)
    {
        placeFire(location);
    }
    else
    {
        explosion(location);
    }
    if (flareUpOn == true){fireTurn();}
}


void FireRescue::checkSmokeFire(int location)
{
    MapCell* cell = m_theBoard.GetCell(location);
    if (cell->getSmoke()==true)
    {
        std::vector<MapCell*> nearCells = adjacentCells(location);  //  populate the vector with the surrounding cells
        bool setFire = false;
        for (int i=0; i<4; i++)                                     // step through each cell
        {
            if (nearCells[i] != nullptr)
            {  
                int base = baseValue(location);
                int barrier = m_MapArray[base + baseOffset[i]];
                if (nearCells[i]->getFire() == true && barrier == 3 || nearCells[i]->getFire() == true && barrier == 0 )
                {
                    setFire = true;                                 //recursive call to place fire
                }
            }
        }
        if (setFire == true) {placeFire(location);}
    }
}


void FireRescue::placeFire(int location)
{
    MapCell* cell = m_theBoard.GetCell(location);
    if (cell->getFire() == false)                      // there is no explosion
    {
        cell->setFire(true);                           // set fire to true and...
        cell->setSmoke(false);                         // turn off smoke so we can't infinitely loop here
        /******* check for pois to be destroyed *******/
        for (int i=0; i<3; i++)
        {
            if (poiArray[i].location==location)
            {
                if (poiArray[i].poi != 0)
                {
                    poiLost++;
                    ui->personsLost->setText("Persons lost = " + QString::number(poiLost));
                    if (poiLost > 3){std::cout << "Game Lost\n";}
                }
                poiArray[i].location = 100;
                lastPoi = i;
            }
        }
        /******** check for hazmats to cause an explosion ********/
        for (int i=0; i<4; i++)
        {
            if (location == hazmatArray[i])
            {
                hazmatArray[i] = 100;
                explosion(location);
            }
        }
        /********* check for fire fighters to get knocked down *********/
        double distanceArray[8];
        for (int i=0; i<6; i++)
        {
            if (location == ffArray[i].location)
            {
                int row = location%10;
                int col = location/10;
                for (int j=0; j<8; j++)
                {
                    int rowJ = ambulance[j]%10;
                    int colJ = ambulance[j]/10;
                    double dist = std::sqrt(((row-rowJ)*(row-rowJ)) + ((col-colJ)*(col-colJ)));
                    distanceArray[j] = dist;
                }
            int size = sizeof(distanceArray) / sizeof(distanceArray[0]);
            double* minDist = std::min_element(distanceArray, distanceArray + size);
            for (int j=0; j<8; j++)
            {
                if (distanceArray[j] == *minDist){ffArray[i].location = ambulance[j];}
            }
            }
        }
        /********** check for hot spots to cause a flare up ************/

        std::vector<MapCell*> nearCells = adjacentCells(location);    //  populate the vector with the surrounding cells
        for (int i=0; i<4; i++)                                       // step through each cell
        {    
            if (nearCells[i] != nullptr)
            {
                int base = baseValue(location);
                int barrier = m_MapArray[base + baseOffset[i]];
                if (barrier == 3) {barrier = 0;}                    // if there is a door and it is open then set barrier to 0
                if (nearCells[i]->getSmoke() == true && barrier == 0)
                {
                    placeFire(nearCells[i]->getID());               //recursive call to place fire
                }
            }
        }
    }
   refreshBoard();  
}


void FireRescue::placeHotSpot(int location)
{
    for (int i=0; i<12; i++)
    {
        if (hotSpotArray[i] > 80)
        {
            hotSpotArray[i] = location;
            hotSpots -= 1;
            ui->hs[hotSpots]->setPixmap(QPixmap());
            i=12;
            break;
        }
    }
    refreshBoard();
}


void FireRescue::flareUpCheck(int location)
{
    if (flareUp == false)
    {
        placeHotSpot(location);
    }
    flareUp = true;
    std::cout << "flareUp = " << flareUp << "\n";
}


void FireRescue::cycleDoor(int location, int direction)
{
    MapCell* cell = m_theBoard.GetCell(location);
    int base = baseValue(location);
    int barrier = m_MapArray[base + baseOffset[direction]];
    if (barrier==4 && action==4 && ffMoves>0) 
    {
        int otherSideOfDoor = getOthersideOfWall(direction, location);
        m_MapArray[base + baseOffset[direction]] = 3;         
        MapCell* otherCell = m_theBoard.GetCell(otherSideOfDoor);    
        checkBreach(location);
        ffMoves --;
        checkBreach(otherSideOfDoor);
    }
    if (barrier==3 && action==5)
    {
        m_MapArray[base + baseOffset[direction]]= 4;
        ffMoves --;
    }
    refreshBoard();   
}


void FireRescue::checkBreach(int location)
{
    MapCell* cell = m_theBoard.GetCell(location);
    std::vector<MapCell*> nearCells = adjacentCells(location);      //  populate the vector with the surrounding cells
        bool setFire = false;
        //cell->printBoard();
        for (int i=0; i<4; i++)                                     // step through each cell
        {
            if (nearCells[i] != nullptr)
            {
                int base = baseValue(location);
                int barrier = m_MapArray[base + baseOffset[i]];     // get the current cell's wall/door value in this direction
                if (barrier < 4) {barrier = 0;}                    // if there is a door and it is open then set barrier to 0
                if (nearCells[i]->getFire() == true && barrier == 0 && cell->getSmoke() == true)
                {
                    setFire = true;                                 //recursive call to place fire
                }
            }
        }
        if (setFire == true) {placeFire(location);}
}

void FireRescue::explosion(int location)
{ 
    MapCell* cell = m_theBoard.GetCell(location);
    placeFire(location);
    delayTimer(50);
    placeHotSpot(location);
    delayTimer(50);
    std::vector<MapCell*> nearCells = adjacentCells(location); 
    for (int i=0; i<4; i++)
    {
        if (nearCells[i] != nullptr)
            {
                int base = baseValue(location);
                int barrier = m_MapArray[base + baseOffset[i]];     // get the current cell's wall/door value in this direction

                if(barrier > 0 && barrier < 3)
                {
                    damageWall(i,location, base);
                }

                barrier = m_MapArray[base + baseOffset[i]]; 


                if (nearCells[i]->getFire() == true && barrier == 0 )
                {
                    shockWave(i,nearCells[i]->getID()) ;                               //recursive call to place fire
                }
                else if(nearCells[i]->getFire() == false and barrier == 0)
                {
                    placeFire(nearCells[i]->getID());
                }   

                if (barrier > 2 && barrier < 9)                      // if there is a door blow it off its hinges
                {
                    barrier = 0;
                    m_MapArray[base + baseOffset[i]] = 0; 
                }               
            }
    }
}


void FireRescue::shockWave(int direction, int location)
{
    std::vector<MapCell*> nearCells = adjacentCells(location); 
    int base = baseValue(location);
    int barrier = m_MapArray[base + baseOffset[direction]];     // get the current cell's wall/door value in this direction
    if(barrier > 0 && barrier < 3)
    {
        damageWall(direction, location, base);
    }

    barrier = m_MapArray[base + baseOffset[direction]]; 

    if (barrier < 9)
    {
        if (nearCells[direction]->getFire() == true && barrier == 0 )
        {
            shockWave(direction,nearCells[direction]->getID()) ;                               //recursive call to place fire
        }
        else if(nearCells[direction]->getFire() == false and barrier == 0)
        {
            placeFire(nearCells[direction]->getID());
        }               
    } 

    if (barrier > 2 && barrier < 9)                      // if there is a door blow it off its hinges
    {
        barrier = 0;
        m_MapArray[base + baseOffset[direction]] = 0; 
    }  
}


void FireRescue::damageWall(int direction, int location, int base)
{
    wallDamage ++;
    if (wallDamage > 21){std::cout << "GAME OVER\n";}
    ui->damage->setText("Damage = " + QString::number(wallDamage));
    int barrier = m_MapArray[base + baseOffset[direction]];
    m_MapArray[base + baseOffset[direction]] = barrier - 1;
}


std::vector<MapCell*> FireRescue::adjacentCells(int location)
{
    std::vector<MapCell*> nextCells(4, nullptr);
    nextCells[0] = (location-10 < 80 && location-10 > -1) ? m_theBoard.GetCell(location-10) : nullptr;      // if the cell above is not on map
    nextCells[1] = (location%10 != 0) ? m_theBoard.GetCell(location-1) : nullptr;                         // cell to the left not on map
    nextCells[2] = ((location+1)%10 != 0 || location == 0) ? m_theBoard.GetCell(location+1) : nullptr;    // cell right not on map
    nextCells[3] = (location+10 < 80 && location+10 > -1) ? m_theBoard.GetCell(location+10) : nullptr;      // cell below not on map
    return nextCells;
}


int FireRescue::baseValue(int location)
{
    int row = location / 10;
    int col = location % 10;
    int base = (row * 21) + col;
    return base;
}


int FireRescue::getOthersideOfWall(int direction, int location)
{
    int otherSideOfDoor;
    if (direction==0) {otherSideOfDoor = location - 10;}
    if (direction==1) {otherSideOfDoor = location - 1;}
    if (direction==2) {otherSideOfDoor = location +1;}
    if (direction==3) {otherSideOfDoor = location + 10;}
    return otherSideOfDoor;
}

void FireRescue::fireTurn()
{
    for (int i=0; i<80; i++){checkSmokeFire(i);}
    rollDice(11);
    int location = ((value6)*10)+(value8);
    placeSmoke(location);
    refreshBoard();
    delayTimer(500);
    bool newPoi = false;
    for (int i=0; i<3; i++)
    {
        if (poiArray[i].location > 80)
        {
            location = newPoiLocation();
            int poi = poiList.back();
            bool match = false;
            poiList.pop_back();
            poiArray[i].poi = poi;
            poiArray[i].location = location;
            // check to see if a poi was dropped on a ff
            for (int i=0; i<ffNumber; i++){if (location == ffArray[i].location){match = true;}}
            if (match == true){poiArray[i].state = 1;}
            else {poiArray[i].state = 0;}
            sortPoi();
            refreshBoard();
        }
    } 
    delayTimer(500);
    nextPlayer();
}

int FireRescue::carryDialog()
{
    QDialog carryDialog;

    QPushButton carryPoi("Carry Poi", &carryDialog);
    carryPoi.setGeometry(100, 50, 100, 50); 

    QPushButton carryHazmat("Carry Hazmat", &carryDialog);
    carryPoi.setGeometry(0, 50, 100, 50); 

    // Variable to store the result (0 or 1)
    int toCarry = -1; // Initialize it to an invalid value

    // Connect the button's click signals to set the variable toCarry and close the dialog
    QObject::connect(&carryPoi, &QPushButton::clicked, [&toCarry, &carryDialog]() {
        toCarry = 0;
        carryDialog.accept(); // Close the dialog
    });

    QObject::connect(&carryHazmat, &QPushButton::clicked, [&toCarry, &carryDialog]() {
        toCarry = 1;
        carryDialog.accept(); // Close the dialog
    });

    // Show the dialog
    carryDialog.exec(); // Blocks until the dialog is closed

    // Now, the variable "toCarry" contains the selected value (0 or 1)
    return toCarry;
}