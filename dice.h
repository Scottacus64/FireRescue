

class Dice
{
private:
    int sides;
    int value;
    bool clicked;

public:
    Dice();
    Dice(int dieSides);
    ~Dice();
    int  rollDie(int dieSides);
    void clickDie();
    bool getClicked();
    void setClicked();
    void setValue(int value);
    int  getValue();
};