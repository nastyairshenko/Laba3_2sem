#ifndef LAB3_2SEM_DYNAMICARRAYSEQUENCE_HPP
#define LAB3_2SEM_DYNAMICARRAYSEQUENCE_HPP
#pragma once

#include "DynamicArray.hpp"
#include "Sequence.hpp"

template <class T> class ArraySequence : public Sequence<T> {

    DynamicArray<T> *buffer;

public:
    ArraySequence() : buffer(new DynamicArray<T>()) {};

    ArraySequence(T *items, int count) : buffer(new DynamicArray<T>(items, count)) {};

    ArraySequence(const DynamicArray<T> &input_array) : buffer(new DynamicArray<T>(input_array)) {};

    ArraySequence(const ArraySequence<T> &input_array) : buffer(new DynamicArray<T>(*input_array.buffer)) {};

    ArraySequence(Sequence<T> *input_sequence) : buffer(new DynamicArray<T>()) {
        for (int i = 0; i < input_sequence->GetLength(); i++) {
            this->buffer->Append(input_sequence->Get(i));
        }
    };

    T GetFirst() const override {
        return this->buffer->GetFirst();
    }

    T GetLast() const override {
        return this->buffer->GetLast();
    }

    T Get(int index) const override {
        return this->buffer->Get(index);
    }

    ArraySequence<T> *GetSubSequence(int startIndex, int endIndex) const override {
        DynamicArray<T>* tmp = this->buffer->GetSubArray(startIndex, endIndex);
        ArraySequence<T>* res = new ArraySequence(*tmp);
        delete tmp;
        return res;
    }

    int GetLength() const override {
        return this->buffer->GetLength();
    }

    void Append(T item) override {
        this->buffer->Append(item);
    }

    ArraySequence<T> *Append(T item) const override {
        ArraySequence<T> *copy = new ArraySequence<T>(*this);
        copy->Append(item);
        return copy;
    }

    void Prepend(T item) override {
        this->buffer->Prepend(item);
    }

    ArraySequence<T> *Prepend(T item) const override {
        ArraySequence<T> *copy = new ArraySequence<T>(*this);
        copy->Prepend(item);
        return copy;
    }

    void InsertAt(T item, int index) override {
        this->buffer->InsertAt(item, index);
    }

    ArraySequence<T> *InsertAt(T item, int index) const override {
        ArraySequence<T> *copy = new ArraySequence<T>(*this);
        copy->InsertAt(item, index);
        return copy;
    }

    void RemoveAt(int index) override {
        this->buffer->RemoveAt(index);
    }

    ArraySequence<T> *RemoveAt(int index) const override {
        ArraySequence<T> *copy = new ArraySequence<T>(*this);
        copy->RemoveAt(index);
        return copy;
    }

    void Remove(T item) override {
        this->buffer->Remove(item);
    }

    ArraySequence<T> *Remove(T item) const override {
        ArraySequence<T> *copy = new ArraySequence<T>(*this);
        copy->Remove(item);
        return copy;
    }

    ArraySequence<T> *Concat(Sequence<T> *input_sequence) const override {
        ArraySequence<T> *res = new ArraySequence<T>(*this);
        for (int i = 0; i < input_sequence->GetLength(); i++) {
            res->Append(input_sequence->Get(i));
        }
        return res;
    }

    void Map(T(*func)(T)) override {
        for (int i = 0; i < this->GetLength(); i++) {
            (*this->buffer)[i] = func(this->buffer->Get(i));
        }
    }

    ArraySequence<T> *Map(T(*func)(T)) const override {
        ArraySequence<T> *copy = new ArraySequence<T>(*this);
        copy->Map(func);
        return copy;
    }

    void Where(bool(*func)(T)) override {
        DynamicArray<T> *tmp = new DynamicArray<T>();
        for (int i = 0; i < this->GetLength(); i++) {
            if (func(this->buffer->Get(i))) {
                tmp->Append(this->buffer->Get(i));
            }
        }
        delete this->buffer;
        this->buffer = tmp;
    }

    ArraySequence<T> *Where(bool(*func)(T)) const override {
        ArraySequence<T> *copy = new ArraySequence<T>(*this);
        copy->Where(func);
        return copy;
    }

    T Reduce(T(*func)(T, T), T initial_value) const override {
        T res = initial_value;
        for (int i = 0; i < this->GetLength(); i++) {
            res = func(res, this->buffer->Get(i));
        }
        return res;
    }

    T Reduce(T(*func)(T, T)) const override {
        T res = this->buffer->Get(0);
        for (int i = 1; i < this->GetLength(); i++) {
            res = func(res, this->buffer->Get(i));
        }
        return res;
    }

    T& operator[](int index) override {
        return (*this->buffer)[index];
    }

    T operator[](int index) const override {
        return (*this->buffer)[index];
    }

    Sequence<T> *operator+(Sequence<T> *input_sequence) const override {
        return this->Concat(input_sequence);
    }

    using Iterator = class DynamicArray<T>::Iterator;
    using ConstIterator = class DynamicArray<T>::ConstIterator;

    Iterator begin() { return this->buffer->begin(); }
    Iterator end() { return this->buffer->end(); }

    ConstIterator begin() const {
        return ((const DynamicArray<T>*)this->buffer)->begin(); }
    ConstIterator end() const {
        return ((const DynamicArray<T>*)this->buffer)->end();
    }

    ~ArraySequence() {
        delete this->buffer;
    }
};


#endif //LAB3_2SEM_DYNAMICARRAYSEQUENCE_HPP
