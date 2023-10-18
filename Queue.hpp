#ifndef LAB3_2SEM_QUEUE_HPP
#define LAB3_2SEM_QUEUE_HPP

#pragma once
#include <iostream>
#include "BasicClass.hpp"
#include "LinkedListSequence.hpp"
#include "Sequence.hpp"
using namespace std;

template <class T>
class Queue : public BasicClass<T> {
    Sequence<T>* sequence;
public:
    Queue()
    { this->sequence = new LinkedListSequence<T>(); }

    Queue(const BasicClass<T>& collection)
    { this->sequence = new LinkedListSequence<T>(collection.GetSequence()); }

    bool Empty() const override
    { return this->GetLength() == 0; }

    T Front() const override {
        if (Empty())
        { throw out_of_range("Queue is empty"); }
        return this->sequence->GetFirst();
    }

    T Pop() override {
        if (Empty())
        { throw out_of_range("Queue is empty"); }
        T thing = this->sequence->GetFirst();
        this->sequence->RemoveAt(0);
        return thing;
    }

    int GetLength() const override
    { return this->sequence->GetLength(); }

    Queue<T>* GetSubCollection(int first, int last) const override {
        auto* copy = new Queue<T>(*this);
        copy->sequence = this->sequence->GetSubSequence(first, last);
        return copy;
    }

    Queue<T>* Concat(BasicClass<T>* c) const override {
        auto* copy = new Queue<T>(*this);
        copy->sequence = this->sequence->Concat(c->GetSequence());
        return copy;
    }

    void Push(T thing) override
    { this->sequence->Append(thing); }

    Queue<T>* Push(T thing) const override {
        auto* copy = new Queue<T>(*this);
        copy->Push(thing);
        return copy;
    }

    void Map(T(*func)(T)) override
    { this->sequence->Map(func); }

    BasicClass<T>* Map(T(*func)(T)) const override {
        auto* copy = new Queue<T>(*this);
        copy->Map(func);
        return copy;
    }

    void Where(bool(*func)(T)) override
     { this->sequence->Where(func); }

    BasicClass<T>* Where(bool(*func)(T)) const override {
        auto* copy = new Queue<T>(*this);
        copy->Where(func);
        return copy;
    }

    T Reduce(T(*func)(T, T)) const override
    { return this->sequence->Reduce(func); }

    tuple <Queue<T>*, Queue<T>*> Divide(T thing) const {
        Sequence<T> * seq = this->GetSequence();
        bool exists = false;
        for (int i = 0; i < this->GetLength(); i++) {
            if (seq->Get(i) == thing) {
                exists = true;
                break;
            }
        }
        if (!exists)
        { throw std::out_of_range("No such item"); }
        auto* left = new Queue<T>();
        auto* right = new Queue<T>(*this);
        while (!right->Empty() && right->Front() != thing) {
            left->Push(right->Pop());
        }
        if (!right->Empty())
        { right->Pop(); }
        return make_tuple(left, right);
    }

    Sequence<T>* GetSequence() const override
    { return this->sequence; }

    ~Queue()
     { delete this->sequence; }
};
#endif //LAB3_2SEM_QUEUE_HPP
