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
        cout << "Ім'я батька: " << nameFather << endl;
    }
};
 
class Kids : public Father {
private:
    string nameKids;   
public:
     
    Kids(const string& imyaDytyny, const string& imyaBatyka)
        : Father(imyaBatyka), nameKids(imyaDytyny) {}

    void show() const override {
        cout << "Ім'я дитини: " << nameKids << ", по батькові: " << nameFather << endl;
    }
};

int main() {
    SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
    
    Father f("Степан");
    f.show();    
    Kids d("Олег", "Степанович");
    d.show();  
    return 0;
}
