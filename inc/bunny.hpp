#ifndef BUNNY_HPP
#define BUNNY_HPP

#include<string>
#include<map>

using std::string;


namespace _Bunny
{
    // attribute enums
    enum Name{ Bopsy, Cuddles, Flopsy, Hoppity, Mittens, Mopsy, Nibbles, Whiskers };
    enum Sex{ Male, Female };
    enum Colour{ White, Brown, Black, Spotted };


    // attribute maps
    static std::map<int,std::string> NamesMap = 
        {{Name::Bopsy, "Bopsy"}, {Name::Cuddles, "Cuddles"},
        {Name::Flopsy, "Flopsy"}, {Name::Hoppity, "Hoppity"}, {Name::Mittens, "Mittens"},
        {Name::Mopsy, "Mopsy"}, {Name::Nibbles, "Nibbles"}, {Name::Whiskers, "Whiskers"}};

    static std::map<Sex,std::string> SexesMap = {{Sex::Male, "Male"}, {Sex::Female, "Female"}};

    static std::map<Colour,std::string> ColoursMap = 
        {{Colour::White, "White"}, {Colour::Brown, "Brown"}, 
        {Colour::Black, "Black"}, {Colour::Spotted, "Spotted"}};


    class Bunny
    {
        string name = "";
        int age = 0;
        Sex sex;
        Colour colour;
        bool isInfected = false;

        public:
            // --- constructors ---
            Bunny();
            explicit Bunny(Colour);  // initialise using mother's colour

            // ---getters/setters ---
            string GetName() const;
            void SetName(string);
            int GetAge() const;
            void SetAge(int);
            Sex GetSex() const;
            void SetSex(Sex);
            Colour GetColour() const;
            void SetColour(Colour);
            bool GetIsInfected() const;
            void SetIsInfected(bool);
    };
}

#endif