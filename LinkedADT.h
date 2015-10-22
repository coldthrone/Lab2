/** ADT stack: Link-based implementation.
@file LinkedADT.h */
#ifndef _LINKED_ADT
#define _LINKED_ADT
#include "StackInterface.h"
#include "Node.h"


template < class ItemType > class LinkedADT //:public StackInterface < ItemType >
{
private:
	Node < ItemType > *topPtr;	// Pointer to first node in the chain;
								// this node contains the stacks top
public:
	// Constructors and destructor:
	LinkedADT();	// Default constructor
	LinkedADT(const LinkedADT < ItemType > &aStack);	// Copy constructor

	virtual ~LinkedADT();	// Destructor
							// Stack operations:
	bool isEmpty() const;

	bool push(const ItemType & newItem);

	bool pop();

	ItemType peek() const;

	// Implementation for LinkedADT
	template < class ItemType > LinkedADT < ItemType >::LinkedADT() :topPtr(nullptr)
	{
	}   // end default constructor

	template < class ItemType > LinkedADT < ItemType >::LinkedADT(const LinkedADT < ItemType > &aStack)
	{
		// Point to nodes in original chain
		Node < ItemType > *origChainPtr = aStack->topPtr;
		if (origChainPtr == nullptr)
			topPtr = nullptr;	// Original bag is empty
		else
		{
			// Copy first node
			topPtr = new Node < ItemType >();
			topPtr->setItem(origChainPtr->getItem());
			// Point to first node in new chain
			Node < ItemType > *newChainPtr = topPtr;
			// Copy remaining nodes
			while (origChainPtr != nullptr)
			{
				// Advance original-chain pointer
				origChainPtr = origChainPtr->getNext();
				// Get next item from original chain
				ItemType nextItem = origChainPtr->getItem();

				// Create a new node containing the next item
				Node < ItemType > *newNodePtr = new Node < ItemType >(nextItem);
				// Link new node to end of new chain
				newChainPtr->setNext(newNodePtr);
				// Advance pointer to new last node
				newChainPtr = newChainPtr->getNext();
			}	// end while
			newChainPtr->setNext(nullptr);	// Flag end of chain
		}	// end if
	}   // end copy constructor

	template < class ItemType > LinkedADT < ItemType >::~LinkedADT()
	{
		// Pop until stack is empty
		while (!isEmpty())
			pop();
	}   // end destructor

	template < class ItemType > bool LinkedADT < ItemType >::isEmpty() const
	{
		return topPtr == nullptr;
	}   // end isEmpty

	template < class ItemType > bool LinkedADT < ItemType >:: push (const ItemType & newItem)
	{
		Node < ItemType > *newNodePtr = new Node < ItemType >(newItem, topPtr);
		topPtr = newNodePtr;
		newNodePtr = nullptr;
		// end push
		template < class ItemType > bool LinkedADT < ItemType >::pop()
		{
			bool result = false;

			if (!isEmpty())
			{
				// Stack is not empty; delete top
				Node < ItemType > *nodeToDeletePtr = topPtr;
				topPtr = topPtr->getNext();
				// Return deleted node to system
				nodeToDeletePtr->setNext(nullptr);
				delete nodeToDeletePtr;

				nodeToDeletePtr = nullptr;
				result = true;
			}	// end if
			return result;
		} // end pop
		template < class ItemType > ItemType LinkedADT < ItemType >::peek()const
		{
			assert(!isEmpty());	// Enforce precondition
								// Stack is not empty; return top
			return topPtr->getItem();
		} // end getTop

};  // end LinkedADT

#include "Main.cpp"
#endif
