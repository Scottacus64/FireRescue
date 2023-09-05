#include "FireRescue.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <QTimer>

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
    poi0.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi0.png");

    poi1.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi1.png");
    poi2.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi2.png");
    poi3.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi3.png");
    poi4.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi4.png");
    poi5.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi5.png");
    poi6.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi6.png");
    poi7.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi7.png");
    poi8.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi8.png");
    poi9.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi9.png");
    poi10.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi10.png");

    poiBlank.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/sPOIblank.png");

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

    for (int i=1; i<11; i++) {poiList.push_back(i);}
    for (int i=0; i<5; i++) {poiList.push_back(0);}
    // Shuffle the vector
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(poiList.begin(), poiList.end(), rng);

    ui->setupUi(this);
}


FireRescue::~FireRescue()
{
    delete ui;
}


void FireRescue::on_tableWidget_cellClicked(int row, int col)
{
    int gridLocation = (row*10) + col;

    refreshBoard();
}



void FireRescue::setUpGame()
{
    int row = 0;
    int col = 0;
    rollDice(0);
    bool onFire = false;
    int location;
    ui->label->setVisible(true);
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
            delayTimer(500);
        }
        if (startUpSequence == 1)                               // explosion 2
        {
            ui->label->setText("Place Explosion 2");
            onFire = true;
            while (onFire == true )
            {
                onFire = checkNewSpot(1);
                location = ((value6)*10)+(value8);
                std::cout << "Fire Detected: " << value6 << "," << value8 << "\n";
            }
            explosion(location);
            delayTimer(500);
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
                std::cout << "Fire Detected: " << value6 << "," << value8 << "\n";
            }
            explosion(location);
            delayTimer(500);
        }
        if (startUpSequence >2 && startUpSequence <7)           // place Hazmats
        {
            ui->label->setText("Place Hazmat " + QString::number(startUpSequence-2));
            onFire = true;
            bool hazmatHere = true;
            while (onFire == true || hazmatHere == true )
            {
                onFire = checkNewSpot(3);
                location = ((value6)*10)+(value8);
                MapCell* cell = m_theBoard.GetCell(location); 
                hazmatHere = cell->getHazmat();
                std::cout  << value6 << "," << value8 << "fire: " << onFire << " Haz: " << hazmatHere << "\n";
            }
            placeHazmat(location);
            delayTimer(500);
        }
        if (startUpSequence >6 && startUpSequence <10)          // place POI
        {
            ui->label->setText("Place 3 Person " + QString::number(startUpSequence-6));
            onFire = true;
            int poiHere = 20;
            while (onFire == true || poiHere < 14)
            {
                onFire = checkNewSpot(6);
                location = ((value6)*10)+(value8);
                MapCell* cell = m_theBoard.GetCell(location); 
                poiHere = cell->getPoi();
                std::cout  << value6 << "," << value8 << "fire: " << onFire << " Poi: " << poiHere << "\n";
            }
            placePOI(location);
            delayTimer(500);
        }
        if (startUpSequence > 9 && startUpSequence <13)         // place Hot Spots
        {
            ui->label->setText("Place 3 Hot Spot " + QString::number(startUpSequence-9));
            int location;
            bool hotSpotHere = true;
            while (hotSpotHere == true)
            {
                rollDice(startUpSequence);
                location = ((value6)*10)+(value8);
                MapCell* cell = m_theBoard.GetCell(location); 
                hotSpotHere= cell->getHotSpot();
                std::cout << value6 << "," << value8 << " HotSpot: " << hotSpotHere << "\n";
            }
            placeHotSpot(location);
            delayTimer(500);
        }        
    }
    ui->label->setVisible(false);
    player[0]= 6;
    MapCell* cell = m_theBoard.GetCell(6);
    cell->setFireFighter(1);
    refreshBoard();
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
        delayTimer(25);
        if (slot != 2){value8 = die.rollDie(8);}
        value6 = die.rollDie(6);
        ui->D6->setPixmap(D6[value6]);
        ui->D8->setPixmap(D8[value8]);
    }

    
}


void FireRescue::on_startGame_clicked()
{
    setUpGame();
}

void FireRescue::on_rbMove_clicked()
{
    action = 0;
}

void FireRescue::on_rbSpray_clicked()
{
    action = 1;
}

void FireRescue::on_rbChop_clicked()
{
    action = 2;
}

void FireRescue::on_rbCarry_clicked()
{
    action = 3;
}

void FireRescue::on_rbOpen_clicked()
{
    action = 4;
}

void FireRescue::on_rbClose_clicked()
{
    action = 5;
}


void FireRescue::on_arrowU_clicked()
{
    if (player[0]-10>-1)
    {
        if (action==0)
        {
            movePlyer(0, player[0], 0);
        }
        else if (action==1)
        {
            spray(player[0],0);
        }
        else if (action==2)
        {
            chop(player[0],0);
        }
        else if (action==3)
        {
            carry(0, player[0], 0, 0);
        }
        else if (action==4 || action==5)
        {
            cycleDoor(player[0],0);
        }
    }
}


void FireRescue::on_arrowD_clicked()
{
    if ((player[0]+10)<80)
    {
        if (action==0)
        {
            movePlyer(0, player[0], 3);
        }
        else if (action==1)
        {
            spray(player[0],3);
        }
        else if (action==2)
        {
            chop(player[0],3);
        }
        else if (action==3)
        {
            carry(0, player[0], 0, 3);
        }
        else if (action==4 || action==5) 
        {
            cycleDoor(player[0],3);
        }
    }
}


void FireRescue::on_arrowL_clicked()
{
    if (player[0]%10 != 0)
    {
        if (action==0)
        {
            movePlyer(0, player[0], 1);
        }
        else if (action==1)
        {
            spray(player[0],1);
        }
        else if (action==2)
        {
            chop(player[0],1);
        }
        else if (action==3)
        {
            carry(0, player[0], 0, 1);
        }
        else if (action==4 || action==5)
        {
            cycleDoor(player[0],1);
        }
    }
}


void FireRescue::on_arrowR_clicked()
{
    if ((player[0]+1)%10 != 0) 
    {
        if (action==0)
        {
            movePlyer(0, player[0], 2);
        }
        else if (action==1)
        {
            spray(player[0],2);
        }
        else if (action==2)
        {
            chop(player[0],2);
        }
        else if (action==3)
        {
            carry(0, player[0], 0, 2);
        }
        else if (action==4 || action ==5)
        {
            cycleDoor(player[0],2);
        }
    }
}

void FireRescue::movePlyer(int slot, int location, int direction)
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
    if ((barrier==0 || barrier==3) && dCell->getFire()==false)
    {
        cell->setFireFighter(14);
        player[slot]+=offset;
        cell = m_theBoard.GetCell(player[slot]);
        cell->setFireFighter(slot);
        int checkPoi = cell->getPoi();
        if (checkPoi < 11){cell->setPoiState(true);}
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
    if ((barrier==0 || barrier==3) && dCell->getSmoke()==true)
    {
        dCell->setSmoke(false);
    } 
    if ((barrier==0 || barrier==3) && dCell->getFire()==true)
    {
        dCell->setFire(false);
        dCell->setSmoke(true);
    } 
    refreshBoard();
}


void FireRescue::chop(int location, int direction)
{
    MapCell* cell = m_theBoard.GetCell(location);
    int base = baseValue(location);
    int barrier = m_MapArray[base + baseOffset[direction]]; 
    if (barrier < 3 && barrier > 0) {m_MapArray[base + baseOffset[direction]] = barrier - 1;}
    refreshBoard();
}


void FireRescue::carry(int slot, int location, int obj, int direction)
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
    if ((barrier==0 || barrier==3) && dCell->getFire()==false && dCell->getSmoke()==false)
    {
        cell->setFireFighter(14);
        int target = cell->getPoi();
        cell->setPoi(14);
        player[slot]+=offset;
        cell = m_theBoard.GetCell(player[slot]);
        cell->setFireFighter(slot);
        cell->setPoi(target);
        cell->setPoiState(true);
        refreshBoard();
    } 
}


void FireRescue::refreshBoard()
{
    bool found;
    for (int i=0; i<80; i++)
    {
        MapCell* cell = m_theBoard.GetCell(i); 
        bool iSmoke = cell->getSmoke();
        bool iFire = cell->getFire();
        bool iHotSpot = cell->getHotSpot();
        bool iHazmat = cell->getHazmat();
        int  iPoi = cell->getPoi();
        bool poiState = cell->getPoiState();
        int  iFireFighter = cell->getFireFighter();
        if (iSmoke == true){ui->leftUpperDisk[i]->setPixmap(smoke);}
        if (iFire == true){ui->leftUpperDisk[i]->setPixmap(fire);}
        if (iSmoke==false && iFire==false){ui->leftUpperDisk[i]->setPixmap(QPixmap());}
        if (iHotSpot == true){ui->centerDisk[i]->setPixmap(hotSpot);}
        if (iHazmat == true){ui->rightUpperDisk[i]->setPixmap(hazmat);}
        if (iFireFighter < 6)
        {
            ui->leftLowerDisk[i]->setPixmap(ff[iFireFighter]);
        }
        else
        {
            ui->leftLowerDisk[i]->setPixmap(QPixmap());
        }

        if (iPoi < 14)
        {
            if (poiState == true)
            {
                switch (iPoi)
                {
                case 0:
                    ui->rightLowerDisk[i]->setPixmap(poiBlank);
                    break;
                case 1:
                    ui->rightLowerDisk[i]->setPixmap(poi1);
                    break;
                case 2:
                    ui->rightLowerDisk[i]->setPixmap(poi2);
                    break;
                case 3:
                    ui->rightLowerDisk[i]->setPixmap(poi3);
                    break;
                case 4:
                    ui->rightLowerDisk[i]->setPixmap(poi4);
                    break;
                case 5:
                    ui->rightLowerDisk[i]->setPixmap(poi5);
                    break;                        
                case 6:
                    ui->rightLowerDisk[i]->setPixmap(poi6);
                    break;
                case 7:
                    ui->rightLowerDisk[i]->setPixmap(poi7);
                    break;        
                case 8:
                    ui->rightLowerDisk[i]->setPixmap(poi8);
                    break;
                case 9:
                    ui->rightLowerDisk[i]->setPixmap(poi9);
                    break;
                case 10:
                    ui->rightLowerDisk[i]->setPixmap(poi10);
                    break;  
                } 
            }
            else{ui->rightLowerDisk[i]->setPixmap(poi0);}
        }
        if (iPoi>10) {ui->rightLowerDisk[i]->setPixmap(QPixmap());}
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
}


void FireRescue::placeSmoke(int location)
{
    MapCell* cell = m_theBoard.GetCell(location);
    if (cell->getSmoke() == false && cell->getFire() == false) 
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
        setFire == false ? cell->setSmoke(true) : placeFire(location);
    }
    else if (cell->getSmoke() == true && cell->getFire() == false)
    {
        placeFire(location);
    }
    else
    {
        explosion(location);
    }
}


void FireRescue::placeFire(int location)
{
    MapCell* cell = m_theBoard.GetCell(location);
    if (cell->getFire() == false)                      // there is no explosion
    {
        cell->setFire(true);                           // set fire to true and...
        cell->setSmoke(false);                         // turn off smoke so we can't infinitely loop here
        std::vector<MapCell*> nearCells = adjacentCells(location);    //  populate the vector with the surrounding cells
        for (int i=0; i<4; i++)                                       // step through each cell
        {    
            if (nearCells[i] != nullptr)
            {
                int base = baseValue(location);
                int barrier = m_MapArray[base + baseOffset[i]];
                //int barrier = cell->getWall(i);       // get the current cell's wall/door value in this direction
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
    MapCell* cell = m_theBoard.GetCell(location);
    bool hs = cell->getHotSpot();
    if (hotSpots > 0 && hs==false)
    {
        cell->setHotSpot(true);
        hotSpots -= 1;
        ui->hs[hotSpots]->setPixmap(QPixmap());
    }
    refreshBoard();
}

void FireRescue::placeHazmat(int location)
{
    MapCell* cell = m_theBoard.GetCell(location);
    cell->setHazmat(true);
    refreshBoard();
}


void FireRescue::placePOI(int location)
{
    MapCell* cell = m_theBoard.GetCell(location);
    int poi = poiList.back();
    poiList.pop_back();
    cell->setPoi(poi);
    refreshBoard();  
}


void FireRescue::cycleDoor(int location, int direction)
{
    MapCell* cell = m_theBoard.GetCell(location);
    int base = baseValue(location);
    int barrier = m_MapArray[base + baseOffset[direction]];
    if (barrier==4 && action==4) 
    {
        int otherSideOfDoor = getOthersideOfWall(direction, location);
        m_MapArray[base + baseOffset[direction]] = 3;         
        MapCell* otherCell = m_theBoard.GetCell(otherSideOfDoor);    
        checkBreach(location);
        checkBreach(otherSideOfDoor);
    }
    if (barrier==3 && action==5)
    {
        m_MapArray[base + baseOffset[direction]]= 4;
    }
    refreshBoard();   
}


void FireRescue::checkBreach(int location)
{
    MapCell* cell = m_theBoard.GetCell(location);
    std::vector<MapCell*> nearCells = adjacentCells(location);      //  populate the vector with the surrounding cells
        bool setFire = false;
        cell->printBoard();
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
    delayTimer(500);
    placeHotSpot(location);
    delayTimer(500);
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

                if (barrier > 2 && barrier < 9)                      // if there is a door blow it off its hinges
                {
                    barrier = 0;
                    m_MapArray[base + baseOffset[i]] = 0; 
                }   

                if (nearCells[i]->getFire() == true && barrier == 0 )
                {
                    shockWave(i,nearCells[i]->getID()) ;                               //recursive call to place fire
                }
                else if(nearCells[i]->getFire() == false and barrier == 0)
                {
                    placeFire(nearCells[i]->getID());
                }               
            }
    }
}



void FireRescue::shockWave(int direction, int location)
{
    //MapCell* cell = m_theBoard.GetCell(location);
    std::vector<MapCell*> nearCells = adjacentCells(location); 
    int base = baseValue(location);
    int barrier = m_MapArray[base + baseOffset[direction]];     // get the current cell's wall/door value in this direction
    if(barrier > 0 && barrier < 3)
    {
        damageWall(direction, location, base);
    }

    barrier = m_MapArray[base + baseOffset[direction]]; 

    if (barrier > 2 && barrier < 9)                      // if there is a door blow it off its hinges
    {
        barrier = 0;
        m_MapArray[base + baseOffset[direction]] = 0; 
    }   

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
}


void FireRescue::damageWall(int direction, int location, int base)
{
    wallDamage ++;
    if (wallDamage > 21){std::cout << "GAME OVER" << "\n";}
    int barrier = m_MapArray[base + baseOffset[direction]];
    m_MapArray[base + baseOffset[direction]] = barrier - 1;
}


std::vector<MapCell*> FireRescue::adjacentCells(int location)
{
   // MapCell* cell = m_theBoard.GetCell(location);
    std::vector<MapCell*> nextCells(4, nullptr);
    nextCells[0] = (location-10 < 80 && location-10 > -1) ? m_theBoard.GetCell(location-10) : nullptr;      // if the cell above is not on map
    nextCells[1] = (location%10 != 0) ? m_theBoard.GetCell(location-1) : nullptr;                         // cell to the left not on map
    nextCells[2] = ((location+1)%10 != 0 || location == 0) ? m_theBoard.GetCell(location+1) : nullptr;    // cell right not on map
    nextCells[3] = (location+10 < 80 && location+10 > -1) ? m_theBoard.GetCell(location+10) : nullptr;      // cell below not on map
    //for (int i=0; i<4; i++){std::cout << nextCells[i] << " ";}
    //std::cout << "\n";
    return nextCells;
}


void FireRescue::printSmoke(int location)
{
    MapCell* cell = m_theBoard.GetCell(location);
    bool smoke = cell->getSmoke();
    //if (location%10 == 0 && location >0) {std::cout << "\n";}
    //std::cout << smoke;
    
}

void FireRescue::printFire(int location)
{
    MapCell* cell = m_theBoard.GetCell(location);
    bool fire = cell->getFire();
    //if (location%10 == 0 && location >0) {std::cout << "\n";}
    //std::cout << fire;
    
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

