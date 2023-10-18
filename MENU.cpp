#include <iostream>
#include "MENU.hpp"

template<typename T>
void Print(BasicClass<T> *Object) {
    Sequence<T> *seq = Object->GetSequence();
    cout << " ";
    for (int i = 0; i != Object->GetLength(); i++) {
        cout << seq->Get(i) << " ";
    }
    cout << endl;
}


template<typename T>
void MENU(BasicClass<T> *c, string ObjectName) {
    int key, key2;
    T value;
    Deque<T> *deque;
    Queue<T> *queue;
    BasicClass<T> *SubObject;
    BasicClass<T> *SecondObject;
    Deque<T> *DequePtrObject;
    if (ObjectName == "Queue")
    { queue = (Queue<T> *) c; }
    else if (ObjectName == "Deque")
    { deque = (Deque<T> *) c; }

    while (true) {
        cout << endl <<  "...................General..Menu..................." << endl;
        cout << "1.  Find subcollection." << endl;
        cout << "2.  Push." << endl;
        cout << "3.  Pop." << endl;
        cout << "4.  Front." << endl;
        cout << "5.  Map." << endl;
        cout << "6.  Where." << endl;
        cout << "7.  Reduce." << endl;
        cout << "8.  Get subcollection." << endl;
        cout << "9.  Concatation." << endl;
        cout << "10. Print." << endl;
        if (ObjectName == "Queue") {
            cout << "11. Divide by value." << endl;
        }
        else if (ObjectName == "Deque") {
            cout << "11. Back." << endl;
            cout << "12. PopBack." << endl;
            cout << "13. PushBack." << endl;
        }
        cout << "14. Exit" << endl;
        cout << ".................................................." << endl << "- ";
        cin >> key;

        switch (key) {
            case 1:
                cout << "Input a subcollection to check if it is in the collection" << endl;
                cout << "Input values to push to subcollection (input -1 to stop): " << endl;
                SubObject = new Queue<T>();
                while (true) {
                    cin >> value;
                    if (value == -1)
                    { break; }
                    SubObject->Push(value);
                }
                if (c->SubDetect(SubObject))
                { cout << "Sub collection is in the collection!" << endl; }
                else
                { cout << "Sub collection is not in the collection!" << endl; }
                delete SubObject;
                break;
            case 2:
                cout << "Input value : ";
                cin >> value;
                c->Push(value);
                cout << "Result: ";
                Print(c);
                break;
            case 3:
                try {
                    value = c->Pop();
                    cout << "Popped value: " << value << "" << endl;
                    cout << "Result: ";
                    Print(c);
                }
                catch (...)
                {  cout << "Try again." << endl; }
                break;
            case 4:
                try {
                    value = c->Front();
                    cout << "Result: " << value << "" << endl;
                }
                catch (...)
                { cout << "Try again." << endl; }
                break;
            case 5:
                c->Map([](T x) { return (x + 6)*10; });
                cout << "Result : ";
                Print(c);
                break;
            case 6:
                c->Where([](T x) { return x % 2 == 0; });
                cout << "Result : ";
                Print(c);
                break;
            case 7:
                try {
                    value = c->Reduce([](T x, T y) { return x * y; });
                    cout << "Result: " << value << "" << endl;
                }
                catch (...)
                { cout << "Try again." << endl; }
                break;
            case 8:
                int first, last;
                cout << "Input first index: ";
                cin >> first;
                cout << "Input last index: ";
                cin >> last;
                try {
                    SubObject = c->GetSubCollection(first, last);
                    cout << "Subcollection: ";
                    Print(SubObject);
                    delete SubObject;
                }
                catch (...)
                { cout << "Try again." << endl; }
                break;
            case 9:
                cout << "For :" << endl;
                cout << "1.  Queue" << endl;
                cout << "2.  Deque" << endl;
                cout << "......................" << endl;
                cin >> key2;
                switch (key2) {
                    case 1:
                        SecondObject = new Queue<T>();
                        break;
                    case 2:
                        DequePtrObject = new Deque<T>();
                        break;
                    default:
                        cout << "Incorrect key." << endl;
                        break;
                }
                cout << "Input values to push to second collection (enter -1 to stop): " << endl;
                while (true) {
                    cin >> value;
                    if (value == -1)
                    { break; }
                    if (key2 == 2) {
                        DequePtrObject->PushBack(value);
                        continue;
                    }
                    SecondObject->Push(value);
                }
                if (key2 == 2)
                { SecondObject = DequePtrObject; }
                SubObject = c->Concat(SecondObject);
                cout << "Collection after concat: ";
                Print(SubObject);
                delete SecondObject;
                delete SubObject;
                break;
            case 10:
                cout << "Now: ";
                Print(c);
                break;
            case 11:
                try {
                    if (ObjectName == "Queue") {
                        T thing;
                        cout << "Input value to divide by: ";
                        cin >> thing;
                        tuple<BasicClass<T>*, BasicClass<T>*> divideResult = queue->Divide(thing);
                        cout << "First subcollection: ";
                        Print(get<0>(divideResult));
                        cout << "Second subcollection: ";
                        Print(get<1>(divideResult));
                        delete get<0>(divideResult);
                        delete get<1>(divideResult);
                    }
                    else if (ObjectName == "Deque"){
                        try {
                            value = deque->Back();
                            cout << "It's not for deque : " << value << "" << endl;
                        }
                        catch (...)
                        { cout << "Try again." << endl; }
                    }
                } catch (...)
                { cout << "Try again." << endl; }
                break;
            case 12:
                if (ObjectName == "Deque"){
                    try {
                        value = deque->PopBack();
                        cout << "Value: " << value << "" << endl;
                        cout << "Result: ";
                        Print(c);
                    }
                    catch (...)
                    { cout << "Try again." << endl; }
                }
                break;
            case 13:
                if (ObjectName == "Deque") {
                    cout << "Input value : ";
                    cin >> value;
                    deque->PushBack(value);
                    cout << "Result: ";
                    Print(c);
                }
                break;
            case 14:
                return;
            default:
                cout << "Incorrect key." << endl;
                break;
        }
    }
}


void IntMenu(){
    int key;
    cout << "............................." << endl;
    cout << "1. Queue" << endl;
    cout << "2. Deque" << endl;
    cout << "............................." << endl;
    cin >> key;
    switch (key) {
        case 1: {
            auto *queue = new Queue<int>();
            MENU<int>(queue, "Queue");
            delete queue;
            break;
        }
        case 2: {
            auto *deque = new Deque<int>();
            MENU<int>(deque, "Deque");
            delete deque;
            break;
        }
        default:
            cout << "Incorrect key." << endl;
            break;
    }
}
