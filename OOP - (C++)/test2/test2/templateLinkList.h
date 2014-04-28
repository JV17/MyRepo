#include <cstring>


template <class T>
class Node
{
private:
    T _data;
    Node* _next;
protected:
public:
    Node(T a, Node* n = nullptr)
    {
        _data = a;
        _next = n;
    }


    ~Node() {}


    Node*& next() { return _next; }
    T& data() { return _data; }
};


template <>
Node<char*>::~Node()
{
    if (_data)
        delete[] _data;
}


template <>
Node<char*>::Node(char* a, Node<char*>* t)
{
    if (a)
    {
        _data = new char[strlen(a) + 1];
        strcpy(_data, a);
    }
    else
        _data = nullptr;
    _next = t;
}


template <class T>
class LinkedList
{
private:
    Node<T>* front;
    unsigned int size;
protected:
    bool findBack(Node<T>*& ref)
    {
        if (front)
        {
            if (front->next())
            {
                auto a = front;
                while (a->next()->next()) a = a->next();
                ref = a;
                return true;
            }
            else
            {
                ref = front;
                return false;
            }
        }
        return false;
    }
public:
    LinkedList() : front(nullptr), size(0) {}
    T& getFront()
    {
        return front->data();
    }


    T& getLast()
    {
        Node<T>* r = nullptr;
        if (findBack(r))
            return r->next()->data();
        else
            return r->data();
    }


    void push_front(T a)
    {
        front = new Node<T>(a, front);
        size++;
    }
    void push_back(T a)
    {
        Node<T>* r = nullptr;
        bool isBeforeBack = findBack(r);
        auto n = new Node<T>(a);
        size++;
        if (r)
        {
            if (!isBeforeBack)
                front->next() = n;
            else
                r->next()->next() = n;
        }
        else
            front = n;
    }


    void pop_front()
    {
        auto a = front;
        front = a->next();
        delete a;
        size--;
    }
    void pop_back()
    {
        Node<T>* ref;
        auto isBeforeBack = findBack(ref);
        if (ref)
        {
            size--;
            if (!isBeforeBack)
            {
                delete front;
                front = nullptr;
            }
            else
            {
                delete ref->next();
                ref->next() = nullptr;
            }
        }
    }
    ~LinkedList() {}
};