#include "Contact.hpp"

void Contact::initContact() {
    head = nullptr;
}

bool Contact::isEmpty() {
    return head == nullptr;
}

void Contact::addPeople() {
    PeoNode * newNode = buyNode();
    newNode->next = head;
    head = newNode;
}

PeoNode * Contact::buyNode() {
    //分配节点并判断是否成功
    PeoNode * newNode = new PeoNode();
    if (newNode == nullptr) {
        cout << "New Failed!\n";
        exit(-1);
    }
    
    //输入信息
    cout << "Please enter name:> "; getline(cin, newNode->name);
    cout << "Please enter sex:> "; getline(cin, newNode->sex);
    //cin.ignore()方法忽略掉在读取整数后可能残留在输入缓冲区中的换行符
    cout << "Please enter age:> "; cin >> newNode->age; cin.ignore();
    cout << "Please enter telephone:> "; getline(cin, newNode->tele);
    cout << "Please enter address:> "; getline(cin, newNode->addr);
	
    newNode->next = nullptr;
    
    return newNode;
}

void Contact::printContact() {
    if (isEmpty()) {
        cout << "List Is Empty!\n";
        exit(-1);
    }
    
    //表头
    cout << "name" << "\t"
         << "sex" << "\t"
         << "age" << "\t"
         << "tele" << "\t"
         << "addr" << "\n";
    PeoNode * cur = head;
    while (cur != nullptr) {
        cout << cur->name << "\t"
             << cur->sex << "\t"
             << cur->age << "\t"
             << cur->tele << "\t"
             << cur->addr << "\n";
        cur = cur->next;
    }
}

PeoNode * Contact::searchByName(string & name) {
    if (isEmpty()) {
        cout << "List Is Empty!\n";
        exit(-1);
    }
    
    PeoNode * cur = head;
    while (cur != nullptr) {
        if (cur->name == name) {
            return cur;
        }
        //向后遍历
        cur = cur->next;
    }
    
    //没找到返回nullptr
    return nullptr;
}

void Contact::deleteByName(string & name) {
    PeoNode * ret = searchByName(name);
    if (ret == nullptr) {
        cout << "People is Not Exist!\n";
        exit(-1);
    }

    //调整链表的关系
    PeoNode * cur = head;
    while (cur->next != ret) {
        cur = cur->next;
    }
    cur->next = ret->next;
    
    //释放节点
    delete ret;
    ret = nullptr;
}

void Contact::modifyByName(string & name) {
    PeoNode * ret = searchByName(name);
    if (ret == nullptr) {
        cout << "Search Failed!\n";
        exit(-1);
    }
    
        //输入信息
    cout << "Please enter name:> "; getline(cin, ret->name);
    cout << "Please enter sex:> "; getline(cin, ret->sex);
    //cin.ignore()方法忽略掉在读取整数后可能残留在输入缓冲区中的换行符
    cout << "Please enter age:> "; cin >> ret->age; cin.ignore();
    cout << "Please enter telephone:> "; getline(cin, ret->tele);
    cout << "Please enter address:> "; getline(cin, ret->addr);
}

void Contact::makeEmpty() {
    if (isEmpty()) {
        cout << "List Is Empty!\n";
        exit(-1);
    }
    
	while (!isEmpty()) {
        cout << head->name;
        //头删
        PeoNode * tmp = head;
        head = head->next;
        free(tmp);
        tmp = nullptr;
        
        cout << "has been poped!\n";
    }
    
    cout << "Make Empty Successfully!\n";
}