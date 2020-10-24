#include <iostream>
#include <string>
#include <memory>

// ���±����ģʽ

class EditorMemento {
public:
    EditorMemento(const std::string& content): content_(content) {}
    const std::string& GetContent() const { return content_; }
private:
    std::string content_;
};

class Editor {

    // ����һ������




    //  typedef std::shared_ptr<EditorMemento>  MementoType;
    using MementoType = std::shared_ptr<EditorMemento>;    // ���ַ�ʽ�ȼ۵ġ�
public:
    void Type(const std::string& words) { content_ += " " + words; }
    const std::string& GetContent() const { return content_; }

    // ��ȫ��¼��ʱ��һ��״̬
    // ���״̬���ԱȽϸ��� ���������н�����һ���Ƚϳ����ַ���



    MementoType Save() { return std::make_shared<EditorMemento>(content_); }


    // �������ǵļ�¼����

    void Restore(MementoType memento) { content_ = memento->GetContent(); }
private:
    std::string content_;
};

int main()
{
    // �и����±�
    Editor editor;
    //! Type some stuff
    editor.Type("This is the first sentence.");
    editor.Type("This is second.");
    //! Save the state to restore to : This is the first sentence. This is second.
    auto saved = editor.Save();
    //! Type some more
    editor.Type("And this is third.");
    std::cout << editor.GetContent() << std::endl;

    // �ص�saved��״̬������redis �־û���һ�λع���
    editor.Restore(saved);
    std::cout << editor.GetContent() << std::endl;




    // ˼����
    //********************************
    //** ���±��п��ܽ�����һ���α��¼  ���м�¼��ǰ״̬  ���������һ�����㷨������
    //** ���±��� �и��α�  �и���¼����  �и��ع�����

    // ���������ʵ�ʵı����лᾭ���õ� ����־û��ͻع� �����������ڷ�װ�����ʱ��û�кܺõĳ���ӿ�  ����ʹ������������Ĵ���һ���ļ򵥡�






}
