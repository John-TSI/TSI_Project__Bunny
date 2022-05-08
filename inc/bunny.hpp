#ifndef BUNNY_HPP
#define BUNNY_HPP

#include<vector>
#include<string>
#include<unordered_map>
#include<memory>

using std::string; using std::unique_ptr;


namespace _Bunny
{
    // --- name vectors ---
    static std::vector<string> MaleNames{"Adam", "Bob", "Carl", "Dave", "Evan", "Fred", "Gary", "Harry"};
    static std::vector<string> FemaleNames{"Anna", "Beth", "Chloe", "Daisy", "Emily", "Faye", "Gemma", "Helen"};

    // --- attribute enums ---
    enum class Sex{Male, Female};
    enum class Colour{White, Brown, Black, Spotted};

    // --- attribute maps ---
    static std::unordered_map<Sex,string> SexesMap = {{Sex::Male, "Male"}, {Sex::Female, "Female"}};
    static std::unordered_map<Colour,string> ColoursMap = {{Colour::White, "White"}, {Colour::Brown, "Brown"}, {Colour::Black, "Black"}, {Colour::Spotted, "Spotted"}};


    class Bunny
    {
        string name = "";
        int age = 0;
        Sex sex;
        Colour colour;
        bool isInfected = false;

        public:
            // --- constructor ---
            explicit Bunny(const unique_ptr<Bunny>&);

            // ---getters/setters ---
            string GetName() const;
            int GetAge() const;
            void SetAge(int);
            Sex GetSex() const;
            Colour GetColour() const;
            bool GetIsInfected() const;
            void SetIsInfected(bool);
    };
}

#endif