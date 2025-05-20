#include <iostream>
using namespace std;

void IF();
void FOR();
void WHILE();

int main()
{
    cout << "If判斷式：" << endl;
    IF();
    cout << "============================" << endl;

    cout << "For迴圈：" << endl;
    FOR();
    cout << "============================" << endl;

    cout << "While迴圈：" << endl;
    WHILE();
    cout << "============================" << endl;
}

void IF()
{
    int x = 5;
    if (x > 10)
    {
        cout << "x大於5" << endl;
    }
    else
    {
        cout << "x小於5" << endl;
    }
}
void FOR()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "目前i值" << i << endl;
    }
}
void WHILE()
{
    int i = 0;
    while (i < 5)
    {
        cout << "目前i值" << i << endl;
        i++;
    }
}