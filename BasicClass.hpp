#ifndef LAB3_2SEM_BASICCLASS_HPP
#define LAB3_2SEM_BASICCLASS_HPP

#pragma once
#include <iostream>
#include "Sequence.hpp"

template <class T> class BasicClass {
public:
    bool SubDetect(BasicClass<T>* PtrObject) const {
        if (PtrObject->Empty())
        { return false; }
        auto one = this->GetSequence();
        auto two = PtrObject->GetSequence();
        if (one == nullptr || two == nullptr)
        { throw std::invalid_argument("Nullptr..."); }
        int size1 = one->GetLength();
        int size2 = two->GetLength();
        if (size2 == 0)
        { return true; }
        if (size2 > size1)
        { return false; }
        for (int i = 0; i <= size1 - size2; i++) {
            bool mark = true;
            for (int j = 0; j < size2; j++) {
                if (one->Get(i + j) != two->Get(j)) {
                    mark = false;
                    break;
                }
            }
            if (mark)
            { return true; }
        }
        return false;
    }

    virtual int GetLength() const = 0;
    virtual bool Empty() const = 0;
    virtual BasicClass<T>* GetSubCollection(int, int) const = 0;
    virtual BasicClass<T>* Concat(BasicClass<T>*) const = 0;
    virtual void Push(T) = 0;
    virtual BasicClass<T>* Push(T) const = 0;
    virtual T Front() const = 0;
    virtual T Pop() = 0;
    virtual void Map(T(*func)(T)) = 0;
    virtual BasicClass<T>* Map(T(*func)(T)) const = 0;
    virtual void Where(bool(*func)(T)) = 0;
    virtual BasicClass<T>* Where(bool(*func)(T)) const = 0;
    virtual T Reduce(T(*func)(T, T)) const = 0;
    virtual Sequence<T>* GetSequence() const = 0;
    virtual ~BasicClass() {};
};


#endif //LAB3_2SEM_BASICCLASS_HPP