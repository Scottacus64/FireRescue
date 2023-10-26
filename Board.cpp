
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
   if( index>-1 && index<80)
   {return &m_theBoard[index];} 
   else 
   {return nullptr;}
}

void Board::clearBoard()
{
   m_theBoard.clear();
}

