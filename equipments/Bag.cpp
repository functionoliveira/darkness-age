#include <iostream>
#include <map>

using namespace std;

class Bag
{
    private:
        int size;
        string name;
        map<int, pair<Equipment*, int>> slots;
        int key = 1;
    public:
        Bag(string n, int s)
        {
            name = n;
            size = s;
        }

        string GetName()
        {
            return name;
        }

        void AddItem(Equipment* item, int qty)
        {
            if (slots.size() < size)
            {
                pair<Equipment*, int> value = make_pair(item, qty);
                slots.insert(make_pair(key, value));
                key = slots.size() + 1;
            }
        }

        void RemoveItem(int k)
        {
            slots.erase(k);
            key = k;
        }

        map<int, pair<Equipment*, int>> GetItems()
        {
            return slots;
        }

        Equipment* GetItemsByKey(int k)
        {
            return slots.find(k)->second.first;
        }

        int GetSize()
        {
            return size;
        }

        int GetBusy()
        {
            return slots.size();
        }
};