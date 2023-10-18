#include <iostream>
#include "Test.hpp"

bool Divis(int n) { return n % 2 == 0; }
int Pow(int n) { return n * n; }
int Sum(int a, int b) { return a + b; }

template <typename BaseCollection>
void TestEmpty(BaseCollection& collection) {
    cout << "Testing of Empty is ";
    assert(collection.Empty());
    collection.Push(1);
    assert(!collection.Empty());
    cout << "successful." << endl;
}

template <typename BaseCollection>
void TestGetLength(BaseCollection& collection) {
    cout << "Testing of GetLength is ";
    assert(collection.GetLength() == 0);
    collection.Push(1);
    assert(collection.GetLength() == 1);
    collection.Push(2);
    assert(collection.GetLength() == 2);
    cout << "successful." << endl;
}

template <typename T>
void TestFrontQ(Queue<T>& collection) {
    cout << "Testing of Front Queue is ";
    collection.Push(1);
    for (int i = 0; i < 10; i++) {
        collection.Push(i);
        assert(collection.Front() == 1);
    }
    cout << "successful." << endl;
}

template <typename T>
void TestFrontD(Deque<T>& collection) {
    cout << "Testing of Front Deque is ";
    collection.PushBack(1);
    for (int i = 0; i < 10; i++) {
        collection.PushBack(i);
        assert(collection.Front() == 1);
    }
    cout << "successful." << endl;
}

template <typename T>
void TestPopQ(Queue<T>& collection) {
    cout << "Testing of Pop Queue is ";
    for (int i = 0; i < 10; i++) {
        collection.Push(i);
    }
    for (int i = 0; i < 10; i++) {
        assert(collection.Pop() == i);
    }
    assert(collection.Empty());
    cout << "successful." << endl;
}

template <typename T>
void TestPopD(Deque<T>& collection) {
    cout << "Testing of Pop Deque is ";
    for (int i = 0; i < 10; i++) {
        collection.PushBack(i);
    }
    for (int i = 0; i < 10; i++) {
        assert(collection.Pop() == i);
    }
    assert(collection.Empty());
    cout << "successful." << endl;
}

template <typename T>
void TestMapQ(Queue<T>& collection) {
    cout << "Testing of Map Queque is ";
    for (int i = 0; i < 10; i++) {
        collection.Push(i);
    }
    collection.Map(Pow);
    for (int i = 0; i < 10; i++) {
        assert(collection.Pop() == i * i);
    }
    cout << "successful." << endl;
}

template <typename T>
void TestMapD(Deque<T>& collection) {
    cout << "Testing of Map Deque is ";
    for (int i = 0; i < 10; i++) {
        collection.PushBack(i);
    }
    collection.Map(Pow);
    for (int i = 0; i < 10; i++) {
        assert(collection.Pop() == i * i);
    }
    cout << "successful." << endl;
}

template <typename BaseCollection>
void TestGetSubCollection(BaseCollection& collection) {
    cout << "Testing of GetSubCollection is ";
    for (int i = 0; i < 10; i++) {
        collection.Push(i);
    }
    BaseCollection* sub = collection.GetSubCollection(0, 5);
    assert(sub->GetLength() == 6);
    assert(collection.SubDetect(sub));
    delete sub;
    cout << "successful." << endl;
}


template <typename BaseCollection>
void TestWhere(BaseCollection& collection) {
    cout << "Testing of Where is ";
    for (int i = 0; i < 10; i++) {
        collection.Push(i);
    }
    collection.Where(Divis);
    assert(collection.GetLength() == 5);
    for (int i = 0; i < 5; i++) {
        assert(collection.Pop() % 2 == 0);
    }
    cout << "successful." << endl;
}

template <typename BaseCollection>
void TestReduce(BaseCollection& collection) {
    cout << "Testing of Reduce is ";
    for (int i = 0; i < 10; i++) {
        collection.Push(i);
    }
    assert(collection.Reduce(Sum) == 45);
    cout << "successful." << endl;
}

template <typename BaseCollection>
void TestConcat(BaseCollection& collection1, BaseCollection& collection2) {
    cout << "Testing of Concat is ";
    for (int i = 0; i < 15; i++) {
        collection1.Push(i);
    }
    for (int i = 15; i < 30; i++) {
        collection2.Push(i);
    }
    BaseCollection* collection3 = collection1.Concat(&collection2);
    assert(collection3->GetLength() == 30);
    assert(collection3->SubDetect(&collection1) && collection3->SubDetect(&collection2));
    delete collection3;
    cout << "successful." << endl;
}


template <typename BaseCollection>
void TestSubDetect(BaseCollection& collection, BaseCollection& collection2) {
    cout << "Testing of TestSubDetect is ";
    for (int i = 0; i < 20; i++) {
        collection.Push(i);
    }
    for (int i = 8; i < 19; i++) {
        collection2.Push(i);
    }
    assert(collection.SubDetect(&collection2));
    cout << "successful." << endl;
}

template <typename T>
void TestDivide(Queue<T>& queue) {
    cout << "Testing of Divide is ";
    for (int i = 0; i < 10; i++) {
        queue.Push(i);
    }
    T thing = 5;
    auto result = queue.Divide(5);
    Queue<int>* left = get<0>(result);
    Queue<int>* right = get<1>(result);
    assert(left->GetLength() == thing);
    assert(right->GetLength() == 10 - thing - 1);
    for (int i = 0; i < thing; i++) {
        assert(left->Pop() == i);
    }
    for (int i = thing + 1; i < 10; i++) {
        assert(right->Pop() == i);
    }
    delete left;
    delete right;
    cout << "successful." << endl;
    cout << "That's okey!" << endl;
}


void Testing(){

    Queue<int> *queue = nullptr;
    Deque<int> *deque = nullptr;

    queue = new Queue<int>();
    deque = new Deque<int>();
    TestEmpty(*queue);
    TestEmpty(*deque);
    delete queue;
    delete deque;

    queue = new Queue<int>();
    deque = new Deque<int>();
    TestGetLength(*queue);
    TestGetLength(*deque);
    delete queue;
    delete deque;

    queue = new Queue<int>();
    deque = new Deque<int>();
    TestFrontQ(*queue);
    TestFrontD(*deque);
    delete queue;
    delete deque;

    queue = new Queue<int>();
    deque = new Deque<int>();
    TestPopQ(*queue);
    TestPopD(*deque);
    delete queue;
    delete deque;

    queue = new Queue<int>();
    deque = new Deque<int>();
    TestMapQ(*queue);
    TestMapD(*deque);
    delete queue;
    delete deque;

    queue = new Queue<int>();
    deque = new Deque<int>();
    TestGetSubCollection(*queue);
    TestGetSubCollection(*deque);
    delete queue;
    delete deque;

    queue = new Queue<int>();
    deque = new Deque<int>();
    TestWhere(*queue);
    TestWhere(*deque);
    delete queue;
    delete deque;

    queue = new Queue<int>();
    deque = new Deque<int>();
    TestReduce(*queue);
    TestReduce(*deque);
    delete queue;
    delete deque;

    queue = new Queue<int>();
    deque = new Deque<int>();
    auto *queue2 = new Queue<int>();
    auto *dequeue2 = new Deque<int>();
    TestConcat(*queue, *queue2);
    TestConcat(*deque, *dequeue2);
    delete queue;
    delete queue2;
    delete deque;
    delete dequeue2;

    queue = new Queue<int>();
    deque = new Deque<int>();
    queue2 = new Queue<int>();
    dequeue2 = new Deque<int>();
    TestSubDetect(*queue, *queue2);
    TestSubDetect(*deque, *dequeue2);
    delete queue;
    delete queue2;
    delete deque;
    delete dequeue2;

    queue = new Queue<int>();
    TestDivide(*queue);
    delete queue;
}

