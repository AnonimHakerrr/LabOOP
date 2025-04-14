#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Father {
protected:
    string nameFather;  
public:
    Father(const string& imya) : nameFather(imya) {}
  
    virtual void show() const {
        cout << "��'� ������: " << nameFather << endl;
    }
};
 
class Kids : public Father {
private:
    string nameKids;   
public:
     
    Kids(const string& imyaDytyny, const string& imyaBatyka)
        : Father(imyaBatyka), nameKids(imyaDytyny) {}

    void show() const override {
        cout << "��'� ������: " << nameKids << ", �� �������: " << nameFather << endl;
    }
};

int main() {
    SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
    
    Father f("������");
    f.show();    
    Kids d("����", "����������");
    d.show();  
    return 0;
}
