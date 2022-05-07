#ifndef ATTRIBUTES_HPP
#define ATTRIBUTES_HPP

#include<string>
#include<map>


// attribute enums
enum Names{ Bopsy, Cuddles, Flopsy, Hoppity, Mittens, Mopsy, Nibbles, Whiskers };
enum Sexes{ Male, Female };
enum Colours{ White, Brown, Black, Spotted };


// attribute maps
// std::map<Names,std::string>
std::map<int,std::string> NamesMap = 
    {{Names::Bopsy, "Bopsy"}, {Names::Cuddles, "Cuddles"},
    {Names::Flopsy, "Flopsy"}, {Names::Hoppity, "Hoppity"}, {Names::Mittens, "Mittens"},
    {Names::Mopsy, "Mopsy"}, {Names::Nibbles, "Nibbles"}, {Names::Whiskers, "Whiskers"}};

std::map<int,std::string> SexesMap = {{Sexes::Male, "Male"}, {Sexes::Female, "Female"}};

std::map<int,std::string> ColoursMap = 
    {{Colours::White, "White"}, {Colours::Brown, "Brown"}, 
    {Colours::Black, "Black"}, {Colours::Spotted, "Spotted"}}; 

#endif