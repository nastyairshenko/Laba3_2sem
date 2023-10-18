#ifndef LAB3_2SEM_TEST_HPP
#define LAB3_2SEM_TEST_HPP
#include <cassert>
#include "Test.hpp"
#include "BasicClass.hpp"
#include "Queue.hpp"
#include "Deque.hpp"
using namespace std;

int Pow(int n);
int Sum(int a, int b);
bool Divis(int n);

template <typename BaseCollection>
void TestEmpty(BaseCollection& collection);

template <typename BaseCollection>
void TestGetLength(BaseCollection& collection);

template <typename T>
void TestFrontQ(Queue<T>& collection);

template <typename T>
void TestFrontD(Deque<T>& collection);

template <typename T>
void TestPopQ(Queue<T>& collection);

template <typename T>
void TestPopD(Deque<T>& collection);

template <typename T>
void TestMapQ(Queue<T>& collection);

template <typename T>
void TestMapD(Deque<T>& collection);

template <typename BaseCollection>
void TestGetSubCollection(BaseCollection& collection);

template <typename BaseCollection>
void TestWhere(BaseCollection& collection);

template <typename BaseCollection>
void TestConcat(BaseCollection& collection1, BaseCollection& collection2);

template <typename BaseCollection>
void TestSubDetect(BaseCollection& collection, BaseCollection& collection2);

template <typename T>
void TestDivide(Queue<T>& queue);

void Testing();

#endif //LAB3_2SEM_TEST_HPP
