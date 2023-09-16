#ifndef MAPCELL_H
#define MAPCELL_H

#include <iostream>
#include <vector>
#include <algorithm>


class MapCell
{

public:
    MapCell();
    MapCell(int gridLocation);
    ~MapCell();
    static int* getMapArray() ;
    static int* getWallArray();

    int id;
    bool getSmoke();
    bool getFire();
    bool getHazmat();
    bool getHotSpot();
    bool getChecked();
    int  getID();


    void setSmoke(bool smoke);
    void setFire(bool fire);
    void setHazmat(bool hazmat);
    void setHotSpot(bool hotSpot);
    void setChecked(bool checked);
    void printBoard();

private:
    static int m_theMap[178];
    static int m_theWalls[178];
    static int m_poiList[16];
                         
    bool fire;
    bool smoke;
    bool hazmat;
    bool checked;
    bool hotSpot;
    
    int  wallArray[4];
    int  door;
    int  doorState;
    int  m_index;
    
    std::unordered_map<int, int> cellToDoorMap;
};
#endif // MAPCELL_H