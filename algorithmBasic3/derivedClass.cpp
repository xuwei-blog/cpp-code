#include <iostream>
#include <cstring>
using namespace std;
/*派生类 和 基类
1.派生类对象的容量等于 基类 + 派生类
2.基类对象的存储位置位于派生类对象新增的成员变量之前
*/
class CStudent
{ //基类
private:
    string name;
    string id;
    char gender;
    int age;

public:
    void PrintInfo();
    void SetInfo(const string &name_, const string &id_,
                 int age_, char gender_);
    string GetName() { return name; }
};
void CStudent::PrintInfo()
{
    cout << "name:" << name << endl;
    cout << "id:" << id << endl;
    cout << "gender:" << gender << endl;
    cout << "age:" << age << endl;
}
void CStudent::SetInfo(const string &name_, const string &id_,
                 int age_, char gender_)
{
    name = name_;
    id = id_;
    age = age_;
    gender = gender_;
}

class CUndergraduateStudent : public CStudent
{ //派生类
private:
    string department;

public:
    void QualifiedForBaoyan()
    {
        cout << "QualifiedForBaoyan " << endl;
    }
    void PrintInfo()
    {
        CStudent::PrintInfo(); //调用基类
        cout << "department: " << department << endl;
    }
    void SetInfo(const string &name_, const string &id_,
                 int age_, char gender_, const string &department_)
    {
        CStudent::SetInfo(name_, id_, age_, gender_); //调用基类
        department = department_;
    }
};

int main()
{
    CUndergraduateStudent s2;
    s2.SetInfo("ben", "11112223", 20, 'M', "CS");
    cout << s2.GetName() << endl;
    s2.QualifiedForBaoyan();
    s2.PrintInfo();

    system("pause");
    return 0;
}
