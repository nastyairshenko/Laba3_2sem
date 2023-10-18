#ifndef LAB3_2SEM_DEQUE_HPP
#define LAB3_2SEM_DEQUE_HPP

#pragma once
#include <iostream>
#include "BasicClass.hpp"
#include "LinkedListSequence.hpp"
#include "Sequence.hpp"

template <class T>
class Deque : public BasicClass<T> {
    Sequence<T>* sequence;
public:
    Deque()
    { this->sequence = new LinkedListSequence<T>(); }

    explicit Deque(const BasicClass<T>& c)
    { this->sequence = new LinkedListSequence<T>(c.GetSequence()); }

    bool Empty() const override
    { return this->GetLength() == 0; }

    T Front() const override {
        if (Empty())
        { throw out_of_range("Deque is empty"); }
        return this->sequence->GetFirst();
    }

    T Back() const {
        if (Empty())
        { throw out_of_range("Deque is empty"); }
        return this->sequence->GetLast();
    }

    T Pop() override {
        if (Empty())
        { throw out_of_range("Deque is empty"); }
        T val = this->sequence->GetFirst();
        this->sequence->RemoveAt(0);
        return val;
    }

    T PopBack() {
        if (Empty())
        { throw out_of_range("Deque is empty"); }
        T thing = this->sequence->GetLast();
        this->sequence->RemoveAt(this->GetLength() - 1);
        return thing;
    }

    int GetLength() const override
    { return this->sequence->GetLength(); }

    Deque<T>* GetSubCollection(int first, int last) const override {
        auto* copy = new Deque<T>(*this);
        copy->sequence = this->sequence->GetSubSequence(first, last);
        return copy;
    }

    Deque<T>* Concat(BasicClass<T>* c) const override {
        auto* copy = new Deque<T>(*this);
        copy->sequence = this->sequence->Concat(c->GetSequence());
        return copy;
    }

    void Push(T thing) override
    { this->sequence->Prepend(thing); }

    void PushBack(T thing)
    { this->sequence->Append(thing); }

    Deque<T>* Push(T thing) const override {
        auto* copy = new Deque<T>(*this);
        copy->Push(thing);
        return copy;
    }

    Deque<T>* PushBack(T thing) const {
        auto* copy = new Deque<T>(*this);
        copy->PushBack(thing);
        return copy;
    }

    void Map(T(*func)(T)) override
    { this->sequence->Map(func); }

    BasicClass<T>* Map(T(*func)(T)) const override {
        auto* copy = new Deque<T>(*this);
        copy->Map(func);
        return copy;
    }

    void Where(bool(*func)(T)) override
    { this->sequence->Where(func); }

    BasicClass<T>* Where(bool(*func)(T)) const override {
        auto* copy = new Deque<T>(*this);
        copy->Where(func);
        return copy;
    }

    T Reduce(T(*func)(T, T)) const override
    { return this->sequence->Reduce(func); }

    Sequence<T>* GetSequence() const override
    { return this->sequence; }

    ~Deque()
    { delete this->sequence; }
};

#endif //LAB3_2SEM_DEQUE_HPP
