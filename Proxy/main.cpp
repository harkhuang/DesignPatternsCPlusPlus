#include <iostream>
#include <string>

class IDoor {
public:
    virtual void Open() = 0;
    virtual void Close() = 0;
};

class LabDoor : public IDoor {
public:
    void Open() override { std::cout << "Opening lab door" << std::endl; }
    void Close() override { std::cout << "Closing the lab door" << std::endl; }
};



// 安全系统作为门的代理
class Security {
public:
    Security(IDoor& door): door_(door) {}
    bool Authenticate(const std::string& password) { return password == "$ecr@t"; }
    void Open(const std::string& password) {
        if (Authenticate(password)) door_.Open();
        else std::cout << "Big no! It ain't possible." << std::endl;
    }
    void Close() { door_.Close(); }

private:
    IDoor& door_;
};

int main()
{


    // 实验室有个门
    LabDoor labDoor;


    // 被安全系统封装
    Security securityDoor(labDoor);



    // 通过安全系统 调用开门关门
    securityDoor.Open("invalid");
    securityDoor.Open("$ecr@t");
    securityDoor.Close();
}
