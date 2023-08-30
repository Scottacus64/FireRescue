#include "FireRescue.h"
#include <iostream>
#include <string>
#include <vector>

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
    poi11.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi11.png");
    poi12.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoi12.png");
    poi13.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/spoiBlank.png");
    greySquare.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/greyCube.png");
    blackSquare.load("/Users/scottmiller/VSC/CPP/FireRescue/Resources/blackCube.png");

    Board m_theBoard = Board();
    m_MapArray = MapCell::getMapArray();
    m_WallArray = MapCell::getWallArray();

    ui->setupUi(this);
}


FireRescue::~FireRescue()
{
    delete ui;
}


void FireRescue::on_tableWidget_cellClicked(int row, int col)
{
    int gridLocation = (row*10) + col;
    if (smokeOn == true)
    {
        placeSmoke(gridLocation);
    }
    else if (fireOn == true)
    {
        placeFire(gridLocation);
    }
    else
    {
        cycleDoor(gridLocation);
    }
    refreshBoard();
}



void FireRescue::setUpGame()
{
    // roll dice for first explosion
    int row = 0;
    int col = 0;
    int value8 = die.rollDie(8);
    if (value8 < 5)
    {
        row = 2;
        col = value8+1;
    }
    else
    {
        row = 3;
        col = value8 - 3;
    }
    //int location = (row*8) + col;
    int location = 19;
    placeFire(location);
    QString text = ("Fire Started:" + QString::number(location));
    ui->label->setText(text);

    refreshBoard();
}


void FireRescue::on_startGame_clicked()
{
    setUpGame();
}

void FireRescue::on_doorB_clicked()
{
    doorOn = true;
    fireOn = false;
    smokeOn = false;
    refreshBoard();
}

void FireRescue::on_fireB_clicked()
{
    doorOn = false;
    fireOn = true;
    smokeOn = false;
}

void FireRescue::on_smokeB_clicked()
{
    doorOn = false;
    fireOn = false;
    smokeOn = true;
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
        int iPoi = cell->getPoi();
        int iFireFighter = cell->getFireFighter();
        if (iSmoke == true){ui->leftUpperDisk[i]->setPixmap(smoke);}
        if (iFire == true){ui->leftUpperDisk[i]->setPixmap(fire);}
        if (iHotSpot == true){ui->centerDisk[i]->setPixmap(hotSpot);}
        if (iHazmat == true){ui->rightUpperDisk[i]->setPixmap(hazmat);}

        if (iPoi < 14)
        {
            switch (iPoi)
            {
            case 0:
                ui->rightLowerDisk[i]->setPixmap(poi0);
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
            case 11:
                ui->rightLowerDisk[i]->setPixmap(poi11);
                break;
            case 12:
                ui->rightLowerDisk[i]->setPixmap(poi12);
                break;
            case 13:
                ui->rightLowerDisk[i]->setPixmap(poi13);
                break;   
            } 
        }
    }
    int doorNum;
    for (int i=0; i<178; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (i== doorArray[j]) 
            {
                std::cout << "Slot = " << i << " door value = " << m_MapArray[i] << "\n";
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
                std::cout << "***** i = " << i << " Base = " << base << "get fire = " << nearCells[i]->getFire() <<  " Barrier = " << barrier <<"\n";
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
        std::cout << "location = " << location << "\n";
        for (int i=0; i<80; i++){printSmoke(i);}
        std::cout << "\n...........................\n";
        for (int i=0; i<80; i++){printFire(i);}
        std::cout << "\n\n";
        cell->printBoard();
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


void FireRescue::cycleDoor(int location)
{
    MapCell* cell = m_theBoard.GetCell(location);
    std::cout << "............\n";
    for (int i=0; i<4; i++)                                     // step through each cell
    {  
        int base = baseValue(location);
        int barrier = m_MapArray[base + baseOffset[i]];
        std::cout << "\ndirection: " << i  << " barrier = " << barrier <<"\n";
        if (barrier == 4)
        {
            int otherSideOfDoor = getOthersideOfWall(i, location);
            m_MapArray[base + baseOffset[i]] = 3;         
            MapCell* otherCell = m_theBoard.GetCell(otherSideOfDoor);    
            checkBreach(location);
            checkBreach(otherSideOfDoor);
        }
        if (barrier == 3)
        {
            m_MapArray[base + baseOffset[i]]= 4;
        }
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
        std::cout << "location = " << location << "\n";
        for (int i=0; i<80; i++){printSmoke(i);}
        std::cout << "\n...........................\n";
        for (int i=0; i<80; i++){printFire(i);}
        std::cout << "\n\n";

}

void FireRescue::explosion(int location)
{ 
    MapCell* cell = m_theBoard.GetCell(location);
    cell->setHotSpot(true);
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
    for (int i=0; i<4; i++){std::cout << nextCells[i] << " ";}
    std::cout << "\n";
    return nextCells;
}


void FireRescue::printSmoke(int location)
{
    MapCell* cell = m_theBoard.GetCell(location);
    bool smoke = cell->getSmoke();
    if (location%10 == 0 && location >0) {std::cout << "\n";}
    std::cout << smoke;
    
}

void FireRescue::printFire(int location)
{
    MapCell* cell = m_theBoard.GetCell(location);
    bool fire = cell->getFire();
    if (location%10 == 0 && location >0) {std::cout << "\n";}
    std::cout << fire;
    
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

