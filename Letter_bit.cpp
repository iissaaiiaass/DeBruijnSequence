#include "Letter_bit.h"

using namespace std;

Letter_bit::Letter_bit(char character, char bit)
{
    this->character = character;
    this->bit = bit;
}
Letter_bit::Letter_bit(const Letter_bit& item)
{
    (*this) = item;
}
Letter_bit & Letter_bit::operator = (const Letter_bit& item)
{
    this->character = item.character;
    this->bit = item.bit;
    return *this;
}
Letter_bit::~Letter_bit()
{}

void Letter_bit::setCharacter(char character)
{
    this->character = character;
}
void Letter_bit::setBit(char bit)
{
    this->bit = bit;
}
void Letter_bit::setCharacterBit(char character, char bit)
{
    this->character = character;
    this->bit = bit;
}

char Letter_bit::getCharacter()const
{
    return this->character;
}
char Letter_bit::getBit()const
{
    return this->bit;
}

ostream & operator << (ostream & out, const Letter_bit& item)
{
    out << item.character << ", " << item.bit << ' ';
    return out;
}
void Letter_bit::displayCharacters()const
{
    cout << this->character;
}
void Letter_bit::displayBits()const
{
    cout << this->bit;
}
