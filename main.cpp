#include <iostream>
#include<fstream>
#include<string>
#include "Node.h"
#include "DoubleList.h"
#include "deBruijn_sequence.h"

using namespace std;

int main()
{
    /*DoubleList<int> intList;
    //Prueba del metodo "insert";
    intList.insert(1, 2);
    intList.insert(2,4);
    intList.insert(3,6);
    intList.insert(5,8);//No se anade
    intList.insert(-5,8);//No se anade
    intList.insert(1,1);
    intList.insert(3,3);
    intList.display();
    cout << "\n";
    intList.displayBackward();
    cout << "\n";
    intList.displayTwoTimes();
    cout << "\n\n";

    //Prueba del insertAfter
    DoubleList<int> intList3;
    intList3.insertAfter(1,1);//No anade
    intList3.insert(1,1);
    intList3.insertAfter(1,2);
    intList3.insertAfter(1,3);
    intList3.insertAfter(5,3);//No anade
    intList3.insertAfter(-3,4);//No anade
    intList3.display();

    cout << "\n\n";

    //Prueba del copy constructor
    DoubleList<int> intList2(intList);
    intList2.display();
     cout << "\n\n";

    //Prueba del metodo remove
    intList2.remove(1);
    intList2.remove(3);
    intList2.remove(3);
    intList2.remove(3);// No remueve
    intList2.remove(-3);// No remueve
    intList2.display();
    cout << "\n\n";

    //Prueba del metodo atEnd
    DoubleList<int> intList4;
    intList4.atEnd(10);
    intList4.atEnd(20);
    intList4.atEnd(30);
    intList4.display();
    cout << "\n\n";
    //Prueba de los demas metodos
    cout << "List's size is: " << intList2.getLength() << endl;
    cout << "Item in postion 2 is: " << intList2.getEntry(2) << endl;
    intList2.setEntry(2,10);
    cout << "New valor of item in position 2 is: " << intList2.getEntry(2) << endl;
    if(intList2.isEmpty())
        cout << "The list is empty\n";
    else
        cout << "The list is not empty\n";
    intList2.clear();
    if(intList2.isEmpty())
        cout << "The list is empty\n";
    else
        cout << "The list is not empty\n";

    cout << "\n\n" << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n";*/

    string greeting = "HOLA PEDRO";
    string greeting2 = "HOLA SERGIO";
    fstream message;
    fstream message2;

    message.open("message.txt", ios::out | ios::in | ios::trunc);
    if(message.fail())
    {
        cout << "message.txt can't open";
        message.clear();
    }
    message2.open("message2.txt", ios::out | ios::in | ios::trunc);
    if(message2.fail())
    {
        cout << "message2.txt can't open";
        message.clear();
    }

    message << greeting;
    message.seekg(0,ios::beg);
    message2 << greeting2;
    message2.seekg(0,ios::beg);

    deBruijn_sequence sequence1;

    cout << "Message: " << greeting << endl;
    cout << "Encoded Message: ";
    sequence1.encodeMessage(message);
    cout << endl;
    cout << "Message: " << greeting2 << endl;
    cout << "Encoded Message: ";
    sequence1.encodeMessage(message2);

    cout << "\n\n";

    string encodedGreeting = "00011111111101110011101001111010000110001100111111";
    string encodedGreeting2 = "0001111111110111001110100100101000011001000010011111111";
    fstream encodeMessage;
    fstream encodeMessage2;

    encodeMessage.open("message3.txt", ios::out | ios::in | ios::trunc);
    if(encodeMessage.fail())
    {
        cout << "message3.txt can't open";
        encodeMessage.clear();
    }
    encodeMessage2.open("message4.txt", ios::out | ios::in | ios::trunc);
    if(encodeMessage2.fail())
    {
        cout << "message4.tx can't open";
        encodeMessage2.clear();
    }

    encodeMessage << encodedGreeting;
    encodeMessage.seekg(0,ios::beg);
    encodeMessage2 << encodedGreeting2;
    encodeMessage2.seekg(0,ios::beg);

    cout << "Encoded Message: " << encodedGreeting << endl;
    cout << "Decoded Message: ";
    sequence1.decodeMessage(encodeMessage);
    cout << endl;
    cout << "Encoded Message: " << encodedGreeting2 << endl;
    cout << "Decoded Message: ";
    sequence1.decodeMessage(encodeMessage2);

    message.close();
    message2.close();
    encodeMessage.close();
    encodeMessage2.close();
    cout << "\n\n";
    return 0;
}
