#ifndef _NODE
#define _NODE


template <class ItemType>

class Node
{
private:
	ItemType item;
	Node<ItemType> * next;
public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem()const;
	Node<ItemType>*getNext() const;


};
// implementation from book for Node

template<class ItemType>
node<ItemType>::Node() :next(nullptr)
{

}// end default constructor
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anitem), next(nullptr)
{

}// end constructor
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePTr)
{

}// end constrcutor
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}// set item
template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
}// set next
template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}// get item
template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
	return next;
}// get next
#endif

