//main.cpp
#include "Flyweight.h"
#include "FlyweightFactory.h"

using namespace std;

int main(int argc,char* argv[])
{

    // �����Ԫģʽ д���˹���ģʽ..

    // ֱ��ͨ����������  
    // �����Ԫ������
    FlyweightFactory* fc = new FlyweightFactory();
    Flyweight* fw1 = fc->GetFlyweight("hello");
    Flyweight* fw2 = fc->GetFlyweight("world!");
    Flyweight* fw3 = fc->GetFlyweight("hello");

    return 0;
}
