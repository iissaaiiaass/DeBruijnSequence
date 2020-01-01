#ifndef LETTER_BIT_H
#define LETTER_BIT_H
#include <iostream>

using namespace std;

class Letter_bit
{
    public:
        Letter_bit(char character='\0', char bit = 0);
        Letter_bit(const Letter_bit& item);
        Letter_bit & operator = (const Letter_bit& item);
        ~Letter_bit();

        void setCharacter(char character);
        void setBit(char bit);
        void setCharacterBit(char character, char bit);

        char getCharacter()const;
        char getBit()const;


        friend ostream & operator << (ostream & out, const Letter_bit& item);
        void displayCharacters()const;
        void displayBits()const;

    protected:

    private:
        char character;
        char bit;
};

#endif // LETTER_BIT_H
