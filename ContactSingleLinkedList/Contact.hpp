#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class PeoNode {
private:
    string name;
    string sex;
    int age;
    string tele;
    string addr;

    PeoNode * next;

    //Provide Contact access;
    friend class Contact;
};

class Contact {
public:
    //初始化通讯录信息
    void initContact();
    //判空
    bool isEmpty();
    //添加联系人
    void addPeople();
    //打印通讯录信息
    void printContact();
    //根据联系人的姓名删除联系人
    void deleteByName(string & name);
    //根据姓名查找联系人
    PeoNode * searchByName(string & name);
    //根据姓名修改联系人的信息
    void modifyByName(string & name);
    //分配节点
    PeoNode * buyNode();
    //销毁
    void makeEmpty();
private:
    PeoNode * head;
};