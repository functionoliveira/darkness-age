class Prologue
{
    public:
        Scene(Person* p, Interface i)
        {
            person = p;
            interface = i;
        }

        void Run()
        {
            switch (person->GetRace())
            {
                case RaceEnumerator::HUMAN:
                    HumanPrologue();
                    break;
                case RaceEnumerator::ELF:
                    ElfPrologue();
                    break;
                case RaceEnumerator::ORC:
                    OrcPrologue();
                    break;
                case RaceEnumerator::DWARF:
                    DwarfPrologue();
                    break;
                default:
                    break;
            }
        }

        void HumanPrologue()
        {
            interface.NewLine();
            interface.PrintTextAndNewLine("Human Prologue...");
        }

        void ElfPrologue()
        {
            interface.NewLine();
            interface.PrintTextAndNewLine("Elf Prologue...");
        }

        void OrcPrologue()
        {
            interface.NewLine();
            interface.PrintTextAndNewLine("Orc Prologue...");
        }

        void DwarfPrologue()
        {
            interface.NewLine();
            interface.PrintTextAndNewLine("Dwarf Prologue...");
        }
    
    private:
        Person* person;
        Interface interface;
};