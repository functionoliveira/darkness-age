#include <iostream>

using namespace std;

class Action
{
    public:
        int id;
        string name;
        int cost;

        Action(int i, string n, int c)
        {
            id = i;
            name = n;
            cost = c;
        }
};