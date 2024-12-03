#include <iostream>
#include <cassert>
using namespace std;

class DynamicArray {
private:
    int size = 0;
    int capacity;
    string* array;

public:
    DynamicArray() {
        capacity = 10;
        array = new string[capacity];
    }

    DynamicArray(int _c) {
        capacity = _c;
        array = new string[capacity];
    }

    DynamicArray(int _c, string* init, int init_size) {
        capacity = _c;
        size = init_size;
        array = new string[capacity];
        for (int i = 0; i < init_size; i++) {
            array[i] = init[i];
        }
    }

    bool insert(string newElement, int position) {
        if (position < 0 || position > size) {
            cout << "Posicion invalida" << endl;
            return false;
        }

        if (capacity <= size) {
            capacity *= 2;
        }

        string* newArray = new string[capacity];
        size++;
        int i;
        for (i = 0; i < position; i++) {
            newArray[i] = array[i];
        }

        newArray[i] = newElement;
        i++;
        while (i < size) {
            newArray[i] = array[i - 1];
            i++;
        }
        delete[] array;
        array = newArray;
        return true;
    }

    bool remove(int position) {
        if (position >= size || position < 0) {
            cout << "Posicion inexistente" << endl;
            return false;
        }
        string* newArray = new string[capacity];
        size--;
        for (int i = 0; i < position; i++) {
            newArray[i] = array[i];
        }
        for (int i = position; i < size; i++) {
            newArray[i] = array[i + 1];
        }
        delete[] array;
        array = newArray;
        return true;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << ", ";
        }
        cout << endl;
    }

    void invert() {
        for (int i = 0; i < size / 2; i++) {
            swap(array[i], array[size - i - 1]);
        }
    }
};

int main() {
    DynamicArray a(10);
    a.insert("bli", 0);
    a.insert("blo", 0);
    a.insert("blu", 0);

    cout << "Array original:" << endl;
    a.print();

    a.invert();
    cout << "Array invertida:" << endl;
    a.print();

    return 0;
}
