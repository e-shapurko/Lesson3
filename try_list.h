#ifndef TRY_LIST_H
#define TRY_LIST_H

#include <iostream>

template<typename T, class alloc = std::allocator<T>>
class try_list
{
public:
    try_list()
    {
        m_head = nullptr;
        m_size = 0;
    }

    T& operator[](const int index)
    {
        int counter = 0;
        Node<T> *current = this->m_head;
        while (current != nullptr)
        {
            if (counter == index)
            {
                return current->data;
            }
            current = current->pNext;
            counter++;
        }
    }

    void push_back(T data)
    {
        if (m_head == nullptr)
        {
            m_head = m_allocator.allocate(1);
            *m_head = data;
        }
        else
        {
            Node<T> *current = this->m_head;
            while (current->pNext != nullptr)
            {
                current = current->pNext;
            }
            current->pNext = m_allocator.allocate(1);

        }
        m_size++;
    }


private:

    template<typename U>
    class Node
    {
    public:
        Node *pNext;
        U data;

        Node(U data = U(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int m_size;
    Node<T> *m_head;
    using node_alloc = typename alloc::template rebind<T>::other;
    node_alloc m_allocator;



};

#endif // TRY_LIST_H
