#include "dice.h"
#include <iostream>

using namespace std;

Dice::Dice()
{
    using std::srand;
    using std::time;
    value = 0;
    sides = 6;
    clicked = false;
    srand((unsigned int) time(0));
}


Dice::Dice(int dieSides)
{
    using std::srand;
    using std::time;
    value = 0;
    sides = dieSides;
    clicked = false;
    srand((unsigned int) time(0));
}

Dice::~Dice()
{}

int Dice::rollDie(int dieSides)
{
    int returnValue;
    int sides = dieSides;
    returnValue = (rand() % sides) + 1;
    if (clicked == false) {value = returnValue;}
    return value;
}

void Dice::clickDie()
{
    clicked = !clicked;
}

void Dice::setClicked()
{
    clicked = false;
}

bool Dice::getClicked()
{
    return clicked;
}

void Dice::setValue(int inputValue)
{
    value = inputValue;
}

int Dice::getValue()
{
    return value;
}