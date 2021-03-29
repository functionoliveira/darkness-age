#include "FamilyBackground.cpp"
#include "ChildrenBackground.cpp"
#include "YoungBackground.cpp"

class Background
{
    public:
        Background() { }
        Background(BackgroundEnumerator f, BackgroundEnumerator c, BackgroundEnumerator y)
        {
            family = FamilyBackground(f);
            children = ChildrenBackground(c);
            young = YoungBackground(y);
        }
        
        FamilyBackground GetFamily()
        {
            return family;
        }

        ChildrenBackground GetChildren()
        {
            return children;
        }

        YoungBackground GetYoung()
        {
            return young;
        }
    private:
        FamilyBackground family;
        ChildrenBackground children;
        YoungBackground young;
        // OPTIONS experience;
        // OPTIONS education;
        // OPTIONS travel;
        // OPTIONS job;
};