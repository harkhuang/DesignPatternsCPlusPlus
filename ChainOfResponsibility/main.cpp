#include <iostream>
#include <exception>
#include <string>

class Account {
public:
    // ��ʼ��
    Account(float balance) : balance_(balance) {}
    virtual std::string GetClassName() { return "Account"; }



    // ���ú����ָ���ָ��  
    // �ṹ�����һ��ָ��ڵ�
    
    void SetNext(Account* const account) { successor_ = account; }
    bool CanPay(float amount) { return balance_ >= amount; }



    // �Լ������Լ�  �����ʹ�õݹ����   ������������
    // �ṩ�ݹ鷽ʽ��ָ������������
    void Pay(float amountToPay) {

        // �ɹ�֧��
        if (CanPay(amountToPay)) {
            std::cout << "Paid " << amountToPay << " using " << GetClassName() << std::endl;
        } else if (successor_) { //û�гɹ�֧��
            std::cout << "Cannot pay using " << GetClassName() << ". Proceeding..." << std::endl;
           // �����Լ�
            successor_->Pay(amountToPay);

        } else {
            throw "None of the accounts have enough balance.";
        }
    }
protected:

    // successor_ �����  �������ɲ��� �����������
    Account* successor_ = nullptr;

    // ���
    float balance_;
};

class Bank : public Account {
public:  
    Bank(float balance) : Account(balance) {}
    std::string GetClassName() override { return "Bank"; }
};

class Paypal : public Account {
public:
    Paypal(float balance) : Account(balance) {}
    std::string GetClassName() override { return "Paypal"; }
};

class Bitcoin : public Account {
public:
    Bitcoin(float balance) : Account(balance) {}
    std::string GetClassName() override { return "Bitcoin"; }
};


// ��Ӻ��ָ��ڵ�
class ZhiFuBao : public Account {
public:
	ZhiFuBao(float balance) : Account(balance) {}
	std::string GetClassName() override { return "ZhiFuBao"; }
};



// ����ʺ� ��ȫ��ⲻ�����е��㷨������������������
int main()
{
    //! Let's prepare a chain like below:
    //! bank -> paypal -> bitcoin
    //! First priority bank
    //!   If bank can't pay then paypal
    //!   If paypal can't pay then bit coin
    
    Bank bank(100); //> Bank with balance 100
    Paypal paypal(200); //> Paypal with balance 200
    bank.SetNext(&paypal);

    Bitcoin bitcoin(300); //> Bitcoin with balance 300

    paypal.SetNext(&bitcoin);

    ZhiFuBao zhifubao(400);

    bitcoin.SetNext(&zhifubao);

    // ��֧��������ѡ��
    // ѡ����Ҫ�������˻����� �ҵ�����ʵ�
    
    // ���Դ����п�ʼ֧��99Ԫ
    std::cout << "try to pay use bank first.and then...\n";
    bank.Pay(99);
    bank.Pay(199);
    bank.Pay(299);
    bank.Pay(399);


	std::cout << "try to pay use papal first.and then...\n";
    paypal.Pay(299);



}
