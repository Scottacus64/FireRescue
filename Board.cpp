
#include "Board.h"


Board::Board() 
{
     for (int i=0; i <80; i++) 
     {
        MapCell* pMapCell = new MapCell(i);
        m_theBoard.push_back(*pMapCell);
     }
}

Board::~Board()
{}



MapCell* Board::GetCell(int index) 
{
    return &m_theBoard[index];
}

