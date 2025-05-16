#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

// فئة المنتجات
class manager {
    int pcode;
    char pname[20];
    float price;
    int pquantity;
public:
    void input();
    void output();
    void readfile();
    void writefile();
    void modifile();
    void deletefile();
    void searchfile();
};

void manager::input() {
    cout << "\nEnter Product Code: ";
    cin >> pcode;
    cin.ignore();
    cout << "Enter Product Name: ";
    cin.getline(pname, 20);
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Quantity: ";
    cin >> pquantity;
    cout << "\n--------------------------------\n";
}

void manager::output() {
    cout << "\nProduct Code: " << pcode
        << "\nProduct Name: " << pname
        << "\nPrice: " << price
        << "\nQuantity: " << pquantity
        << "\n--------------------------------\n";
}

void manager::readfile() {
    ifstream ifile("manager.dat", ios::binary);
    if (!ifile) {
        cout << "!!File Does Not Exist!!\n";
        return;
    }
    manager c;
    cout << "!!Total Number Of Products Entered!!\n";
    while (ifile.read(reinterpret_cast<char*>(&c), sizeof(manager))) {
        c.output();
    }
    ifile.close();
}

void manager::writefile() {
    int n;
    cout << "Enter total number of products (MAX 10): ";
    cin >> n;
    if (n > 10 || n < 1) {
        cout << "Invalid number!\n";
        return;
    }
    ofstream ofile("manager.dat", ios::binary | ios::app);
    if (!ofile) {
        cout << "Error: Cannot open file!\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        manager c;
        c.input();
        ofile.write(reinterpret_cast<char*>(&c), sizeof(manager));
    }
    ofile.close();
}

void manager::modifile() {
    manager c1, c2;
    int f = 0;
    ifstream ifile("manager.dat", ios::binary);
    ofstream ofile("temp.dat", ios::binary);
    if (!ifile) {
        cout << "!!File Does Not Exist!!\n";
        return;
    }
    cout << "Enter Product Details to Modify:\n";
    c1.input();
    while (ifile.read(reinterpret_cast<char*>(&c2), sizeof(c2))) {
        if (c1.pcode == c2.pcode) {
            f = 1;
            ofile.write(reinterpret_cast<char*>(&c1), sizeof(c1));
        }
        else {
            ofile.write(reinterpret_cast<char*>(&c2), sizeof(c2));
        }
    }
    ifile.close();
    ofile.close();
    if (f == 1) {
        remove("manager.dat");
        rename("temp.dat", "manager.dat");
        cout << "Record Modified!\n";
    }
    else {
        cout << "!!Information Does Not Exist!!\n";
        remove("temp.dat");
    }
}

void manager::deletefile() {
    manager c;
    int f = 0, PC;
    ifstream ifile("manager.dat", ios::binary);
    ofstream ofile("temp.dat", ios::binary);
    if (!ifile) {
        cout << "!!File Does Not Exist!!\n";
        return;
    }
    cout << "Enter Product Code to Delete: ";
    cin >> PC;
    while (ifile.read(reinterpret_cast<char*>(&c), sizeof(manager))) {
        if (c.pcode == PC) {
            f = 1;
            c.output();
        }
        else {
            ofile.write(reinterpret_cast<char*>(&c), sizeof(manager));
        }
    }
    ifile.close();
    ofile.close();
    if (f == 1) {
        remove("manager.dat");
        rename("temp.dat", "manager.dat");
        cout << "\n!!Record Deleted!!\n";
    }
    else {
        cout << "!!Information Does Not Exist!!\n";
        remove("temp.dat");
    }
}

void manager::searchfile() {
    int PC, f = 0;
    manager c;
    ifstream ifile("manager.dat", ios::binary);
    if (!ifile) {
        cout << "!!File Does Not Exist!!\n";
        return;
    }
    cout << "Enter Product Code to Search: ";
    cin >> PC;
    while (ifile.read(reinterpret_cast<char*>(&c), sizeof(manager)) && f == 0) {
        if (PC == c.pcode) {
            c.output();
            f = 1;
        }
    }
    ifile.close();
    if (f == 0) {
        cout << "!!Information Does Not Exist!!\n";
    }
}

// فئة الموظفين
class employee {
    int c_code;
    char c_name[20];
    char phnumber[20];
    char address[100];
    char doj[10];
public:
    void input();
    void output();
    void readfile();
    void writefile();
    void modifile();
    void deletefile();
    void searchfile();
};

void employee::input() {
    cout << "\nEnter Employee Code: ";
    cin >> c_code;
    cin.ignore();
    cout << "Enter Employee Name: ";
    cin.getline(c_name, 20);
    cout << "Enter Phone Number: ";
    cin.getline(phnumber, 20);
    cout << "Enter Address: ";
    cin.getline(address, 100);
    cout << "Enter Date of Joining (DD/MM/YY): ";
    cin.getline(doj, 10);
    cout << "\n--------------------------------\n";
}

void employee::output() {
    cout << "\nEmployee Code: " << c_code
        << "\nEmployee Name: " << c_name
        << "\nPhone Number: " << phnumber
        << "\nAddress: " << address
        << "\nDate of Joining: " << doj
        << "\n--------------------------------\n";
}

void employee::readfile() {
    ifstream ifile("employee.dat", ios::binary);
    if (!ifile) {
        cout << "!!File Does Not Exist!!\n";
        return;
    }
    employee c;
    cout << "!!Total Number Of Employees Entered!!\n";
    while (ifile.read(reinterpret_cast<char*>(&c), sizeof(employee))) {
        c.output();
    }
    ifile.close();
}

void employee::writefile() {
    int n;
    cout << "Enter total number of employees (MAX 10): ";
    cin >> n;
    if (n > 10 || n < 1) {
        cout << "Invalid number!\n";
        return;
    }
    ofstream ofile("employee.dat", ios::binary | ios::app);
    if (!ofile) {
        cout << "Error: Cannot open file!\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        employee c;
        c.input();
        ofile.write(reinterpret_cast<char*>(&c), sizeof(employee));
    }
    ofile.close();
}

void employee::modifile() {
    employee c1, c2;
    int f = 0;
    ifstream ifile("employee.dat", ios::binary);
    ofstream ofile("temp.dat", ios::binary);
    if (!ifile) {
        cout << "!!File Does Not Exist!!\n";
        return;
    }
    cout << "Enter Employee Details to Modify:\n";
    c1.input();
    while (ifile.read(reinterpret_cast<char*>(&c2), sizeof(c2))) {
        if (c1.c_code == c2.c_code) {
            f = 1;
            ofile.write(reinterpret_cast<char*>(&c1), sizeof(c1));
        }
        else {
            ofile.write(reinterpret_cast<char*>(&c2), sizeof(c2));
        }
    }
    ifile.close();
    ofile.close();
    if (f == 1) {
        remove("employee.dat");
        rename("temp.dat", "employee.dat");
        cout << "Record Modified!\n";
    }
    else {
        cout << "!!Information Does Not Exist!!\n";
        remove("temp.dat");
    }
}

void employee::deletefile() {
    employee c;
    int f = 0, CC;
    ifstream ifile("employee.dat", ios::binary);
    ofstream ofile("temp.dat", ios::binary);
    if (!ifile) {
        cout << "!!File Does Not Exist!!\n";
        return;
    }
    cout << "Enter Employee Code to Delete: ";
    cin >> CC;
    while (ifile.read(reinterpret_cast<char*>(&c), sizeof(employee))) {
        if (c.c_code == CC) {
            f = 1;
            c.output();
        }
        else {
            ofile.write(reinterpret_cast<char*>(&c), sizeof(employee));
        }
    }
    ifile.close();
    ofile.close();
    if (f == 1) {
        remove("employee.dat");
        rename("temp.dat", "employee.dat");
        cout << "\n!!Record Deleted!!\n";
    }
    else {
        cout << "!!Information Does Not Exist!!\n";
        remove("temp.dat");
    }
}

void employee::searchfile() {
    int CC, f = 0;
    employee c;
    ifstream ifile("employee.dat", ios::binary);
    if (!ifile) {
        cout << "!!File Does Not Exist!!\n";
        return;
    }
    cout << "Enter Employee Code to Search: ";
    cin >> CC;
    while (ifile.read(reinterpret_cast<char*>(&c), sizeof(employee)) && f == 0) {
        if (CC == c.c_code) {
            c.output();
            f = 1;
        }
    }
    ifile.close();
    if (f == 0) {
        cout << "!!Information Does Not Exist!!\n";
    }
}

// فئة المبيعات
class sell {
    int s_code;
    char s_name[20];
    char phnumber[20];
    char address[100];
    int pcode;
    int quantitypurchased;
public:
    void input();
    void output();
    void writefile();
    void readfile();
};

void sell::input() {
    cout << "\nEnter Customer Code: ";
    cin >> s_code;
    cin.ignore();
    cout << "Enter Customer Name: ";
    cin.getline(s_name, 20);
    cout << "Enter Phone Number: ";
    cin.getline(phnumber, 20);
    cout << "Enter Address: ";
    cin.getline(address, 100);
    cout << "Enter Product Code: ";
    cin >> pcode;
    cout << "Enter Quantity Purchased: ";
    cin >> quantitypurchased;
    cout << "\n--------------------------------\n";
}

void sell::output() {
    cout << "\nCustomer Code: " << s_code
        << "\nCustomer Name: " << s_name
        << "\nPhone Number: " << phnumber
        << "\nAddress: " << address
        << "\nProduct Code: " << pcode
        << "\nQuantity Purchased: " << quantitypurchased
        << "\n--------------------------------\n";
}

void sell::writefile() {
    int n;
    cout << "Enter total number of sales (MAX 10): ";
    cin >> n;
    if (n > 10 || n < 1) {
        cout << "Invalid number!\n";
        return;
    }
    ofstream ofile("sell.dat", ios::binary | ios::app);
    if (!ofile) {
        cout << "Error: Cannot open file!\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        sell s;
        s.input();
        ofile.write(reinterpret_cast<char*>(&s), sizeof(sell));
    }
    ofile.close();
}

void sell::readfile() {
    ifstream ifile("sell.dat", ios::binary);
    if (!ifile) {
        cout << "!!File Does Not Exist!!\n";
        return;
    }
    sell s;
    cout << "!!Sales Records!!\n";
    while (ifile.read(reinterpret_cast<char*>(&s), sizeof(sell))) {
        s.output();
    }
    ifile.close();
}

// الدالة الرئيسية
int main() {
    manager c1;
    employee C1;
    sell S1;
    int choice, ch1, ch2;
    char ch3;

    // شاشة البداية
    system("cls");
    cout << "\n\n\n\n\n\t\t\t\t  DEVELOPED BY \n\t\t\t Rahul Veer Singh";
    cout << "\n\n\n\n\n\t\t\t***********************************";
    cout << "\n\t\t\t\t  WELCOME TO THE ";
    cout << "\n\t\t\t        ELECTRONICS MEGASTORE";
    cout << "\n\t\t\t***********************************";
    cout << "\n\n\n\n\n\n\n\n\nPRESS ENTER TO CONTINUE ";
    cin.get();

    // تسجيل الدخول الرئيسي
    bool loggedIn = false;
    do {
        system("cls");
        char username[20], password[20];
        cout << "\n\n\n\n\n\t\t LOGIN ";
        cout << "\n\t\t\t USERNAME: ";
        cin >> username;
        cout << "\t\t\t PASSWORD: ";
        cin.ignore();
        cin.getline(password, 20);

        if (strcmp(username, "admin") == 0 && strcmp(password, "admin1") == 0) {
            loggedIn = true;
        }
        else {
            cout << "\nINVALID USERNAME OR PASSWORD!!\n";
            cout << "DO YOU WANT TO EXIT (y/n)? ";
            cin >> ch3;
            if (ch3 == 'y' || ch3 == 'Y') {
                exit(0);
            }
        }
    } while (!loggedIn);

    // القائمة الرئيسية
    do {
        system("cls");
        cout << "\n\n\n\n\n\t\t     ####################################";
        cout << "\n\t\t     %\t\t\t\t\t%\n\t\t     %\t\t\t\t\t%\n\t\t     %\t\t   1.MANAGER\t\t%";
        cout << "\n\t\t     %\t\t\t\t\t%\n\t\t     %\t\t\t\t\t%\n\t\t     %\t\t\t\t\t%";
        cout << "\n\t\t     %\t\t\t\t\t%\n\t\t     %\t\t  2.INVOICE\t\t%";
        cout << "\n\t\t     %\t\t\t\t\t%\n\t\t     %\t\t\t\t\t%\n\t\t     %\t\t\t\t\t%";
        cout << "\n\t\t     %\t\t\t\t\t%\n\t\t     %\t\t  3.EXIT\t\t%";
        cout << "\n\t\t     %\t\t\t\t\t%\n\t\t     %\t\t\t\t\t%";
        cout << "\n\t\t     ####################################";
        cout << "\n\t\t ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // تسجيل دخول المدير
            bool managerLoggedIn = false;
            do {
                system("cls");
                char username1[20], password1[20];
                cout << "\n\n\n\n\n\t\t MANAGER LOGIN ";
                cout << "\n\t\t\t USERNAME: ";
                cin >> username1;
                cout << "\t\t\t PASSWORD: ";
                cin.ignore();
                cin.getline(password1, 20);

                if (strcmp(username1, "manager") == 0 && strcmp(password1, "madmin1") == 0) {
                    managerLoggedIn = true;
                }
                else {
                    cout << "\nINVALID USERNAME OR PASSWORD!!\n";
                    cout << "DO YOU WANT TO EXIT (y/n)? ";
                    cin >> ch3;
                    if (ch3 == 'y' || ch3 == 'Y') {
                        exit(0);
                    }
                }
            } while (!managerLoggedIn);

            // قائمة المدير
            do {
                system("cls");
                cout << "\n\n\n\n\t\t================================";
                cout << "\n\n\t\t1. ADD PRODUCTS";
                cout << "\n\t\t2. DETAILS OF PRODUCTS";
                cout << "\n\t\t3. EDIT PRODUCTS";
                cout << "\n\t\t4. DELETE PRODUCTS";
                cout << "\n\t\t5. SEARCH PRODUCTS";
                cout << "\n\t\t6. EMPLOYEE DETAILS";
                cout << "\n\t\t7. BACK";
                cout << "\n\n\t\t=====================================";
                cout << "\n\t\tENTER YOUR CHOICE: ";
                cin >> ch1;
                system("cls");

                switch (ch1) {
                case 1:
                    c1.writefile();
                    break;
                case 2:
                    c1.readfile();
                    break;
                case 3:
                    c1.modifile();
                    break;
                case 4:
                    c1.deletefile();
                    break;
                case 5:
                    c1.searchfile();
                    break;
                case 6: {
                    // قائمة الموظفين
                    do {
                        system("cls");
                        cout << "\n\n\n\t\t===============EMPLOYEE===============";
                        cout << "\n\n\t\t1. ADD EMPLOYEE";
                        cout << "\n\t\t2. DETAILS OF EMPLOYEE";
                        cout << "\n\t\t3. EDIT EMPLOYEE";
                        cout << "\n\t\t4. DELETE EMPLOYEE";
                        cout << "\n\t\t5. SEARCH EMPLOYEE";
                        cout << "\n\t\t6. BACK";
                        cout << "\n\n\t\t======================================";
                        cout << "\n\t\tENTER YOUR CHOICE: ";
                        cin >> ch2;
                        system("cls");

                        switch (ch2) {
                        case 1:
                            C1.writefile();
                            break;
                        case 2:
                            C1.readfile();
                            break;
                        case 3:
                            C1.modifile();
                            break;
                        case 4:
                            C1.deletefile();
                            break;
                        case 5:
                            C1.searchfile();
                            break;
                        case 6:
                            break;
                        default:
                            cout << "Invalid choice!\n";
                        }
                        cout << "Press Enter to continue...";
                        cin.ignore();
                        cin.get();
                    } while (ch2 != 6);
                    break;
                }
                case 7:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
                if (ch1 != 7) {
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.get();
                }
            } while (ch1 != 7);
            break;
        }
        case 2: {
            // قائمة المبيعات
            do {
                system("cls");
                cout << "\n\n\n\t\t=================SELL================";
                cout << "\n\n\t\t1. ADD SALE";
                cout << "\n\t\t2. READ SALES";
                cout << "\n\t\t3. BACK";
                cout << "\n\n\t\t======================================";
                cout << "\n\t\tENTER YOUR CHOICE: ";
                cin >> ch2;
                system("cls");

                switch (ch2) {
                case 1:
                    S1.writefile();
                    break;
                case 2:
                    S1.readfile();
                    break;
                case 3:
                    break;
                default:
                    cout << "Invalid choice!\n";
                }
                if (ch2 != 3) {
                    cout << "Press Enter to continue...";
                    cin.ignore();
                    cin.get();
                }
            } while (ch2 != 3);
            break;
        }
        case 3:
            system("cls");
            cout << "\n\n\n\n\n\n\n\t\t\t\tEND OF PROGRAM";
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t BY Rahul Veer Singh";
            break;
        default:
            cout << "Invalid choice!\n";
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        }
    } while (choice != 3);

    return 0;
}







