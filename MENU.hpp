#ifndef LAB3_2SEM_MENU_HPP
#define LAB3_2SEM_MENU_HPP
#include <string>
#include <tuple>
#include "BasicClass.hpp"
#include "Sequence.hpp"
#include "Queue.hpp"
#include "Deque.hpp"
using namespace std;

template<typename T>
void MENU(BasicClass<T> *c, string ObjectName);

void IntMenu();

template<typename T>
void Print(BasicClass<T> *Object);

#endif //LAB3_2SEM_MENU_HPP
