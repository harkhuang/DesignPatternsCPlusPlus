#include <iostream>
#include <string>
#include <algorithm>
#include <memory>

class IWritingState {
public:
    virtual void Write(std::string words) = 0;
};

class UpperCase : public IWritingState {
    void Write(std::string words) override {
        std::transform(words.begin(), words.end(), words.begin(), ::toupper);
        std::cout << words << std::endl;
    }
};

class LowerCase : public IWritingState {
    void Write(std::string words) override {
        std::transform(words.begin(), words.end(), words.begin(), ::tolower);
        std::cout << words << std::endl;
    }
};

class Default : public IWritingState {
    void Write(std::string words) override { std::cout << words << std::endl; }
};

class TextEditor {
public:
    TextEditor(const std::shared_ptr<IWritingState>& state): state_(state) {}
    void SetState(const std::shared_ptr<IWritingState>& state) { state_ = state; }
    void Type(std::string words) { state_->Write(words); }
private:

    /// <summary>
    /// 共享指针用于 主类所使用的状态机
    /// 用智能指针的好处就是 在用户层可以随意的new  不需要去管理指针资源
    /// </summary>
    std::shared_ptr<IWritingState> state_;
};

int main()
{
  TextEditor editor(std::make_shared<Default>());
  editor.Type("First line");

  editor.SetState(std::make_shared<UpperCase>());
  editor.Type("Second line");
  editor.Type("Third line");

  editor.SetState(std::make_shared<LowerCase>());
  editor.Type("Fourth line");
  editor.Type("Fifth line");
}
