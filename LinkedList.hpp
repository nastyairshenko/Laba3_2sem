#ifndef LAB3_2SEM_LINKEDLIST_HPP
#define LAB3_2SEM_LINKEDLIST_HPP

#pragma once

#include <iostream>

template <class T> class LinkedList {
public:
    class Node {
    public:
        T Point;
        Node *Next;
        explicit Node(T point) : Point(point), Next(nullptr) {};
        T operator*()
        { return this->Point; }
    };

    LinkedList() : First(nullptr), Last(nullptr) {};

    LinkedList(T *array, int number) : LinkedList() {
        if (number == 0)
            return;
        this->size = number;
        for (int i = 0; i < number; i++){
            this->Append(array[i]);
        }
    }

    LinkedList(const LinkedList<T> &list) : LinkedList() {
        for (auto i : list) {
            this->Append(i);
        }
    }

    T GetFirst() const {
        if (this->First == nullptr)
        { throw std::out_of_range("List is empty"); }
        return this->First->Point;
    }

    T GetLast() const {
        if (this->Last == nullptr)
        { throw std::out_of_range("List is empty"); }
        return this->Last->Point;
    }

    T Get(int k) const  {
        if (k >= this->size || k < 0)
        { throw std::out_of_range("Index out of range"); }
        Node *now = this->First;
        for (int i = 0; i < k; i++) {
            now = now->Next;
        }
        return now->Point;
    }

    int GetLength() const {
        return this->size;
    }

    LinkedList<T> *GetSubList(int first, int last) const {
        if (first < 0 || last >= this->size || first > last)
        { throw std::out_of_range("Index out of range"); }
        auto *result = new LinkedList<T>();
        Node *now = this->First;
        for (int i = 0; i < first; i++) {
            now = now->Next;
        }
        for (int i = first; i <= last; i++) {
            result->Append(now->Point);
            now = now->Next;
        }
        return result;
    }

    void Prepend(T thing) {
        Node *newNode = new Node(thing);
        if (this->First == nullptr) {
            this->First = newNode;
            this->Last = newNode;
        } else {
            newNode->Next = this->First;
            this->First = newNode;
        }
        this->size++;
    }

    LinkedList<T> *Prepend(T item) const {
        auto *copy = new LinkedList<T>(*this);
        copy->Prepend(item);
        return copy;
    }


    void Append(T thing) {
        Node *newNode = new Node(thing);
        if (this->First == nullptr) {
            this->First = newNode;
            this->Last = newNode;
        }
        else {
            this->Last->Next = newNode;
            this->Last = newNode;
        }
        this->size++;
    }

    LinkedList<T> *Append(T thing) const {
        auto *copy = new LinkedList<T>(*this);
        copy->Append(thing);
        return copy;
    }


    void InsertAt(T thing, int k) {
        if (k >= this->size || k < 0)
        { throw std::out_of_range("Index out of range"); }
        Node *newNode = new Node(thing);
        if (k == 0) {
            if (this->First == nullptr) {
                this->First = newNode;
                this->Last = newNode;
            }
            else {
                newNode->Next = this->First;
                this->First = newNode;
            }
        }
        else {
            Node *now = this->First;
            for (int i = 0; i < k - 1; i++) {
                now = now->Next;
            }
            newNode->Next = now->Next;
            now->Next = newNode;
        }
        this->size++;
    }

    LinkedList<T> *InsertAt(T thing, int k) const {
        auto *copy = new LinkedList<T>(*this);
        copy->InsertAt(thing, k);
        return copy;
    }

    LinkedList<T> *Concat(const LinkedList<T> &list) const {
        auto *result = new LinkedList<T>(*this);
        for (auto i : list) {
            result->Append(i);
        }
        return result;
    }

    void RemoveAt(int k) {
        if (k < 0 || k >= this->size)
        { throw std::out_of_range("Index out of range"); }
        if(k != 0) {
            Node *now = this->First;
            for (int i = 0; i < k - 1; i++) {
                now = now->Next;
            }
            Node *thing = now->Next;
            if (thing == this->Last) {
                this->Last = now;
            }
            now->Next = now->Next->Next;
            delete thing;
        }
        if (k == 0) {
            if (this->First == this->Last) {
                delete this->First;
                this->First = nullptr;
                this->Last = nullptr;
            }
            else {
                Node *thing = this->First;
                this->First = this->First->Next;
                delete thing;
            }
        }
        this->size--;
    }

    void Remove(T thing) {
        int k = 0;
        Node *now = this->First;
        while (now != nullptr) {
            if (now->Point == thing) {
                this->RemoveAt(k);
                return;
            }
            now = now->Next;
            k+=1;
        }
        throw std::invalid_argument("Value not found");
    }

    T& operator[](int k)
    { return this->LinkedListVal(k); }

    const T operator[](int k) const
    { return this->Get(k); }

    class Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = Node*;
        using reference = value_type&;
        pointer ptr;
    public:
        Iterator(pointer ptr)
        { this->ptr = ptr; }

        Iterator &operator++() {
            this->ptr = this->ptr->Next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator thing = *this;
            this->ptr = this->ptr->Next;
            return thing;
        }

        bool operator==(const Iterator &other) const
        { return this->ptr == other.ptr; }

        bool operator!=(const Iterator &other) const
        { return this->ptr != other.ptr; }

        reference operator*()
        { return ptr->Point; }

        pointer operator->()
        { return ptr; }
    };

    class ConstIterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = Node*;
        using reference = value_type&;
        pointer ptr;
    public:
        ConstIterator(pointer ptr)
        { this->ptr = ptr; }

        ConstIterator &operator++() {
            this->ptr = this->ptr->Next;
            return *this;
        }

        ConstIterator operator++(int) {
            ConstIterator thing = *this;
            this->ptr = this->ptr->Next;
            return thing;
        }

        bool operator==(const ConstIterator &other) const
        { return this->ptr == other.ptr; }

        bool operator!=(const ConstIterator &other) const
        { return this->ptr != other.ptr; }

        const T& operator*()
        { return ptr->Point; }

        const Node *operator->()
        { return ptr; }
    };

    Iterator begin()
    { return Iterator(this->First); }

    Iterator end()
    { return Iterator(nullptr); }

    ConstIterator begin() const
    { return ConstIterator(this->First); }

    ConstIterator end() const
    { return ConstIterator(nullptr); }

    ~LinkedList() {
        Node *now = this->First;
        while (now != nullptr) {
            Node *next = now->Next;
            delete now;
            now = next;
        }
        this->First = nullptr;
        this->Last = nullptr;
        this->size = 0;
    }

private:
    int size = 0;
    Node *First;
    Node *Last;

protected:
    T& LinkedListVal(int k) {
        Node *now = this->First;
        for (int i = 0; i < k; i++) {
            now = now->Next;
        }
        return now->Point;
    }
};
#endif //LAB3_2SEM_LINKEDLIST_HPP
