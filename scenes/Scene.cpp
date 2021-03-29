class Scene
{
    public:
        Scene(Person* p, Interface i)
        {
            person = p;
            interface = i;
        }

        void CalculateResult() 
        {

        }

        void Run()
        {
            char action;
            interface.NewLine();
            interface.PrintTextAndNewLine("A carruagem se aproxima da entrade de Porto Nobuloso, um cheiro forte de podre toma conta do ar,");
            interface.PrintTextAndNewLine("causado pelas pilhas de corpos que são montadas pelos soladados da União. O reino de Allys domina");
            interface.PrintTextAndNewLine("o local após a sangrenta batalha que levou a o massacre de tropas élficas, e o que você vê agora é");
            interface.PrintTextAndNewLine("apenas resultado disso tudo.");
            interface.NewLine();
            interface.PrintTextAndNewLine("Você nota que de repente parou de se movimentar, do lado de fora escuta-se um ruído que se parece");
            interface.PrintTextAndNewLine("uma conversa. As tropas conversam com o cocheiro que parece resmungar da situação. Não muito tempo");
            interface.PrintTextAndNewLine("se passa e eles batem na porta.");
            interface.NewLine();
            interface.PrintTextAndNewLine("- Fiscal! por favor abra a porta para que possamos verificar seus papeis.");
            interface.PrintTextAndNewLine(" 1 - Você abre a porta mostrando sua face e apresenta os papeis.");
            interface.PrintTextAndNewLine(" 2 - Pela fresta você apresenta os papeis sem deixar muito claro seu rosto.");
            interface.PrintTextAndNewLine(" 3 - Negar-se a abrir a porta dizendo que é um cidadão importante da cidade.");
            action = interface.Continue("Qual será sua ação? ", true);
        }

        ShowChoiceAndImpact()
        {

        }
    
    private:
        int step = 1; 
        Person* person;
        Interface interface;
};