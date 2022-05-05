#include"../inc/bunny.hpp"
#include"../inc/attributes.hpp"

using _Bunny::Bunny;


// --- constructors ---
Bunny::Bunny(int id) :
    id(id),
    name(NamesMap[ rand()%(NamesMap.size()) ]), 
    sex(SexesMap[ rand()%2 ]),
    colour(ColoursMap[ rand()%4 ]),
    isMutant( (rand()%100 < 2) ? true : false ) {}

Bunny::Bunny(int id, string colour) :
    id(id),
    name(NamesMap[ rand()%7 ]), 
    sex(SexesMap[ rand()%2 ]),
    colour(colour),
    isMutant( (rand()%100 < 2) ? true : false ) {}


// --- getters/setters ---
int Bunny::GetID() const { return id; }
void Bunny::SetID(int input) { id = input; }
string Bunny::GetName() const { return name; }
void Bunny::SetName(string input) { name = input; }
int Bunny::GetAge() const { return age; }
void Bunny::SetAge(int input) { age = input; }
string Bunny::GetSex() const { return sex; }
void Bunny::SetSex(string input) { sex = input; }
string Bunny::GetColour() const { return colour; }
void Bunny::SetColour(string input) { colour = input; }
bool Bunny::GetIsMutant() const { return isMutant; }
void Bunny::SetIsMutant(bool input) { isMutant = input; }