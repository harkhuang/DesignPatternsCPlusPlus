#include <iostream>

class AnimalOperation;

// visitee
class Animal {
public:
    virtual void Accept(AnimalOperation& operation) = 0;
};

class Monkey;
class Lion;
class Dolphin;

// 动物运转商
class AnimalOperation {
public:
    virtual void visitMonkey(Monkey& monkey) = 0;
    virtual void visitLion(Lion& lion) = 0;
    virtual void visitDolphin(Dolphin& dolphin) = 0;
};

class Monkey : public Animal {
public:
    void Shout() { std::cout << "Ooh oo aa aa!" << std::endl; }
    void Accept(AnimalOperation& operation) override { operation.visitMonkey(*this); }
};

class Lion : public Animal {
public:
    void Roar() { std::cout << "Roaaar!" << std::endl; }
    void Accept(AnimalOperation& operation) override { operation.visitLion(*this); }
};

class Dolphin : public Animal {
public:
    void Speak() { std::cout << "Tuut tuttu tuutt!" << std::endl; }
    void Accept(AnimalOperation& operation) override { operation.visitDolphin(*this); }
};





// speak 应该终极类

// 访问者最终想要访问的对象
// 在构建的时候应该先创建这个类
// 根据这个类需要的元素 做相应的抽象  动物都会叫  访问叫的属性 抽象动物
// 同时叫是可以被访问的一张属性 是动物园运营的一种
// 在具体实现就要实现vist某种动物的具体方法



class Speak : public AnimalOperation {
public:
    void visitMonkey(Monkey& monkey) override { monkey.Shout(); }
    void visitLion(Lion& lion) override { lion.Roar(); }
    void visitDolphin(Dolphin& dolphin) override { dolphin.Speak(); }
};

int main()
{

    // 动物园的三种动物
    Monkey monkey;
    Lion lion;
    Dolphin dolphin;

    // 继承动物运营的类的方法
    // 这里想拜访的是动物的说话. 
    Speak speak;
    
    // 去看猴子说话
    monkey.Accept(speak);
    lion.Accept(speak);
    dolphin.Accept(speak);
}
