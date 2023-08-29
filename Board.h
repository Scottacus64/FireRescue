#ifndef BOARD_H
#define BOARD_H

#include "MapCell.h"
#include <vector>

class Board{
public:
    Board();
    ~Board();
    MapCell* GetCell(int index);
private:
std::vector<MapCell> m_theBoard;
    
};
#endif // BOARD_H