#include <iostream>
using namespace std;

int main()
{
    int x = 10;
    cout << x << endl;  // x的值
    cout << &x << endl; // "&" 可以顯示值的位址

    int *ads = &x;        // 將指標指向x的位址
    cout << *ads << endl; // ads的值
    cout << ads << endl;  // ads的位址

    delete ads; // 釋放內存

    // 指標數組
    int numbers[] = {1, 2, 3};
    int *ptr = numbers; // 指向數組的指標
}
