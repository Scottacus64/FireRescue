#include "MapCell.h"
#include <iostream>
#include <unordered_map>
#include <utility> // For std::pair

int MapCell::m_theMap[110] = {           2,2,2,2,2,0,2,2,
                                        2,0,0,4,0,2,0,0,2,
                                         0,0,0,0,0,0,0,0,
                                        2,0,0,2,0,4,0,0,2,
                                         0,0,2,2,2,2,2,4,
                                        0,0,4,0,0,0,2,0,2,
                                         0,0,0,0,0,0,0,0,
                                        2,0,2,0,0,0,4,0,0,
                                         2,2,2,4,2,2,2,2,
                                        2,0,0,0,0,2,0,2,2,
                                         0,0,0,0,0,0,0,0,
                                        2,0,0,0,0,4,0,4,2,
                                         2,2,0,2,2,2,2,2   };   

MapCell::MapCell()
{}


MapCell::MapCell(int gridLocation)
    : fire(false), smoke(false), hazmat(false), hotSpot(false), poi(14), fireFighter(14), checked(false), id(gridLocation)
{
    // Insert key-value pairs
    cellToDoorMap.insert(std::make_pair(2, 1));
    cellToDoorMap.insert(std::make_pair(3, 1));
    cellToDoorMap.insert(std::make_pair(12, 2));
    cellToDoorMap.insert(std::make_pair(13, 2));
    cellToDoorMap.insert(std::make_pair(15, 4));
    cellToDoorMap.insert(std::make_pair(17, 3));
    cellToDoorMap.insert(std::make_pair(18, 3));
    cellToDoorMap.insert(std::make_pair(23, 4));
    cellToDoorMap.insert(std::make_pair(27, 6));
    cellToDoorMap.insert(std::make_pair(29, 5));
    cellToDoorMap.insert(std::make_pair(30, 5));
    cellToDoorMap.insert(std::make_pair(35, 6));
    cellToDoorMap.insert(std::make_pair(44, 7));
    cellToDoorMap.insert(std::make_pair(45, 7));
    cellToDoorMap.insert(std::make_pair(46, 8));
    cellToDoorMap.insert(std::make_pair(47, 8));


    
    /****** this looks through the map and sets where the walls and doors are **********/
    int row = gridLocation / 8;
    int col = gridLocation % 8;
    int base = (row * 17) + col;
    wallArray[0] = m_theMap[base];
    wallArray[1] = m_theMap[base + 8];
    wallArray[2] = m_theMap[base + 9];
    wallArray[3] = m_theMap[base + 17];
    door = 0;
    doorState = 0;
    for (int i=0; i<4; i++)
    {
        if (wallArray[i]> 2) 
        { 
            door = cellToDoorMap[gridLocation];
            doorState = wallArray[i];
        }
    }

}


MapCell::~MapCell()
{}


bool MapCell::getSmoke()
{ return smoke;}


bool MapCell::getFire()
{return fire;}


bool MapCell::getHazmat()
{return hazmat;}


bool MapCell::getHotSpot()
{return hotSpot;}


int MapCell::getPoi()
{return poi;}


int MapCell::getFireFighter()
{return fireFighter;}


//int MapCell::getWall(int side)
//{return wallArray[side];}


//int MapCell::getMapWall(int wall)
//{return m_theMap[wall];}


int MapCell::getID()
{return id;}


//int MapCell::getDoor()
//{return door;}


//int MapCell::getDoorState()
//{return doorState;}


void MapCell::setSmoke(bool iSmoke)
{ smoke = iSmoke;}


void MapCell::setFire(bool iFire)
{fire = iFire;}


void MapCell::setHazmat(bool iHazmat)
{hazmat = iHazmat;}


void MapCell::setHotSpot(bool iHotSpot)
{hotSpot = iHotSpot;}


void MapCell::setPoi(int iPoi)
{poi = iPoi;}


void MapCell::setFireFighter(int iFireFighter)
{fireFighter = iFireFighter;}


void MapCell::printBoard()
{ 
    int slot = 0;
    for (int i =0; i<7; i++) 
    {
        std::cout << " ";
        for (int j=0; j<8; j++)
        {
            std::cout << m_theMap[slot] << " ";
            slot ++;
        }
        std::cout << "\n"; 
        if (i<6)
        {
            for (int k=0; k<9; k++)
            {
                std::cout << m_theMap[slot] << " ";
                slot ++;
            }
                std::cout << "\n"; 
        }
    }
    std::cout << "\n";
}



int* MapCell::getMapArray() 
{
    std::cout << "address of m_theMap from the MapCell class = " << &m_theMap << "\n";
    return m_theMap;
}


