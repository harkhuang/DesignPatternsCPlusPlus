#include <iostream>
#include <string>
#include <unordered_map>

// Anything that will be cached is flyweight.
// Types of tea here will be flyweights.
class KarakTea {};

// ��Ԫģʽ�����ص���Ǳ�����Ƕ����ָ��
// �̲�ʦΨһ�ļ����������̲裬ÿ��һ�������ڼ��ܱ�������һ�ּ���
class TeaMaker {
public:

    //  �����̲� ���Ҽ�¼
    KarakTea* Make(const std::string& preference) {

        // ��ѯ�ü�¼�Ƿ����  ����������� ���ҷ��ظö���
        if (availableTea_.find(preference) == availableTea_.end())
            // ��������������ﹹ��
            // ÿ��������̲趼��һ����Ӧ��karakTea��֮��Ӧ
            availableTea_.insert({preference, new KarakTea()});

        // ���ض�Ӧλ�õĳ�Ա
        return availableTea_.at(preference);
    }

private:

    // ��¼��Ԫģʽ����
    // ��¼�ܹ������̲������?
    // ���ݶ������Ƽ�¼�Ŀ��Է���Ĳ�����
    // �̲���̲�ʦ���ϵ���̲����� �̲�����
    std::unordered_map<std::string, KarakTea*> availableTea_;
};




// û�м̳�ֻ�й���
class TeaShop {
public:

    // ���̲�� ����Ҫ�и��̲�ʦ
    TeaShop(TeaMaker& teaMaker): teaMaker_(teaMaker) {}

    // �㵥����
    void TakeOrder(const std::string& teaType, int table) {

        // �̲�ʦ
        orders_[table] = teaMaker_.Make(teaType);
    }

    // ����
    void Serve() {
        //  �����������  �鿴���˶�����ʲô
        for(auto order : orders_)
            std::cout << "Serving tea to table# " << order.first << std::endl;
    }

private:

    // int ��ʾ��λ����    karak��ʾ�������
    // �̲���̲����ϵ����λ�Ź�ϵ
    std::unordered_map<int, KarakTea*> orders_;
    TeaMaker& teaMaker_;
};

int main()
{
    // �̲�ʦ
    TeaMaker teaMaker;
    //  �̲��
    TeaShop shop(teaMaker);
    // �̲�괴���̲�
    // �̲�������̲�ʦ�ļ��ܺ͹���  
    // ͨ���̲����������̲�
    shop.TakeOrder("less sugar", 1);
	shop.TakeOrder("more milk", 2);
	shop.TakeOrder("less milk",3);
    shop.TakeOrder("without sugar", 5);
    shop.Serve();


}
