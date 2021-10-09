// TaskB.cpp
//

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class MyDeque {
 public:
    int length = 0;
    int* arr = new int[0];
    int capacity = 1;
    // pushHead - метод, добавляющий в голову дека новый элемент.
    void PushFront(int n) {
        
        if (capacity == ++length)
        {
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i < length - 1; i++) {
                newArr[i] = arr[i];
            }
            newArr[length - 1] = n;
            delete[] arr;
            arr = newArr;
        }
        else
        {
            arr[length - 1] = n;
        }

        cout << "ok" << endl;
    }
    // PushBack - метод, добавляющий в хвост дека новый элемент.
    void PushBack(int n) {
        int* newArr = new int[++length];
        for (int i = 1; i < length; i++) {
            newArr[i] = arr[i-1];
        }
        newArr[0] = n;
        arr = new int[length];
        delete[] arr;
        arr = newArr;
        cout << "ok" << endl;
    }
    // Метод PopFront удаляет головной элемент стека и выводит его в консоль.
    void PopFront() {
        // Проверка длины дека.
        if (length == 0) {
            cout << "error" << endl;
        } else {
            int value = arr[length - 1];
            int* newArr = new int[--length];
            for (int i = 0; i < length; i++) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            cout << value << endl;
        }
    }
    // Метод PopBack удаляет нулевой элемент стека и выводит его в консоль.
    void PopBack() {
        // Проверка длины дека.
        if (length == 0) {
            cout << "error" << endl;
        } else {
            int value = arr[0];
            int* newArr = new int[--length];
            for (int i = 0; i < length; i++) {
                newArr[i] = arr[i + 1];
            }
            delete[] arr;
            arr = newArr;
            cout << value << endl;
        }
    }
    // Выводит в консоль головной элемент дека.
    void Front() {
        if (length <= 0) {
            cout << "error" << endl;
        } else {
            cout << (arr[length - 1]) << endl;
        }
    }
    // Выводит в консоль 0 элемент дека.
    void Back() {
        if (length <= 0) {
            cout << "error" << endl;
        } else {
            cout << (arr[0]) << endl;
        }
    }
    // Выводит длину дека в консоль.
    void Size() {
        cout << length << endl;
    }
    // Очищает стек.
    void Clear() {
        length = 0;
        arr = new int[length];
        cout << "ok" << endl;
    }
    // Метод завершает выполнение программы.
    void Exit() {
        cout << "bye" << endl;
        exit;
    }
};

int main() {
    MyDeque myDeque;
    while (true) {
        string command;
        cin >> command;
        if (command == "push_front") {
            int n;
            cin >> n;
            myDeque.PushFront(n);
        } else if (command == "push_back") {
            int n;
            cin >> n;
            myDeque.PushBack(n);
        } else if (command == "pop_front") {
            myDeque.PopFront();
        } else if (command == "pop_back") {
            myDeque.PopBack();
        } else if (command == "front") {
            myDeque.Front();
        } else if (command == "back") {
            myDeque.Back();
        } else if (command == "size") {
            myDeque.Size();
        } else if (command == "clear") {
            myDeque.Clear();
        } else if (command == "exit") {
            cout << "bye" << endl;
            return 0;
        }
    }
    return 0;
}
