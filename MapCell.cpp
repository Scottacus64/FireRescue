#include "MapCell.h"
#include <iostream>
#include <unordered_map>
#include <utility> // For std::pair

int MapCell::m_theMap[178] = {           9,9,9,9,9,9,9,9,9,9,
                                        9,0,0,0,0,0,0,0,0,0,9,
                                         0,2,2,2,2,2,0,2,2,0,
                                        9,2,0,0,4,0,2,0,0,2,9,
                                         0,0,0,0,0,0,0,0,0,0,
                                        9,2,0,0,2,0,4,0,0,2,9,
                                         0,0,0,2,2,2,2,2,4,0,
                                        9,0,0,4,0,0,0,2,0,2,9,
                                         0,0,0,0,0,0,0,0,0,0,
                                        9,2,0,2,0,0,0,4,0,0,9,
                                         0,2,2,2,4,2,2,2,2,0,
                                        9,2,0,0,0,0,2,0,2,2,9,
                                         0,0,0,0,0,0,0,0,0,0,
                                        9,2,0,0,0,0,4,0,4,2,9,
                                         0,2,2,0,2,2,2,2,2,0,
                                        9,0,0,0,0,0,0,0,0,0,9,  
                                         9,9,9,9,9,9,9,9,9,9     };   

int MapCell::m_theWalls[178] = {         0,0,0,0,0,0,0,0,0,0,
                                        0,0,0,0,0,0,0,0,0,0,0,
                                         0,1,2,3,4,5,0,6,7,0,
                                        0,8,0,0,0,0,9,0,0,10,9,
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

MapCell::MapCell()
{}


MapCell::MapCell(int gridLocation)
    : fire(false), smoke(false), hazmat(false), hotSpot(false), poi(20), fireFighter(14), checked(false), id(gridLocation)
{}


MapCell::~MapCell()
{}


bool MapCell::getSmoke()
{return smoke;}


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


int MapCell::getID()
{return id;}


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
    for (int i =0; i<9; i++) 
    {
        std::cout << " ";
        for (int j=0; j<10; j++)
        {
            std::cout << m_theMap[slot] << " ";
            slot ++;
        }
        std::cout << "\n"; 
        if (i<8)
        {
            for (int k=0; k<11; k++)
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
    return m_theMap;
}


int* MapCell::getWallArray() 
{
    return m_theWalls;
}


