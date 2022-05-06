#ifndef BUNNY_HPP
#define BUNNY_HPP

#include<string>
#include<map>

using std::string;


namespace _Bunny
{
    class Bunny
    {
        string name = "";
        int age = 0;
        string sex = "";
        string colour = "";
        bool isInfected = false;

        public:
            // --- constructors ---
            Bunny();
            explicit Bunny(string);  // initialise using mother's colour

            // ---getters/setters ---
            string GetName() const;
            void SetName(string);
            int GetAge() const;
            void SetAge(int);
            string GetSex() const;
            void SetSex(string);
            string GetColour() const;
            void SetColour(string);
            bool GetIsInfected() const;
            void SetIsInfected(bool);
    };
}

#endif