#include <iostream>

// ��һ�������װΪһ������ �Ӷ�ʹ������ò�ͬ������Կͻ����в�������
// ��������Ŷӻ��߼�¼������־���Լ�֧�ֿɳ���������


// ����  ���� ����   ��redis��������ʹ�������ʽ   �ȴ��������ٴ��ύ
//                 ���ݿ���ͬ���Է�ʽ   ��д�����ٴ� �ύ  ���Ҫ�ḻ�ӿ� ��ô���Կ��Ǽ���ع�

// �����
class Bulb {
  public:
    // ��
    void TurnOn() { std::cout << "Bulb has been lit" << std::endl; }
    // �ر�
    void TurnOff() { std::cout << "Darkness!" << std::endl; }
};



class ICommand {
  public:
    virtual void Execute() = 0;
    virtual void Undo() = 0;
    virtual void Redo() = 0;
};



class TurnOn : public ICommand {
  public:
    TurnOn(Bulb& bulb): bulb_(bulb) {}
    void Execute() override { bulb_.TurnOn(); }
    void Undo() override { bulb_.TurnOff(); }
    void Redo() override { Execute(); }
  private:
    Bulb& bulb_;
};

class TurnOff : public ICommand {
  public:
    TurnOff(Bulb& bulb): bulb_(bulb) {}
    void Execute() override { bulb_.TurnOff(); }
    void Undo() override { bulb_.TurnOn(); }
    void Redo() override { Execute(); }
  private:

    // �����bulb����д�ɳ��� �����Ĳ���
    Bulb& bulb_;
};


// Զ�̿�����
class RemoteControl {
  public:

    // Զ�̿����� �����Ƶ��� �̳г���������
    void Submit(ICommand& command) { command.Execute(); }
};

int main()
{

    // ����ģʽ
  Bulb bulb;

  // �õ��������� ����
  TurnOn turnOn(bulb);
  TurnOff turnOff(bulb);


  // Զ�̿���һ��
  RemoteControl remote;
  remote.Submit(turnOn);
  remote.Submit(turnOff);
}
