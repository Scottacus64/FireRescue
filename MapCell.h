#ifndef MAPCELL_H
#define MAPCELL_H

#include <iostream>


class MapCell
{

public:
    MapCell();
    MapCell(int gridLocation);
    ~MapCell();
    static int* getMapArray() ;

    int id;
    bool getSmoke();
    bool getFire();
    bool getHazmat();
    bool getHotSpot();
    bool getChecked();
    int  getPoi();
    int  getFireFighter();
    int  getID();


    void setSmoke(bool smoke);
    void setFire(bool fire);
    void setHazmat(bool hazmat);
    void setHotSpot(bool hotSpot);
    void setChecked(bool checked);
    void setPoi(int poi);
    void setFireFighter(int fireFighter);
    void printBoard();


private:
    static int m_theMap[178];
                         
    bool fire;
    bool smoke;
    bool hazmat;
    bool checked;
    int  poi;
    bool hotSpot;
    int  fireFighter;
    int  wallArray[4];
    int  door;
    int  doorState;
    int  m_index;
    std::unordered_map<int, int> cellToDoorMap;



    // door values 4 = closed, 3 = open, 0 = destroyed

};
#endif // MAPCELL_H