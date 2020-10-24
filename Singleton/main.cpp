#include <iostream>
#include <string>
#include <cassert>

class President {
public:
   // 在c11 中static 表示线程安全
    // 不需要成员变量, 仅仅在获取句柄函数中返回这个变量即可
    static President& GetInstance() {
        static President instance;
        return instance;
    }


// 删除了拷贝构造 使得对象更加的安全
    President(const President&) = delete;
    President& operator=(const President&) = delete;

private:
    President() {}
};

int main()
{
    const President& president1 = President::GetInstance();
    const President& president2 = President::GetInstance();

    assert(&president1 == &president2); // same address, point to same object.
}
