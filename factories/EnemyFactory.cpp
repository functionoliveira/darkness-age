using namespace std;

pair<Person*, int> EnemyFactory(char type, int level=1)
{
    BackgroundEnumerator bckg = BackgroundEnumerator::WARRIOR;
    switch (type)
    {
    case '1':
        return make_pair(new Human("Humano", bckg, bckg, bckg), (11 + (level * 2)));
    case '2':
        return make_pair(new Orc("Orc", bckg, bckg, bckg), (12 + (level * 3)));
    case '3':
        return make_pair(new Elf("Elfo", bckg, bckg, bckg), (11 + (level * 2)));
    case '4':
        return make_pair(new Dwarf("Anao", bckg, bckg, bckg), (11 + (level * 2)));
    case '5':
        return make_pair(new Brocks("Brocks", bckg, bckg, bckg), (15 + (level * 3)));
    case '6':
        return make_pair(new Wolf(level), (9 + (level * 1)));
    default:
        return make_pair(new Human("Humano", bckg, bckg, bckg), (11 + (level * 2)));
    }
}