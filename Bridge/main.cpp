#include <iostream>
#include <string>


// �����ʵ�ַ���

// ��������� ��ôԽ��Խ�񹤳���
class ITheme {
public:
    virtual std::string GetColor() = 0;
};

class DarkTheme : public ITheme {
public:
    std::string GetColor() override { return "Dark Black"; }
};

class LightTheme : public ITheme {
public:
    std::string GetColor() override { return "Off white"; }
};

class AquaTheme : public ITheme {
public:
    std::string GetColor() override { return "Light blue"; }
};




// ǰ���õ��ļ̳к��񹤳�  �̳н����ǹ�����һ�������Զ���
// ����Ҳ���û���ĳ��� ʹ�ó�������Ϊ��Ա����
// ʹ�ø���߱������仯�Ŀռ�
class IWebPage {
public:
    // �����û�����Ҫ����һ����������
    // ��Ҫһ������Ķ�����ܶԸó�����ʵ����
    IWebPage(ITheme& theme) : theme_(theme) {}
    virtual std::string GetContent() = 0;
protected:
    ITheme& theme_;
};

// ʵ���� ����ҳ��
// ����һ����������      �������ֻ�����û������ı�ʵ����
class About : public IWebPage {
public:
    About(ITheme& theme) : IWebPage(theme) {}
    std::string GetContent() override {
        return "About page in " + theme_.GetColor();
    }
};


// �ӳ��� ����Ĺ���
// �ӳٹ��� ���ó��������Ķ���
// ����һ�����ӳ�  ֱ������ϣ�����ݽ�ȥʵ��������ȥΪֹ
// ����������ӳ� һֱ���û������  ���û��������׶�����ʲô����
class Careers : public IWebPage {
public:
    Careers(ITheme& theme) : IWebPage(theme) {}
    std::string GetContent() override {
        return "Careers page in " + theme_.GetColor();
    }
};

int main()
{

    // �����ö��ʵ�����������
    DarkTheme darkTheme;
    About about(darkTheme);
    std::cout << about.GetContent() << std::endl;


    // ����һ����ɫ����
    LightTheme lightTheme;
    Careers careers(lightTheme);
    std::cout << careers.GetContent() << std::endl;
}
