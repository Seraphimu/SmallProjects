#include "Contact.hpp"

void testContact() {
    Contact con;

    con.initContact();
    con.addPeople();
    con.addPeople();
    con.addPeople();
    string name = "1114";
    // cout << "Search By Name" << con.searchByName(name) << endl;
    // con.deleteByName(name);
    // con.modifyByName(name);

    con.printContact();
    con.makeEmpty();
}

int main(void) {
    testContact();

    return 0;
}