#include<iostream>
#include<time.h>
#include"../inc/field.hpp"
#include"../inc/bunny.hpp"

using _Bunny::Bunny;


int main()
{   srand(time(NULL)); // seed rand()

    Field F;
    F.Initialise();
    F.RmBunny(3);
    F.PrintBunnies();



/*     char input = 'z';
    int counter = 1;
    while(input != 'q')
    {
        std::cout << "Press any key to advance (q to quit):\n";
        std::cin >> input;
        if(input != 'q')
        {
            std::cout << counter << std::endl;
            counter++;
        }
    } */


    return 0;
}