#include <iostream>
#include "Background.cpp"

class BackgroundTest
{
    public:
        bool run()
        {
            Background* backgroud = new Background(BackgroundEnumerator::NOBLE, BackgroundEnumerator::GODLY, BackgroundEnumerator::MERCHANT);
            std::cout << backgroud->GetFamily().GetLore() << std::endl;
            std::cout << backgroud->GetFamily().GetInfoAboutAttributesUpdate() << std::endl;
            std::cout << backgroud->GetChildren().GetLore() << std::endl;
            std::cout << backgroud->GetChildren().GetInfoAboutAttributesUpdate() << std::endl;
            std::cout << backgroud->GetYoung().GetLore() << std::endl;
            std::cout << backgroud->GetYoung().GetInfoAboutAttributesUpdate() << std::endl;
            return true;
        }
};