#ifndef NODE_H
#define NODE_H

using namespace std;

template <class ItemType>
class Node
{
    public:
        Node();
        Node(const ItemType& anItem);
        Node(const ItemType& anItem, Node<ItemType>* prev, Node<ItemType>* nextNodePtr);
        void setItem(const ItemType& anItem);
        void setPrev(Node<ItemType>* prevNodePtr);
        void setNext(Node<ItemType>* nextNodePtr);
        ItemType getItem() const;
        Node<ItemType>* getPrev()const;
        Node<ItemType>* getNext() const ;

    protected:

    private:
         ItemType item;
         Node<ItemType>* next;
         Node<ItemType>* prev;
};

template<class ItemType>
Node<ItemType>::Node() : next(NULL),prev(NULL)
{}
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(NULL), prev(NULL)
{}
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* prevNodePtr, Node<ItemType>* nextNodePtr) :
	item(anItem), next(nextNodePtr), prev(prevNodePtr)
{}


template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}
template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
}
template<class ItemType>
void Node<ItemType>::setPrev(Node<ItemType>* prevNodePtr)
{
	prev = prevNodePtr;
}


template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}
template<class ItemType>
Node<ItemType>* Node<ItemType>::getPrev()const
{
    return prev;
}
template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}

#endif // NODE_H
