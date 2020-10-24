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

// ������ת��
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





// speak Ӧ���ռ���

// ������������Ҫ���ʵĶ���
// �ڹ�����ʱ��Ӧ���ȴ��������
// �����������Ҫ��Ԫ�� ����Ӧ�ĳ���  ���ﶼ���  ���ʽе����� ������
// ͬʱ���ǿ��Ա����ʵ�һ������ �Ƕ���԰��Ӫ��һ��
// �ھ���ʵ�־�Ҫʵ��vistĳ�ֶ���ľ��巽��



class Speak : public AnimalOperation {
public:
    void visitMonkey(Monkey& monkey) override { monkey.Shout(); }
    void visitLion(Lion& lion) override { lion.Roar(); }
    void visitDolphin(Dolphin& dolphin) override { dolphin.Speak(); }
};

int main()
{

    // ����԰�����ֶ���
    Monkey monkey;
    Lion lion;
    Dolphin dolphin;

    // �̳ж�����Ӫ����ķ���
    // ������ݷõ��Ƕ����˵��. 
    Speak speak;
    
    // ȥ������˵��
    monkey.Accept(speak);
    lion.Accept(speak);
    dolphin.Accept(speak);
}
