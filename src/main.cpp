#include<iostream>
#include<time.h>
#include"../inc/field.hpp"


int main()
{   
    srand(time(NULL)); 
    Field F;
    F.Initialise();

    char input = 'z';
    while(input != 'q' && F.GetBunnyCount() > 0)
    {
        input = F.Advance();
    }
    std::cout<< "All Bunnies have died.";

    return 0;
}