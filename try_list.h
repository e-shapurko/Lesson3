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

//    template<typename U>
    template<typename U>
    class Node;

    class iterator
    {
        Node<T>* current_node;
    public:
        iterator(Node<T>* first ) : current_node(first){}

        operator + (int n)
        {
            current_node = (current_node + n)->pNext;
            return *current_node;
        }

        operator ++ ()
        {
            current_node = current_node->pNext;
            return *current_node;
        }

        bool operator != (const iterator& it)
        {
            return current_node != it.current_node;
        }

        bool operator == (const iterator& it)
        {
            return current_node == it.current_node;
        }

        T& operator* ()
        {
//            current_node = current_node->pNext;
            return current_node->data;
        }
	}
    iterator begin() {return m_head;}
    iterator end() {return m_head + m_size;}


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
            (current->pNext) = m_allocator.allocate(1);
            current->pNext->data = data;
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
    std::size_t m_size;
    Node<T> *m_head;
    using node_alloc = typename alloc::template rebind<Node<T>>::other;
    node_alloc m_allocator;




};

#endif // TRY_LIST_H
