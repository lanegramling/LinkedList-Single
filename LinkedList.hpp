#include <iostream>
#include "Node.h"
#include "LinkedList.h"

//Constructor
template <class T>
LinkedList<T>::LinkedList()
{
  m_size = 0;
  m_front = nullptr;
}

//Destructor
template <class T>
LinkedList<T>::~LinkedList()
{
  while (!isEmpty()) erase(m_front->getValue());
}

//Erases the node containing the given value from this LinkedList.
template <class T>
bool LinkedList<T>::erase(T value, Node<T>* current, Node<T>* prev)
{
  //Validation Logic
  if (isEmpty()) {std::cout << "\nError: List is already empty."; return false; }
  if (current == nullptr) {
    if (prev == nullptr) current = m_front; //Designed such that when both are nullptr, we're at the beginning, and...
    else { std::cout << "\nError: Number not in list."; return false; }                   //when current is nullptr but prev is not, we're at the end AND the Value was never found
  }

  //Evaluate the Node
  if (current->getValue() == value) { //Found the value, now remove it.
    if (current == m_front) m_front = m_front->getNext();  //Edge case: Adjust front pointer if removing first value.
    if (prev != nullptr) prev->setNext(current->getNext()); //Re-link if needed
    m_size--;
    delete current;
    std::cout << "\nNumber removed from list.";
    return true;
  } else { //Keep searching
    return erase(value, current->getNext(), current);
  }
}

//Adds a node to the end of this LinkedList. Abort upon detection of a duplicate value.
template <class T>
void LinkedList<T>::insert(T value, Node<T>* current)
{
  if (isEmpty()) {   //Validate existence of front Node.
    Node<T>* newNode = new Node<T>(value);
    m_front = newNode;
    m_size++;
    return;
  }
  if (current == nullptr) current = m_front; //Designed so this only occurs at entry of recursion. Allows usage of default parameter.
  if (current->getValue() == value) { //Disallow duplicates
    std::cout << "\nError: Duplicate found in list.";
    return;
  }
  if (current->getNext() != nullptr) insert(value, current->getNext()); //Recurse to end
  else {  //Time to insert - Create a new node and pin it to the end.
    Node<T>* newNode = new Node<T>(value);
    current->setNext(newNode);
    m_size++;
    std::cout << "\nNumber added to list.";
  }
}

template <class T>
void LinkedList<T>::print()
{
  if (isEmpty()) std::cout << "(Empty)";
  Node<T>* current = m_front;
  while (current != nullptr) {
    std::cout << current->getValue() << " ";
    current = current->getNext();
  }
}

template <class T>
Node<T>* LinkedList<T>::find(T value)
{
    Node<T>* current = m_front;

    while (current != nullptr)
      if (current->getValue() == value) return current;
      else current = current->getNext();

    return nullptr;
}

//Returns whether this LinkedList is empty.
template <class T>
bool LinkedList<T>::isEmpty()
{
  return m_size == 0;
}
