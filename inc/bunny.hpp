#ifndef BUNNY_HPP
#define BUNNY_HPP

#include<string>
#include<map>

using std::string;


namespace _Bunny
{
    class Bunny
    {
        int id = 0;
        string name = "";
        int age = 0;
        string sex = "";
        string colour = "";
        bool isMutant = false;

        public:
            // --- constructors ---
            explicit Bunny(int);
            Bunny(int,string); // overloaded constructor to initialise colour using mother

            // ---getters/setters ---
            int GetID() const;
            void SetID(int);
            string GetName() const;
            void SetName(string);
            int GetAge() const;
            void SetAge(int);
            string GetSex() const;
            void SetSex(string);
            string GetColour() const;
            void SetColour(string);
            bool GetIsMutant() const;
            void SetIsMutant(bool);
    };
}

#endif