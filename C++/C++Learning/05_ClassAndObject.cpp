#include <iostream>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "I am Animal" << endl;
    }
};

// 定義一個類
class Dog : public Animal // 繼承
{
public: // 還有private、protected
    // 屬性
    string name;
    int age;

    void Info()
    {
        cout << "Dog：" << name << endl;
        cout << "Age：" << age << endl;
    }
    // 建構函數(物件生成時執行)
    Dog()
    {
        cout << "生成狗狗 " << endl;
    }
    // 析構函數(物件銷毀時執行)
    ~Dog()
    {
        cout << "狗狗死掉了 " << endl;
    }
};
//================================================================

int main()
{
    // 根據類創造物件
    {
        Dog dog;
        dog.name = "黃金獵犬";
        dog.age = 8;
        dog.Info();
    } // 這個大括號是作用域，執行完裡面內容會刪除物件

    return 0;
}
