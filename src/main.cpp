#include"../inc/field.hpp"

int main()
{   
    Field F;
    while( !F.Terminate() ) { F.Advance(); }  
    return 0;
}