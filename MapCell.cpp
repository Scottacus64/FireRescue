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
                                         9,2,2,0,2,2,2,2,2,0,
                                        9,0,0,0,0,0,0,0,0,0,9,  
                                         9,9,9,9,9,9,9,9,9,9     };   

MapCell::MapCell()
{}


MapCell::MapCell(int gridLocation)
    : fire(false), smoke(false), hazmat(false), hotSpot(false), poi(14), fireFighter(14), checked(false), id(gridLocation)
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
    std::cout << "address of m_theMap from the MapCell class = " << &m_theMap << "\n";
    return m_theMap;
}


