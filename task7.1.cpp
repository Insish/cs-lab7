#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Array {
private:
    vector<int> elements;

public:
    //метод для заповнення вектору елементів
    void fillArray() {
        int size;
        cout << "Enter the size of the array: ";
        cin >> size;
        cout << "Enter the elements of the array:" << endl;
        for (int i = 0; i < size; i++) {
            int element;
            cin >> element;
            elements.push_back(element);
        }
    }

    //метод для знаходження номера максимального за модулем елемента
    int findMaxAbsIndex() {
        int maxIndex = 0;
        int maxAbsValue = abs(elements[0]);

        for (int i = 1; i < elements.size(); i++) {
            if (abs(elements[i]) > maxAbsValue) {
                maxAbsValue = abs(elements[i]);
                maxIndex = i;
            }
        }

        return maxIndex;
    }

    //метод для обчислення суми модулів елементів після першого додатного елемента
    int sumOfAbsAfterFirstPositive() {
        int sum = 0;
        bool foundPositive = false;

        for (int i = 0; i < elements.size(); i++) {
            if (foundPositive) {
                sum += abs(elements[i]);
            }
            else if (elements[i] > 0) {
                foundPositive = true;
            }
        }

        return sum;
    }

    //метод для перетворення масиву
    void rearrangeArray(int a, int b) {
        auto compare = [=](int x, int y) {
            bool xInRange = x >= a && x <= b;
            bool yInRange = y >= a && y <= b;

            if (xInRange != yInRange) {
                return xInRange > yInRange;
            }
            else {
                return x < y;
            }
            };

        sort(elements.begin(), elements.end(), compare);
    }

    //виведення масиву
    void printArray() const {
        cout << "Array:" << endl;
        for (int element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }
};

int main() {
    Array arr;

    //заповнення вектору елементів
    arr.fillArray();

    //введення інтервалу [a, b]
    int a, b;
    cout << "Enter the interval [a, b]: ";
    cin >> a >> b;

    //знаходження номера максимального за модулем елемента
    cout << "The number of the maximum element by module: " << arr.findMaxAbsIndex() << endl;

    //обчислення суми модулів елементів після першого додатного елемента
    cout << "Sum of absolute values after the first positive element: " << arr.sumOfAbsAfterFirstPositive() << endl;

    //перетворення масиву
    arr.rearrangeArray(a, b);

    //виведення перетвореного масиву
    arr.printArray();
}
