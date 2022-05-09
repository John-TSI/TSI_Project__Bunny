#include<iostream>
#include"../inc/field.hpp"

int main()
{   
    Field F;
    F.Initialise();

    char input = 'b';
    while(input != 'q' && F.GetBunnyCount() > 0)
    {
        input = F.Advance();
    }
    std::cout<< "All Bunnies have died.";
    
    return 0;
}