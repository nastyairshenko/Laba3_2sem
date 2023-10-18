#ifndef LAB3_2SEM_SEQUENCE_HPP
#define LAB3_2SEM_SEQUENCE_HPP

#pragma once

#include <tuple>

template <class T> class Sequence {
public:
    virtual T Get(int) const = 0;
    virtual int GetLength() const = 0;
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;
    virtual void Prepend(T) = 0;
    virtual Sequence<T>* Prepend(T) const = 0;
    virtual void Append(T) = 0;
    virtual Sequence<T>* Append(T) const = 0;
    virtual void InsertAt(T, int) = 0;
    virtual Sequence<T>* InsertAt(T, int) const = 0;
    virtual void Remove(T) = 0;
    virtual Sequence<T>* Remove(T) const = 0;
    virtual void RemoveAt(int) = 0;
    virtual Sequence<T>* RemoveAt(int) const = 0;
    virtual Sequence<T>* Concat(Sequence<T>*) const = 0;
    virtual Sequence<T> *operator+(Sequence<T>*) const = 0;
    virtual Sequence<T>* GetSubSequence(int, int) const = 0;
    virtual void Map(T(*func)(T)) = 0;
    virtual Sequence<T>* Map(T(*func)(T)) const = 0;
    virtual void Where(bool(*func)(T)) = 0;
    virtual Sequence<T>* Where(bool(*func)(T)) const = 0;
    virtual T Reduce(T(*func)(T, T), T) const = 0;
    virtual T Reduce(T(*func)(T, T)) const = 0;
    virtual T& operator[](int) = 0;
    virtual T operator[](int) const = 0;
    virtual ~Sequence() {};

};

#endif //LAB3_2SEM_SEQUENCE_HPP
