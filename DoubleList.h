#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include <iostream>
#include "PrecondViolatedExcep.h"
#include "Node.h"
#include <cassert>

using namespace std;

template <class ItemType>
class DoubleList
{
    public:
        DoubleList();
        DoubleList(int size);
        DoubleList(const DoubleList<ItemType>& aList);
        ~DoubleList();

        bool isEmpty() const;
        int getLength() const;
        bool insert(int newPosition, const ItemType& newEntry);
        bool remove(int position);
        void clear();
        ItemType getEntry(int position) const throw(PrecondViolatedExcep);
        Node<ItemType>* getNodeAt(int position) const;
        void display()const;
        void displayBackward()const;
        void displayTwoTimes()const;
        int getItemcount()const;
        void setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep);
        int getPosition(const ItemType& newEntry)const;



        void atEnd(const ItemType& newEntry);
        ItemType RetrieveNextInfo(int position)const;
        bool insertAfter(const ItemType& beforeEntry, const ItemType& newEntry);



    protected:

    private:
        Node<ItemType>* headPtr;
        Node<ItemType>* TailPtr;
        int itemCount;


};

template<class ItemType>
DoubleList<ItemType>::DoubleList() : headPtr(NULL), TailPtr(NULL), itemCount(0)
{}
template<class ItemType>
DoubleList<ItemType>::DoubleList(const DoubleList<ItemType>& aList)
{
	itemCount = aList.itemCount;
	Node<ItemType>* origChainPtr = aList.headPtr;

	if (origChainPtr == NULL)
		headPtr = NULL;
	else
	{

		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());

		Node<ItemType>* newChainPtr = headPtr;
		Node<ItemType>* prevNode = NULL;
		origChainPtr = origChainPtr->getNext();

		for(int i = 1; i < aList.itemCount; i++)
		{

			ItemType nextItem = origChainPtr->getItem();

			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);


			prevNode = newChainPtr;
			newChainPtr->setNext(newNodePtr);


			newChainPtr = newChainPtr->getNext();
			newChainPtr->setPrev(prevNode);


			origChainPtr = origChainPtr->getNext();
		}
		TailPtr = newChainPtr;
		TailPtr->setNext(headPtr);
        headPtr->setPrev(TailPtr);
	}
}


template<class ItemType>
DoubleList<ItemType>::~DoubleList()
{
   clear();
}

template<class ItemType>
bool DoubleList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}
template<class ItemType>
int DoubleList<ItemType>::getLength() const
{
   return itemCount;
}

template<class ItemType>
bool DoubleList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (itemCount > 0) && (newPosition <= itemCount + 1);

   if (ableToInsert)
   {
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

      if (newPosition == 1 && itemCount > 1)
      {
         headPtr->setPrev(newNodePtr);
         newNodePtr->setNext(headPtr);
         newNodePtr->setPrev(TailPtr);
         headPtr = newNodePtr;
         TailPtr->setNext(headPtr);
         itemCount++;
      }
      else if(newPosition <= itemCount)
      {
         Node<ItemType>* tempPrevPtr = getNodeAt(newPosition - 1);
         Node<ItemType>* originalPtr = getNodeAt(newPosition);


         newNodePtr->setNext(tempPrevPtr->getNext());
         newNodePtr->setPrev(tempPrevPtr);
         tempPrevPtr->setNext(newNodePtr);
         originalPtr->setPrev(newNodePtr);
         itemCount++;
      }
      else
      {
          TailPtr->setNext(newNodePtr);
          newNodePtr->setPrev(TailPtr);
          newNodePtr->setNext(headPtr);
          headPtr->setPrev(newNodePtr);
          TailPtr = newNodePtr;
          itemCount++;
      }
   }
   else if(newPosition == 1 && itemCount == 0)
   {
       Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
       headPtr = newNodePtr;
       TailPtr = newNodePtr;
       itemCount++;
       ableToInsert = true;
   }
   return ableToInsert;
}

template<class ItemType>
bool DoubleList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<ItemType>* curPtr = NULL;
      if (position == 1)
      {
         curPtr = headPtr;
         headPtr = headPtr->getNext();
      }
      else if(position < itemCount)
      {
         Node<ItemType>* tempPrevPtr = getNodeAt(position - 1);
         Node<ItemType>* tempNextPtr = getNodeAt(position + 1);
         curPtr = tempPrevPtr->getNext();
         tempPrevPtr->setNext(tempNextPtr);
         tempNextPtr->setPrev(tempPrevPtr);
      }
      else
      {
          curPtr = TailPtr;
          Node<ItemType>* tempPrevPtr = getNodeAt(position - 1);
          tempPrevPtr->setNext(headPtr);
          TailPtr = tempPrevPtr;
          headPtr->setNext(TailPtr);

      }
      curPtr->setNext(NULL);
      curPtr->setPrev(NULL);
      delete curPtr;
      curPtr = NULL;

      itemCount--;
   }

   return ableToRemove;
}

template<class ItemType>
void DoubleList<ItemType>::clear()
{
   while (!isEmpty())
      remove(1);
}
template<class ItemType>
ItemType  DoubleList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      string message = "getEntry() called with an empty list or ";
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message));
   }
}
template<class ItemType>
Node<ItemType>* DoubleList<ItemType>::getNodeAt(int position) const
{
   assert( (position >= 1) && (position <= itemCount) );

   Node<ItemType>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();

   return curPtr;
}
template <class ItemType>
void DoubleList<ItemType>::display()const
{
    if(!(this->isEmpty()))
    {
        Node<ItemType>* currentPosition;
        currentPosition = headPtr;
        for (int i = 0; i < itemCount - 1; i++)
        {
            cout << currentPosition->getItem();
            currentPosition = currentPosition->getNext();
        }
        cout << currentPosition->getItem();
    }

}
template <class ItemType>
void DoubleList<ItemType>::displayBackward()const
{
    if(!(this->isEmpty()))
    {
        Node<ItemType>* currentPosition;
        currentPosition = TailPtr;
        for (int i = 0; i < itemCount - 1; i++)
        {
            cout << currentPosition->getItem();
            currentPosition = currentPosition->getPrev();
        }
        cout << currentPosition->getItem();
    }
}
template<class ItemType>
void DoubleList<ItemType>::displayTwoTimes()const
{
    if(!(this->isEmpty()))
    {
        Node<ItemType>* currentPosition;
        currentPosition = headPtr;
        for (int i = 0; i < 2 * itemCount - 1; i++)
        {
            cout << currentPosition->getItem();
            currentPosition = currentPosition->getNext();
        }
        cout << currentPosition->getItem();
    }
}
template <class ItemType>
int DoubleList<ItemType>::getItemcount()const
{
    return this->itemCount;
}

template<class ItemType>
void DoubleList<ItemType>::setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
    bool ableToSet = (position >= 1) && (position <= itemCount);
    if(ableToSet)
    {
        Node<ItemType>* nodePtr = getNodeAt(position);
        nodePtr->setItem(newEntry);

    }
    else
    {
        string message = "setEntry() called with an empty list or ";
        message  = message + "invalid position.";
        throw PrecondViolatedExcep("This is an illegal action!");
    }

}
template<class ItemType>
int DoubleList<ItemType>::getPosition(const ItemType& newEntry)const
{
   int position = 0;
   if(itemCount >= 1)
   {

       Node<ItemType>* curPtr = headPtr;
       ItemType curItem = curPtr->getItem();
       for(position = 1; position <= itemCount; position++)
          if(curItem == newEntry)
          {
              return position;
          }
   }
   return position;
}
template<class ItemType>
void DoubleList<ItemType>::atEnd(const ItemType& newEntry)
{
   Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

   if(itemCount == 0)
   {
       headPtr = newNodePtr;
       TailPtr = newNodePtr;
       itemCount++;
   }
   else
   {
       TailPtr->setNext(newNodePtr);
       newNodePtr->setPrev(TailPtr);
       newNodePtr->setNext(headPtr);
       headPtr->setPrev(newNodePtr);
       TailPtr = newNodePtr;
       itemCount++;
    }
}
template<class ItemType>
ItemType DoubleList<ItemType>::RetrieveNextInfo(int position)const
{
    Node<ItemType>* newNode = new Node<ItemType>;
    newNode =  getNodeAt(position + 1);
    return newNode->getItem();
}
template<class ItemType>
 bool DoubleList<ItemType>::insertAfter(const ItemType& beforeEntry, const ItemType& newEntry)
 {
     int position = getPosition(beforeEntry);
     bool ableToInsert = (position >= 1) && (itemCount >= 1) && (position <= itemCount);
     if (ableToInsert)
        {
            Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
            if(position == 1 && itemCount == 1)
            {
               headPtr->setNext(newNodePtr);
               headPtr->setPrev(newNodePtr);
               newNodePtr->setPrev(headPtr);
               newNodePtr->setNext(headPtr);
               TailPtr = newNodePtr;
               itemCount++;
            }
            else if(position <= itemCount)
            {
                Node<ItemType>* tempPrevPtr = getNodeAt(position);
                Node<ItemType>* PositionPtr = getNodeAt(position + 1);

                newNodePtr->setNext(tempPrevPtr->getNext());
                newNodePtr->setPrev(tempPrevPtr);
                tempPrevPtr->setNext(newNodePtr);
                PositionPtr->setPrev(newNodePtr);
                itemCount++;
            }
            else
            {
                TailPtr->setNext(newNodePtr);
                newNodePtr->setPrev(TailPtr);
                newNodePtr->setNext(headPtr);
                headPtr->setPrev(newNodePtr);
                TailPtr = newNodePtr;
                itemCount++;
            }
        }
   return ableToInsert;
}

#endif // DOUBLELIST_H
