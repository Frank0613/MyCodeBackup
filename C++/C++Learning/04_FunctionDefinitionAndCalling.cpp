#include <iostream>
using namespace std;

int times(int a, int b); // 函式聲明

int add(int a, int b) // 函式一
{
    return a + b;
}

void Speak() // 函式二
{
    cout << "Hi C++" << endl;
}

int main()
{
    cout << add(10, 4) << endl;
    Speak();
    cout << times(4, 5) << endl;
}

int times(int a, int b) // 函式三
{
    return a * b;
}