#ifndef DEBRUIJN_SEQUENCE_H
#define DEBRUIJN_SEQUENCE_H
#include <fstream>
#include <string>
#include "DoubleList.h"
#include "Letter_bit.h"

using namespace std;

class deBruijn_sequence
{
    public:
        deBruijn_sequence();
        ~deBruijn_sequence();

        void encodeMessage(fstream& message);
        void decodeMessage(fstream& message);

    protected:

    private:
        DoubleList<Letter_bit> circularSequence;
};

#endif // DEBRUIJN_SEQUENCE_H
