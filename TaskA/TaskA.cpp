// TaskA.cpp
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Класс - самописный стек.
class MyStack {
 public:
    int length = 0;
    int* arr = new int[length];
    int capacity = 1;
    // Метод PushN добавляет в стек новый элемент N.
    void PushN(int n) {
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
    // Метод Pop удаляет верхний элемент стека и выводит его в консоль. !!!!!!!!!!!!!поменять
    void Pop() {
        // Проверка длинны стека.
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
    // Метод Back выводит в консоль error, если стек пуст и значение головы стека в обратном случае.
    void Back() {
        if (length <= 0) {
            cout << "error" << endl;
        } else {
            cout << (arr[length - 1]) << endl;
        }
    }
    // Выводит в консоль длину стека.
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
    MyStack myStack;
    // Цикл, для реализации множественного последовательного ввода.
    while (true) {
        string command;
        cin >> command;
        if (command == "push") {
            int n;
            cin >> n;
            myStack.PushN(n);
        } else if (command == "pop") {
            myStack.Pop();
        } else if (command == "back") {
            myStack.Back();
        } else if (command == "size") {
            myStack.Size();
        } else if (command == "clear") {
            myStack.Clear();
        } else if (command == "exit") {
            cout << "bye" << endl;
            return 0;
        }
    }
    return 0;
}
