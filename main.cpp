#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

void CountDown(int count) {
    if (count <= 0) {
        cout << "Go!" << endl;
    }
    else {
        CountDown(count - 1);
        cout << count << endl;
    }
}

void countDown (int n) {
    while (n >= 0) {
        cout << n << endl;
        --n;
    }
}

int FindNumber (int number[], int lowIndex, int highIndex, int target) {
    int midVal, midIndex;
    midIndex = (lowIndex + highIndex) / 2;
    midVal = number[midIndex];
    cout << midVal;

    if (target == midVal) {
        return midIndex;
    }
    else if (lowIndex == highIndex) {
        return -1;

    }
    else {
        if (target < midVal) {
            return FindNumber (number, lowIndex, midIndex - 1, target);
        }
        else {
            return FindNumber (number, midIndex + 1, highIndex, target);
        }
    }
}

void FindNumber (int number, int lowVal, int highVal, int& count) {
    int midVal;
    midVal = (lowVal + highVal) / 2;
    cout << number;
    cout << ", ";
    cout << midVal;

    if (number == midVal) {
        cout << " o" << endl;
    }
    else {
        count++;
        if (number < midVal) {
            cout << " p" << endl;
            FindNumber (number, lowVal, midVal, count);
        }
        else {
            cout << " q" << endl;
            FindNumber (number, midVal + 1, highVal, count);
        }
    }
}

void generate(int numbers[], int size, int index) {
    if (index >= size) {
        return;
    }

    numbers[index] = rand();
    generate(numbers, size, index+1);
}

void print (int numbers[], int size, int index) {
    if (index >= size) {
        return;
    }
    cout << numbers[index] << endl;
    print(numbers,size,index + 1);
}

int main() {
//    CountDown(10);
//    countDown(10);

    int n[10];
    generate(n,10, 0);
    sort(n, n+10);
    print(n,10,0);

    int index = FindNumber(n, 0, 10, 99);
    cout << index << endl;
    return 0;
}
