////////////////////////////////////////////////////////////////////////////////
// Module Name:  linked_list.h/cpp
// Authors:      Sergey Shershakov, Leonid Dworzanski
// Version:      0.2.0
// Date:         06.02.2017
// Copyright (c) The Team of "Algorithms and Data Structures" 2014–2017.
//
// This is a part of the course "Algorithms and Data Structures"
// provided by  the School of Software Engineering of the Faculty
// of Computer Science at the Higher School of Economics.
//
// Отделенная часть заголовка шаблона класса "Связанный список"
//
////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>

namespace xi
{

template<class T>
LinkedList<T>::LinkedList()
{
    //Creation of the dummy/sentinel element
    _preHead = new Node<T>;
    _preHead->next = nullptr;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    delete[] _preHead;
    // TODO: Write your code here

}


// TODO: Write your code here

template<class T>
xi::Node<T> *xi::LinkedList<T>::getPreHead()
{
    return _preHead;
}

template<class T>
T &xi::LinkedList<T>::operator[](int i)
{
    Node<T> *buff = _preHead;
    if (i < 0)
        throw std::out_of_range("OE");

    for (i; i >= 0; i--)
    {
        if (buff->next == nullptr)
            throw std::out_of_range("OEE");
        buff = buff->next;
    }
    return buff->value;

}

template<class T>
int xi::LinkedList<T>::size()
{
    Node<T> *node = getPreHead();
    int i = 0;
    while (node->next != nullptr)
    {
        node = node->next;
        i++;
    }
    return i;
}

template<class T>
void xi::LinkedList<T>::addElementToEnd(T &value)
{
    Node<T> *buff = getLast();
    buff->next = new Node<T>(value);
}

template<class T>
void xi::LinkedList<T>::deleteNodes(xi::Node<T> *pNodeBefore, xi::Node<T> *pNodeLast)
{
    Node<T> *Anote;
    do
    {
        Anote = pNodeBefore->next;
        pNodeBefore->next = Anote->next;
        delete Anote;
    } while (Anote != pNodeLast);
}

template<class T>
void xi::LinkedList<T>::deleteNextNode(xi::Node<T> *pNodeBefore)
{
    if (pNodeBefore->next == nullptr)
        return;
    Node<T> *ANote = pNodeBefore->next;
    pNodeBefore->next = ANote->next;
    delete ANote;
}

template<class T>
void xi::LinkedList<T>::moveNodesToEnd(xi::Node<T> *pNodeBefore, xi::Node<T> *pNodeLast)
{
    Node<T> *buffer = LinkedList::_preHead;
    while (buffer->next != nullptr)
    {
        buffer = buffer->next;
    }
    buffer->next = pNodeBefore->next;
    pNodeBefore->next = pNodeLast->next;
    pNodeLast->next = nullptr;
}

template<class T>
void xi::LinkedList<T>::moveNodeToEnd(xi::Node<T> *pNodeBefore)
{
    if (pNodeBefore->next == nullptr)
        return;
    else
    {
        Node<T> *node = _preHead;
        while (node->next != nullptr)
        {
            node = node->next;
        }
        node->next = pNodeBefore->next;
        Node<T> *nameBuffer = pNodeBefore->next->next;
        pNodeBefore->next->next = nullptr;
        pNodeBefore->next = nameBuffer;
    }
}

template<class T>
void xi::LinkedList<T>::moveNodesAfter(xi::Node<T> *pNode, xi::Node<T> *pNodeBefore, xi::Node<T> *pNodeLast)
{
    if (pNodeBefore == nullptr || pNodeBefore->next == nullptr || pNodeLast == nullptr)
        return;
    Node<T> *node = pNodeBefore->next;
    pNodeBefore->next = pNodeLast->next;
    pNodeLast->next = pNode->next;
    pNode->next = node;
}

template<class T>
void xi::LinkedList<T>::moveNodeAfter(xi::Node<T> *pNode, xi::Node<T> *pNodeBefore)
{
    Node<T> *buff = pNodeBefore->next->next;
    Node<T> *buffer = pNode->next;
    pNode->next = pNodeBefore->next;
    pNodeBefore->next->next = buffer;
    pNodeBefore->next = buff;
}

template<class T>
Node <T> *LinkedList<T>::getLast()
{
    Node<T> *buff = getPreHead();
    while (buff->next != nullptr)
    {
        buff = buff->next;
    }
    return buff;
}


} // namespace xi
