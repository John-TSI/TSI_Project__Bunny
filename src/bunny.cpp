#include"../inc/bunny.hpp"
#include"../inc/attributes.hpp"

using _Bunny::Bunny;


// --- constructors ---
/* Bunny::Bunny() :
    name(NamesMap[ rand()%(NamesMap.size()) ]), 
    sex(SexesMap[ rand()%2 ]),
    colour(ColoursMap[ rand()%4 ]),
    isInfected( (rand()%100 < 2) ? true : false ) {}

Bunny::Bunny(string colour) :
    name(NamesMap[ rand()%7 ]), 
    sex(SexesMap[ rand()%2 ]),
    colour(colour),
    isInfected( (rand()%100 < 2) ? true : false ) {} */

Bunny::Bunny() :
    name(NamesMap[ rand()%(NamesMap.size()) ]), 
    sex(SexesMap[ rand()%2 ]),
    colour(ColoursMap[ rand()%4 ]),
    isInfected( (rand()%100 < 2) ? true : false ) {}

Bunny::Bunny(string colour) :
    name(NamesMap[ rand()%7 ]), 
    sex(SexesMap[ rand()%2 ]),
    colour(colour),
    isInfected( (rand()%100 < 2) ? true : false ) {}


// --- getters/setters ---
string Bunny::GetName() const { return name; }
void Bunny::SetName(string input) { name = input; }
int Bunny::GetAge() const { return age; }
void Bunny::SetAge(int input) { age = input; }
string Bunny::GetSex() const { return sex; }
void Bunny::SetSex(string input) { sex = input; }
string Bunny::GetColour() const { return colour; }
void Bunny::SetColour(string input) { colour = input; }
bool Bunny::GetIsInfected() const { return isInfected; }
void Bunny::SetIsInfected(bool input) { isInfected = input; }