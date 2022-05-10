#include<iostream>
#include"../inc/field.hpp"

int main()
{   
    Field F;

    char input = 'b';
    while(input != 'q' && F.GetBunnyCount() > 0)
    {
        input = F.Advance();
    }
    std::cout<< "All Bunnies have died.";
    
    return 0;
}