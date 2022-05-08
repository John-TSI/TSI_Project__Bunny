#include"../inc/bunny.hpp"

using _Bunny::Bunny;


// --- constructor ---
Bunny::Bunny(const unique_ptr<Bunny>& u_ptr) :
    sex( Sex(rand()%2) ),
    // u_ptr will either point to a Female Bunny object, or be nullptr
    colour( !u_ptr ? Colour(rand()%4) : u_ptr->GetColour() ),
    isInfected( rand()%100 < 2 ? true : false )
{
    name = ((int)sex) ? FemaleNames[ rand()%(FemaleNames.size()) ] : MaleNames[ rand()%(MaleNames.size()) ]; 
}


// --- getters/setters ---
string Bunny::GetName() const { return name; }
int Bunny::GetAge() const { return age; }
void Bunny::SetAge(int input) { age = input; }
_Bunny::Sex Bunny::GetSex() const { return sex; }
_Bunny::Colour Bunny::GetColour() const { return colour; }
bool Bunny::GetIsInfected() const { return isInfected; }
void Bunny::SetIsInfected(bool input) { isInfected = input; }