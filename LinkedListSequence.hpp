#ifndef LAB3_2SEM_LINKEDLISTSEQUENCE_HPP
#define LAB3_2SEM_LINKEDLISTSEQUENCE_HPP

#pragma once
#include "LinkedList.hpp"
#include "Sequence.hpp"


template <class T> class LinkedListSequence : public Sequence<T> {
    LinkedList<T> *General;
public:
    LinkedListSequence() : General(new LinkedList<T>()) {};
    LinkedListSequence(T *array, int number) : General(new LinkedList<T>(array, number)) {};
    LinkedListSequence(const LinkedList<T> &list) : General(new LinkedList<T>(list)) {};
    LinkedListSequence(const LinkedListSequence<T> &list) : General(new LinkedList<T>(*list.General)) {};
    LinkedListSequence(Sequence<T> *seq) : General(new LinkedList<T>()) {
        for (int i = 0; i < seq->GetLength(); i++) {
            this->General->Append(seq->Get(i));
        }
    };

    T GetFirst() const override
    { return this->General->GetFirst(); }

    T GetLast() const override
    { return this->General->GetLast(); }

    T Get(int k) const override
    { return this->General->Get(k); }

    int GetLength() const override
    { return this->General->GetLength(); }

    LinkedListSequence<T> *GetSubSequence(int First, int Last) const override {
        LinkedList<T>* new_list = this->General->GetSubList(First, Last);
        auto* res = new LinkedListSequence(*new_list);
        delete new_list;
        return res;
    }


    void Prepend(T thing) override
    { this->General->Prepend(thing); }

    LinkedListSequence<T> *Prepend(T thing) const override {
        auto *copy = new LinkedListSequence<T>(*this);
        copy->Prepend(thing);
        return copy;
    }

    void Append(T thing) override
    { this->General->Append(thing); }

    LinkedListSequence<T> *Append(T thing) const override {
        auto *copy = new LinkedListSequence<T>(*this);
        copy->Append(thing);
        return copy;
    }

    void InsertAt(T thing, int k) override
    { this->General->InsertAt(thing, k); }

    LinkedListSequence<T> *InsertAt(T thing, int k) const override {
        auto *copy = new LinkedListSequence<T>(*this);
        copy->InsertAt(thing, k);
        return copy;
    }

    LinkedListSequence<T> *Concat(Sequence<T> *list) const override {
        auto *res = new LinkedListSequence<T>(*this);
        for (int i = 0; i < list->GetLength(); i++) {
            res->Append(list->Get(i));
        }
        return res;
    }

    Sequence<T> *operator+(Sequence<T> *list) const override
    { return this->Concat(list); }

    void Where(bool (*function)(T)) override {
        auto *copy = new LinkedList<T>();
        for (int k = 0; k < this->GetLength(); k++) {
            if (function(this->Get(k)))
            { copy->Append(this->Get(k)); }
        }
        delete this->General;
        this->General = copy;
    }

    LinkedListSequence<T> *Where(bool (*function)(T)) const override {
        auto *copy = new LinkedListSequence<T>(*this);
        copy->Where(function);
        return copy;
    }

    void Map(T (*function)(T)) override {
        for (int k = 0; k < this->GetLength(); k++) {
            (*this->General)[k] = function(this->Get(k));
        }
    }

    LinkedListSequence<T> *Map(T (*function)(T)) const override {
        auto *copy = new LinkedListSequence<T>(*this);
        copy->Map(function);
        return copy;
    }

    T Reduce(T (*function)(T, T)) const override {
        T val = this->Get(0);
        for (int i = 1; i < this->GetLength(); i++) {
            val = function(val, this->Get(i));
        }
        return val;
    }

    T Reduce(T (*function)(T, T), T sym) const override {
        T val = sym;
        for (int k = 0; k < this->GetLength(); k++) {
            val = function(val, this->Get(k));
        }
        return val;
    }

    void RemoveAt(int k) override
    { this->General->RemoveAt(k); }

    LinkedListSequence<T> *RemoveAt(int k) const override {
        auto *copy = new LinkedListSequence<T>(*this);
        copy->RemoveAt(k);
        return copy;
    }

    void Remove(T thing) override
    { this->General->Remove(thing); }

    LinkedListSequence<T> *Remove(T thing) const override {
        auto *copy = new LinkedListSequence<T>(*this);
        copy->Remove(thing);
        return copy;
    }

    T& operator[](int k) override
    { return (*this->General)[k]; }

    T operator[](int k) const override
    { return this->General->Get(k); }

    using Iterator = class LinkedList<T>::Iterator;
    using ConstIterator = class LinkedList<T>::ConstIterator;
    Iterator begin() { return this->General->begin(); }
    Iterator end() { return this->General->end(); }
    ConstIterator begin() const { return ((const LinkedList<T>*)this->General)->begin(); }
    ConstIterator end() const { return ((const LinkedList<T>*)this->General)->end(); }

    ~LinkedListSequence()
    { delete this->General; }
};
#endif //LAB3_2SEM_LINKEDLISTSEQUENCE_HPP
