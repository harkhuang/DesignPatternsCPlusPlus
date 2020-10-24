#include <iostream>
using namespace std;

//����ӿ�
class Target
{
public:
	Target() {
		cout << "Target()" << endl;
	};
	virtual ~Target() {
		cout << "~Target()" << endl;
	};

	virtual void Request() {
		std::cout << "Target::Request()" << std::endl;
	};
protected:
private:
};

//����������
class Adaptee
{
public:
	Adaptee() {
		cout << "Adaptee()" << endl;
	};
	~Adaptee() {
		cout << "~Adaptee()" << endl;
	};


	// һ���ر�����󷽷�
	void SpecificRequest() {
		std::cout << "Adaptee::SpecificRequest()" << std::endl;
	};
protected:
private:
};

// ������ķ���
// Ŀ�ľ�������Adapter�е���һ����Target��request����һ���ķ���

// Ϊ�����ౣ������ ���Ҳ��ƻ���һְ���ԭ�� ���ǲ����˹����ķ�ʽ  �ڳ�Ա������ʵ����һ���������󷽷�
class Adapter :public Target
{
public:
	Adapter(Adaptee* ade) {
		std::cout << "Adapter(Adaptee* ade)" << std::endl;
		this->_ade = ade;
	};
	~Adapter() {
		std::cout << "~Adapter()" << std::endl;
	};


	// ͨ��������ʽ�ĳ�Ա��������д���ü̳е����Ա
	// ��д�����������ױ�������
	void Request() {
		_ade->SpecificRequest();
	}
	;
protected:
private:
	Adaptee* _ade;
};

int main(int argc, char* argv[])
{
	//�û��������������Լ�����
	Adaptee* ade = new Adaptee;

	// ������ʱ��ʹ�ó�����, ����������һ��������������  ���䷽������һ��
	Target* adt = new Adapter(ade);
	adt->Request();
	return 0;
}