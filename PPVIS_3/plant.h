#ifndef PLANT_H
#define PLANT_H

const int MAX_LIFE_POINTS = 4;

class Plant{
private:
    int life_points;

public:
    Plant();

    bool next_step();

    void set_life_points(int points);

    int get_life_points();
};

#endif  