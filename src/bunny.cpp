#include"../inc/bunny.hpp"

using _Bunny::Bunny;


// --- constructors ---
Bunny::Bunny() :
    name(NamesMap[ rand()%(NamesMap.size()) ]), 
    sex( Sex(rand()%2) ),
    colour( Colour(rand()%4) ),
    isInfected( (rand()%100 < 2) ? true : false ) {}
    
Bunny::Bunny(Colour colour) :
    name(NamesMap[ rand()%(NamesMap.size()) ]), 
    sex( Sex(rand()%2) ),
    colour(colour),
    isInfected( (rand()%100 < 2) ? true : false ) {}


// --- getters/setters ---
string Bunny::GetName() const { return name; }
void Bunny::SetName(string input) { name = input; }
int Bunny::GetAge() const { return age; }
void Bunny::SetAge(int input) { age = input; }
_Bunny::Sex Bunny::GetSex() const { return sex; }
void Bunny::SetSex(Sex input) { sex = input; }
_Bunny::Colour Bunny::GetColour() const { return colour; }
void Bunny::SetColour(Colour input) { colour = input; }
bool Bunny::GetIsInfected() const { return isInfected; }
void Bunny::SetIsInfected(bool input) { isInfected = input; }