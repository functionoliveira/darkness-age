using namespace std;

void up(Person* p, int lvl)
{
    p->SetLevel(lvl);
    for(int i = 1; i < lvl; i++)
    {
        p->Up(BackgroundEnumerator::WARRIOR);
    }
}

pair<Person*, int> EnemyFactory(char type, int level=1)
{
    Person* human;
    Person* orc;
    Person* elf;
    Person* dwarf;
    Person* brocks;
    BackgroundEnumerator bckg = BackgroundEnumerator::WARRIOR;
    switch (type)
    {
    case '1':
        human = new Human("Humano", bckg, bckg, bckg);
        up(human, level);
        return make_pair(human, (11 + (level * 2)));
    case '2':
        orc = new Orc("Orc", bckg, bckg, bckg);
        up(orc, level);
        return make_pair(orc, (12 + (level * 3)));
    case '3':
        elf = new Elf("Elfo", bckg, bckg, bckg);
        up(elf, level);
        return make_pair(elf, (11 + (level * 2)));
    case '4':
        dwarf = new Dwarf("Anao", bckg, bckg, bckg);
        up(dwarf, level);
        return make_pair(dwarf, (11 + (level * 2)));
    case '5':
        brocks = new Brocks("Brocks", bckg, bckg, bckg);
        up(brocks, level);
        return make_pair(brocks, (15 + (level * 3)));
    case '6':
        return make_pair(new Wolf(level), (9 + (level * 1)));
    default:
        human = new Human("Humano", bckg, bckg, bckg);
        up(human, level);
        return make_pair(human, (11 + (level * 2)));
    }
}