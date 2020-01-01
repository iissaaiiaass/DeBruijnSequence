#include "deBruijn_sequence.h"

using namespace std;

deBruijn_sequence::deBruijn_sequence()
{
     ifstream charactersFile;
     string characters;
     charactersFile.open("Characters.txt");
     if(charactersFile.fail())
    {
        cout << "CharactersFile can't open";
        charactersFile.clear();
    }
    getline(charactersFile,characters);

    ifstream deBruijn_SequenceFile;
    string deBruijn_Sequence;
    deBruijn_SequenceFile.open("deBruijn_sequence.txt");
    if(deBruijn_SequenceFile.fail())
    {
        cout << "deBruijn_SequenceFile can't open";
        deBruijn_Sequence.clear();
    }
    getline(deBruijn_SequenceFile, deBruijn_Sequence);

    deBruijn_SequenceFile.close();
    charactersFile.close();

    Letter_bit initializer;
    for(int i=0; i < 32; i++)
    {
        initializer.setCharacter(characters[i]);
        initializer.setBit(deBruijn_Sequence[i]);
        circularSequence.atEnd(initializer);
    }
}

deBruijn_sequence::~deBruijn_sequence()
{}


void deBruijn_sequence::encodeMessage(fstream& message)
{
    string completeMessage;
    getline(message, completeMessage);
    for(unsigned int i=0; i < completeMessage.length(); i++)
    {
        //Compare each letter of the message with the circularSequence's letters.
        for(int j=1; j <= 32; j++)
        {
            Letter_bit letter = circularSequence.getEntry(j);
            if(completeMessage.at(i)==letter.getCharacter())
            {
                 Node<Letter_bit>* traverse  = circularSequence.getNodeAt(j);
                 //Print the binary sequence that represent each letter.
                 for(int k=0; k < 5; k++)
                 {
                     letter =  traverse->getItem();
                     letter.displayBits();
                     traverse = traverse->getNext();
                 }
            }
        }
    }
}

void deBruijn_sequence::decodeMessage(fstream& message)
{
    string encodeMessage;
    Node<Letter_bit>* desiredLetterPtr;
    Node<Letter_bit>* traversePtr;
    Letter_bit desiredLetter;
    Letter_bit traverse;
    getline(message, encodeMessage);
    int c = 0;
    for(unsigned int i = 0; i < encodeMessage.length() / 5; i++)
    {
        string stringLetterRepresentation;
        //Save each letter of the encoded message.
        for(int j=0; j < 5; j++)
        {
            stringLetterRepresentation += encodeMessage.at(c);
            c++;
        }
        //Compare each letter of the encoded message with the circularSequence's bits.
        for(int k=0; k < 32; k++)
        {
            desiredLetterPtr = circularSequence.getNodeAt(k+1);
            traversePtr = circularSequence.getNodeAt(k+1);
            string ComparingLetter;
            for(int l=0; l < 5; l++)
            {
                 traverse = traversePtr->getItem();
                 ComparingLetter += traverse.getBit();
                 traversePtr = traversePtr->getNext();
            }
            if(stringLetterRepresentation == ComparingLetter)
            {
                //Print the binary sequence of each letter.
                desiredLetter = desiredLetterPtr->getItem();
                cout << desiredLetter.getCharacter();
            }
        }
    }
}
