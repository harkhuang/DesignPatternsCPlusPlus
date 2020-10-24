#include <iostream>

// ������
class Burger {
public:


    // �����ഴ������
    // �������� �ṹ����  ʹ�ú����Լ��䵱director�����ݣ�
    class BurgerBuilder;

    // Flavors ��ζ����
    void showFlavors() {
        std::cout << size_;
        if (cheese_) std::cout << "-cheese";
        if (peperoni_) std::cout << "-peperoni";
        if (lettuce_) std::cout << "-lettuce";
        if (tomato_) std::cout << "-tomato";
        std::cout << std::endl;
    }
private:
    Burger(int size): size_(size) {}


    // ���ú���Ĭ�ϵ�����
    int size_ = 7;
    bool cheese_ = false;
    bool peperoni_ = false;
    bool lettuce_ = false;
    bool tomato_ = false;
};




// ����������
// �����  ��Ա���а����� ��������
class Burger::BurgerBuilder {
public:
    BurgerBuilder(int size) { burger_ = new Burger(size); }
    BurgerBuilder& AddCheese() { burger_->cheese_ = true; return *this; }
    BurgerBuilder& AddPepperoni() { burger_->peperoni_ = true; return *this; }
    BurgerBuilder& AddLettuce() { burger_->lettuce_ = true; return *this; }
    BurgerBuilder& AddTomato() { burger_->tomato_ = true; return *this; }



    Burger* Build() { return burger_; }
private:
    Burger* burger_;
};



class A{

public:
    class B;
};

// ���ǰ���δ������ɽṹ�����  �����������
// �ṹ�� +  RAII�� + private + ���쿽���� = ��
class A::B{

public:
   // B(){ a_ = new A(); }
    void hi()
    {
        std::cout<< "hi \n";
    }

    //A *a_;
};

int main()
{

    A a;

    // ��ʱ������
    A::B().hi();
    // �ⲻ����java�г��õ���һ�����ģʽ�𣿣�����������������
    // spring ��������Щ�оٵȷ��� ȥ���� ����ȥ����
    // ԭ���������������� ����
    // �������ţ�� д����һ�μ��� ȷʵ�о�������
    // ��Ϊ�������ص� thisָ�� �������Ǻ���ĵ����޶�������
    Burger* burger = Burger::BurgerBuilder(14).AddPepperoni().AddLettuce().AddTomato().Build();
    burger->showFlavors();
}
