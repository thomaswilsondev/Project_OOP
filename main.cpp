#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

class Person
{
private:
    // Attribute

    string name;
    string dateOfBirth;
    string address;
    string phone;
    string email;

public:
    // Contructor
    Person() {}
    Person(string n, string a, string p)
        : name(n), address(a), phone(p) {}

    string getName() const { return name; }
    string getAddress() const { return address; }
    string getPhoneNumber() const { return phone; }

    virtual void display() const
    {
        cout << "Ten: " << name << endl;
        cout << "Dia chi: " << address << endl;
        cout << "So dien thoat: " << phone << endl;
    }

    Person(string name, string dateOfBirth, string address, string phone, string email)
    {
        this->name = name;
        this->dateOfBirth = dateOfBirth;
        this->address = address;
        this->phone = phone;
        this->email = email;
    }
    // Destructor
    ~Person(){};

    // Setter
    void setName(string name)
    {
        this->name = name;
    }

    void setDateOfBrith(string dateOfBirth)
    {
        this->dateOfBirth = dateOfBirth;
    }

    void setAddress(string address)
    {
        this->address = address;
    }

    void setPhone(string phoneNumber)
    {
        this->phone = phoneNumber;
    }

    void setEmail(string email)
    {
        this->email = email;
    }

    // Getter

    string getDateOfBrith()
    {
        return this->dateOfBirth;
    }

    string getEmail()
    {
        return this->email;
    }
};

class Employee : public Person
{
private:
    int employeeID;
    string position;
    float salary;
    string dateOfHire;

public:
    // Contructor

    Employee() {}

    Employee(int employeeID, string position, float salary, string dateOfHire, string name, string dateOfBirth, string address, string phone, string email) : Person(name, dateOfBirth, address, phone, email)
    {
        this->employeeID = employeeID;
        this->position = position;
        this->salary = salary;
        this->dateOfHire = dateOfHire;
    }

    // Destructor
    ~Employee(){};

    // Setter
    void setEmployeeID(int employeeID)
    {
        this->employeeID = employeeID;
    }

    void setPosition(string position)
    {
        this->position = position;
    }

    void setSalary(float salary)
    {
        this->salary = salary;
    }

    void setDateOfHire(string dateOfHire)
    {
        this->dateOfHire = dateOfHire;
    }

    // Getter

    int getEmployeesId()
    {
        return this->employeeID;
    }

    string getPosition()
    {
        return this->position;
    }

    float getSalary()
    {
        return this->salary;
    }

    string getDateOfHire()
    {
        return this->dateOfHire;
    }
};

class Customer : public Person
{
private:
    int customerId;
    string membershipLevel;
    int point;

public:
    // Contructor
    Customer() {}

    Customer(int customerId, string membershipLevel, int point, string name, string dateOfBirth, string address, string phone, string email) : Person(name, dateOfBirth, address, phone, email)
    {
        this->customerId = customerId;
        this->membershipLevel = membershipLevel;
        this->point = point;
    }

    // Destrustor
    ~Customer() {}

    // Setter
    void setCustomerId(int customerId)
    {
        this->customerId = customerId;
    }

    void setMembershipLevel(string membershipLevel)
    {
        this->membershipLevel = membershipLevel;
    }

    void setPoint(int point)
    {
        this->point = point;
    }

    // Getter
    int getCustomerId()
    {
        return this->customerId;
    }

    string getMembershipLevel()
    {
        return this->membershipLevel;
    }

    int getPoint()
    {
        return this->point;
    }
};
class OrderItem
{
private:
    string name;
    double price;
    int quantity;

public:
    OrderItem() {}
    OrderItem(string n, double p, int q)
        : name(n), price(p), quantity(q) {}

    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    void setQuantity(int q) { quantity = q; }
    void setPrice(double p) { price = p; }
    double getTotalPrice() const { return price * quantity; }

    void display() const
    {
        cout << setw(20) << left << name
             << setw(10) << right << price
             << setw(10) << quantity
             << setw(10) << getTotalPrice() << endl;
    }
};
class Order
{
private:
    int id;
    Person customer;
    vector<OrderItem> items;

public:
    Order() {}
    Order(int i, Person c) : id(i), customer(c) {}

    int getId() const { return id; }

    void addItem(OrderItem item) { items.push_back(item); }
    void removeItem(int index) { items.erase(items.begin() + index); }

    double getTotalPrice() const
    {
        double total = 0;
        for (const auto &item : items)
        {
            total += item.getTotalPrice();
        }
        return total;
    }
    void modifyItemQuantity(int index, int newQuantity)
    {
        if (index >= 0 && index < items.size())
        {
            items[index].setQuantity(newQuantity);
        }
    }

    void modifyItemPrice(int index, double newPrice)
    {
        if (index >= 0 && index < items.size())
        {
            items[index].setPrice(newPrice);
        }
    }
    void display() const
    {
        cout << "Id don hang: " << id << endl;
        customer.display();

        cout << "\nOrder items:\n";
        cout << setw(20) << left << "Ten"
             << setw(10) << right << "Gia"
             << setw(10) << "So luong"
             << setw(10) << "Tong cong" << endl;
        for (const auto &item : items)
        {
            item.display();
        }
        cout << setw(40) << right << "Tong cong: " << getTotalPrice() << endl;
    }
    void modifyItem(int index, int newQuantity)
    {
        if (index >= 0 && index < items.size())
        {
            items[index].setQuantity(newQuantity);
        }
    }
};

void displayOrders(const vector<Order> &orders)
{
    if (orders.empty())
    {
        cout << "Khong tim thay don hang ban muon !!!\n";
        return;
    }

    for (int i = 0; i < orders.size(); ++i)
    {
        cout << "Order " << i + 1 << ":\n";
        orders[i].display();
        cout << endl;
    }
}
void addOrder(vector<Order> &orders)
{
    int customer_id;
    double product_price;
    int product_id, quantity;
    string customer_name, customer_address, customer_phoneNumber, product_name;
    char addMore;

    cout << "\n\n\tThem don hang moi";
    cout << "\n\n\tThong tin khach hang";
    cout << "\n\tNhap id khach hang: ";
    cin >> customer_id;
    cout << "\tNhap ten khach hang: ";
    cin.ignore();
    getline(cin, customer_name);
    cout << "\tNhap dia chi khach hang: ";
    getline(cin, customer_address);
    cout << "\tNhap sdt khach hang: ";
    getline(cin, customer_phoneNumber);

    Person customer(customer_name, customer_address, customer_phoneNumber);
    Order order(customer_id, customer);

    do
    {
        cout << "\n\tThong tin san pham";
        cout << "\n\tNhap id san pham: ";
        cin >> product_id;
        cout << "\tNhap ten san pham: ";
        cin.ignore();
        getline(cin, product_name);
        cout << "\tNhap gia san pham: ";
        cin >> product_price;
        cout << "\tNhap so luong: ";
        cin >> quantity;

        OrderItem order_item(product_name, product_price, quantity);
        order.addItem(order_item);

        cout << "\n\tBan muon nhap them san pham khong? (y/n): ";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');

    orders.push_back(order);

    cout << "\n\tDon hang da them vao thang cong" << endl;
}
void modifyOrder(vector<Order> &orders)
{
    int orderId, itemIndex, newQuantity;
    double newPrice;
    bool found = false;
    int option;
    string product_name;
    double product_price;
    int quantity;

    displayOrders(orders);

    cout << "\nNhap id don hang ban muon sua: ";
    cin >> orderId;

    for (auto &order : orders)
    {
        if (order.getId() == orderId)
        {
            found = true;
            cout << "\n\tVui long lua chon option:";
            cout << "\n\t\t1. Them mon hang";
            cout << "\n\t\t2. Xoa mon hang";
            cout << "\n\t\t3. Chinh sua gia tri so luong don hang";
            cout << "\n\t\t4. Chinh sua gia tri gia don hang";
            cout << "\n\n\tOption: ";
            cin >> option;

            switch (option)
            {
            case 1:

                cout << "\n\tThong tin san pham";
                cout << "\n\tNhap ten san pham: ";
                cin.ignore();
                getline(cin, product_name);
                cout << "\tNhap gia san pham: ";
                cin >> product_price;
                cout << "\tNhap so luong: ";
                cin >> quantity;

                order.addItem(OrderItem(product_name, product_price, quantity));
                break;
            case 2:

                cout << "\nNhap chi so mon hang ban muon xoa: ";
                cin >> itemIndex;
                order.removeItem(itemIndex);
                break;
            case 3:

                cout << "\nNhap chi so mon hang ban muon chinh sua: ";
                cin >> itemIndex;
                cout << "Nhap so luong moi ";
                cin >> newQuantity;
                order.modifyItemQuantity(itemIndex, newQuantity);
                break;
            case 4:

                cout << "\nNhap chi so mon hang ban muon chinh sua ";
                cin >> itemIndex;
                cout << "Nhap gia tri moi: ";
                cin >> newPrice;
                order.modifyItemPrice(itemIndex, newPrice);
                break;
            }
            break;
        }
    }

    if (found)
    {
        cout << "\nChinh sua don hang thanh cong!";
    }
    else
    {
        cout << "\nKhong tim thay id!! " << orderId;
    }

    cout << endl;
}
void removeOrder(vector<Order> &orders)
{
    int orderId;
    bool found = false;

    displayOrders(orders);

    cout << "\nNhap id don hang can xoa: ";
    cin >> orderId;

    for (auto it = orders.begin(); it != orders.end(); ++it)
    {
        if (it->getId() == orderId)
        {
            orders.erase(it);
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << "\nXoa don hang thanh cong";
    }
    else
    {
        cout << "\nKhong tim thay don hang co id tren!! " << orderId;
    }

    cout << endl;
}

void manageOrders()
{
    vector<Order> orders;
    int option;
    do
    {

        cout << "\n\tVui long lua chon mot so option:";
        cout << "\n\t\t1. Them don hang moi";
        cout << "\n\t\t2. Xoa don hang moi";
        cout << "\n\t\t3. Hien thi don hang moi";
        cout << "\n\t\t4. Chinh sua don hang";
        cout << "\n\t\t5. Lui lai";
        cout << "\n\n\tOption: ";
        cin >> option;

        switch (option)
        {
        case 1:
            addOrder(orders);
            break;
        case 2:
            displayOrders(orders);
            removeOrder(orders);
            break;
        case 3:
            displayOrders(orders);
            break;
        case 4:

            displayOrders(orders);
            modifyOrder(orders);
            break;
        }
    } while (option != 5);
}
class Product
{
private:
    int productId;
    string productName;
    float price;
    int inventory;

public:
    // Getter

    int getProductId()
    {
        return this->productId;
    };

    string getProductName()
    {
        return this->productName;
    };

    float getPrice()
    {
        return this->price;
    };

    int getInventory()
    {
        return this->inventory;
    }
    // Setter

    void setProductId(int productId)
    {
        this->productId = productId;
    };

    void setProductName(string productName)
    {
        this->productName = productName;
    };

    void setPrice(float price)
    {
        this->price = price;
    };

    void setInventory(int inventory)
    {
        this->inventory = inventory;
    };
    // Contructor

    Product(int productId, string productName, float price, int inventory)
    {
        this->productId = productId;
        this->productName = productName;
        this->price = price;
        this->inventory = inventory;
    }

    ~Product(){};
};

class ProductFile
{
public:
    // Read input from csv file and return product list;

    vector<Product> loadProduct(string filename)
    {
        vector<Product> ProductList;
        int productId;
        string productName;
        float price;
        int inventory;

        fstream input(filename);
        if (!input.is_open())
        {
            cout << "Can not read file!!!" << endl;
        }
        else
        {
            string line, data;
            while (getline(input, line))
            {
                stringstream ss(line);

                getline(ss, data, ',');
                productId = stoi(data);
                getline(ss, productName, ',');
                getline(ss, data, ',');
                price = stof(data);
                getline(ss, data, ',');
                inventory = stoi(data);

                ProductList.push_back(Product(productId, productName, price, inventory));
            }
        }
        input.close();
        return ProductList;
    };

    // write product list into file csv

    void saveProduct(string filename, vector<Product> ProductList)
    {
        ofstream output(filename);
        if (!output.is_open())
        {
            cout << "Can not write file!!!" << endl;
        }
        else
        {
            for (int i = 0; i < ProductList.size(); i++)
            {
                output << ProductList[i].getProductId() << ","
                       << ProductList[i].getProductName() << ","
                       << ProductList[i].getPrice() << ","
                       << ProductList[i].getInventory() << endl;
            }
        }
        output.close();
    }
};

class ControllProduct
{
private:
    vector<Product> ProductList;
    int AutoID()
    {
        return this->ProductList.back().getProductId() + 1;
    }

public:
    // contructor
    ControllProduct(vector<Product> ProductList)
    {
        this->ProductList = ProductList;
    }

    // Display product list
    void Display()
    {
        cout << setw(5) << left << "ID"
             << setw(100) << left << "Ten sanp pham"
             << setw(10) << left << "Gia"
             << setw(10) << left << "Ton kho"
             << endl;

        for (int i = 0; i < this->ProductList.size(); i++)
        {
            cout << setw(5) << left << this->ProductList[i].getProductId()
                 << setw(100) << left << this->ProductList[i].getProductName()
                 << setw(10) << left << this->ProductList[i].getPrice()
                 << setw(10) << left << this->ProductList[i].getInventory()
                 << endl;
        }
    }

    // Add item into product list

    void addProduct()
    {
        int n;
        string productName;
        float price;
        int inventory;

        cout << "So luong san pham muon them: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin.ignore(32767, '\n');
            cout << "San pham " << i + 1 << endl;
            cout << "Nhap ten san pham: ";
            getline(cin, productName);
            cout << "Nhap gia san pham: ";
            cin >> price;
            cout << "Nhap so luong ton kho: ";
            cin >> inventory;

            Product item(this->AutoID(), productName, price, inventory);
            this->ProductList.push_back(item);
        }
    }

    // Remove item form product list
    void removeProduct()
    {
        int idRemovedProduct;
        cout << "Nhap ID san pham can xoa: ";
        cin >> idRemovedProduct;
        for (int i = 0; i < this->ProductList.size(); i++)
        {
            if (this->ProductList[i].getProductId() == idRemovedProduct)
            {
                this->ProductList.erase(this->ProductList.begin() + i);
                return;
            }
        }
    }
};

class Store
{
private:
    vector<Employee> employeesList;
    vector<Customer> customerList;
    vector<Order> orderList;

public:
    // Contructor
    Store() {}

    // Destructor
    ~Store() {}

    // Method

    // Manage Employee
    void loadEmployee(string filename)
    {
        vector<Employee> EmployeeList;
        int employeeID;
        string position;
        float salary;
        string dateOfHire;
        string name;
        string dateOfBirth;
        string address;
        string phone;
        string email;
        string data;

        fstream input(filename);
        if (!input.is_open())
        {
            cout << "Can not read file!!!" << endl;
        }
        else
        {
            string line, data;
            while (getline(input, line))
            {
                stringstream ss(line);

                getline(ss, data, ',');
                employeeID = stoi(data);
                getline(ss, position, ',');
                getline(ss, data, ',');
                salary = stof(data);
                getline(ss, dateOfHire, ',');
                getline(ss, name, ',');
                getline(ss, dateOfBirth, ',');
                getline(ss, address, ',');
                getline(ss, phone, ',');
                getline(ss, email, ',');
                EmployeeList.push_back(Employee(employeeID, position, salary, dateOfHire, name, dateOfBirth, address, phone, email));
            }
        }
        input.close();
        this->employeesList = EmployeeList;
    };

    void DisplayEmployeesList()
    {
        cout << setw(5) << left << "ID"
             << setw(20) << left << "Ten nhan vien"
             << setw(20) << left << "Chuc vu"
             << setw(10) << left << "Luong"
             << setw(15) << left << "Ngay tuyen"
             << setw(15) << left << "Ngay Sinh"
             << setw(20) << left << "Dia chi"
             << setw(15) << left << "So dien thoai"
             << setw(20) << left << "Email"
             << endl;

        for (int i = 0; i < this->employeesList.size(); i++)
        {
            cout << setw(5) << left << this->employeesList[i].getEmployeesId()
                 << setw(20) << left << this->employeesList[i].getName()
                 << setw(20) << left << this->employeesList[i].getPosition()
                 << setw(10) << left << this->employeesList[i].getSalary()
                 << setw(15) << left << this->employeesList[i].getDateOfHire()
                 << setw(15) << left << this->employeesList[i].getDateOfBrith()
                 << setw(20) << left << this->employeesList[i].getAddress()
                 << setw(15) << left << this->employeesList[i].getPhoneNumber()
                 << setw(20) << left << this->employeesList[i].getEmail()
                 << endl;
        }
    }

    void addEmployee()
    {
        int n;
        int employeeID;
        string position;
        float salary;
        string dateOfHire;
        string name;
        string dateOfBirth;
        string address;
        string phone;
        string email;

        cout << "So luong nhan vien muon them: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin.ignore(32767, '\n');
            employeeID = this->employeesList.back().getEmployeesId() + 1;

            cout << "Nhan vien " << i + 1 << endl;
            cout << "Nhap ten nhan vien: ";
            getline(cin, name);
            cout << "Chuc vu: ";
            getline(cin, position);
            cout << "Luong: ";
            cin >> salary;
            cin.ignore(32767, '\n');

            cout << "Ngay tuyen: ";
            getline(cin, dateOfHire);
            cout << "Ngay sinh: ";
            getline(cin, dateOfBirth);
            cout << "Dia chi: ";
            getline(cin, address);
            cout << "So dien thoai: ";
            getline(cin, phone);
            cout << "Email: ";
            getline(cin, email);

            this->employeesList.push_back(Employee(employeeID, position, salary, dateOfHire, name, dateOfBirth, address, phone, email));
        }
    }

    void removeEmployee()
    {
        int id;
        cout << "Nhap ma nhan vien ban muon xoa: ";
        cin >> id;
        for (int i = 0; i < this->employeesList.size(); i++)
        {
            if (this->employeesList[i].getEmployeesId() == id)
            {
                this->employeesList.erase(this->employeesList.begin() + i);
                return;
            }
        }
    }

    void loadCustomer(string filename)
    {
        vector<Customer> CustomerList;
        int customerId;
        string membershipLevel;
        int point;
        string name;
        string dateOfBirth;
        string address;
        string phone;
        string email;
        string data;

        fstream input(filename);
        if (!input.is_open())
        {
            cout << "Can not read file!!!" << endl;
        }
        else
        {
            string line, data;
            while (getline(input, line))
            {
                stringstream ss(line);

                getline(ss, data, ',');
                customerId = stoi(data);
                getline(ss, membershipLevel, ',');
                getline(ss, data, ',');
                point = stoi(data);
                getline(ss, name, ',');
                getline(ss, dateOfBirth, ',');
                getline(ss, address, ',');
                getline(ss, phone, ',');
                getline(ss, email, ',');
                CustomerList.push_back(Customer(customerId, membershipLevel, point, name, dateOfBirth, address, phone, email));
            }
        }
        input.close();
        this->customerList = CustomerList;
    };

    void DisplayCustomerList()
    {
        cout << setw(5) << left << "ID"
             << setw(20) << left << "Ten Khach hang"
             << setw(20) << left << "Bac thanh vien"
             << setw(10) << left << "Diem"
             << setw(15) << left << "Ngay Sinh"
             << setw(20) << left << "Dia chi"
             << setw(15) << left << "So dien thoai"
             << setw(20) << left << "Email"
             << endl;

        for (int i = 0; i < this->customerList.size(); i++)
        {
            cout << setw(5) << left << this->customerList[i].getCustomerId()
                 << setw(20) << left << this->customerList[i].getName()
                 << setw(20) << left << this->customerList[i].getMembershipLevel()
                 << setw(10) << left << this->customerList[i].getPoint()
                 << setw(15) << left << this->customerList[i].getDateOfBrith()
                 << setw(20) << left << this->customerList[i].getAddress()
                 << setw(15) << left << this->customerList[i].getPhoneNumber()
                 << setw(20) << left << this->customerList[i].getEmail()
                 << endl;
        }
    }

    void addCustomer()
    {
        int n;
        int customerId;
        string membershipLevel;
        int point;
        string name;
        string dateOfBirth;
        string address;
        string phone;
        string email;

        cout << "So luong Khach hang muon them: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin.ignore(32767, '\n');
            customerId = this->customerList.back().getCustomerId() + 1;

            cout << "Khach hang " << i + 1 << endl;
            cout << "Nhap ten Khach hang: ";
            getline(cin, name);
            cout << "Bac thanh vien: ";
            getline(cin, membershipLevel);
            cout << "Diem: ";
            cin >> point;
            cin.ignore(32767, '\n');

            cout << "Ngay sinh: ";
            getline(cin, dateOfBirth);
            cout << "Dia chi: ";
            getline(cin, address);
            cout << "So dien thoai: ";
            getline(cin, phone);
            cout << "Email: ";
            getline(cin, email);

            this->customerList.push_back(Customer(customerId, membershipLevel, point, name, dateOfBirth, address, phone, email));
        }
    }

    void removeCustomer()
    {
        int id;
        cout << "Nhap ma khach hang ban muon xoa: ";
        cin >> id;
        for (int i = 0; i < this->customerList.size(); i++)
        {
            if (this->customerList[i].getCustomerId() == id)
            {
                this->customerList.erase(this->customerList.begin() + i);
                return;
            }
        }
    }
    //
};
int main()
{
    ProductFile data;
    // Load data product
    ControllProduct ProductController(data.loadProduct("product.csv"));

    Store StoreController;
    // Load data employees
    StoreController.loadEmployee("employee.csv");

    // Load data customer
    StoreController.loadCustomer("customers.csv");

    int choice;
    int option;
    do
    {
        system("cls");
        cout << "\n\tVui long nhap su lua chon cua ban:";
        cout << "\n\t\t1.Quan li nhan vien";
        cout << "\n\t\t2.Quan li khach hang ";
        cout << "\n\t\t3.Quan li don hang";
        cout << "\n\t\t4.Quan li kho hang";
        cout << "\n\t\t5.Thong tin cham soc khach hang ";
        cout << "\n\t\t6.Thoat";
        cout << "\n\t Nhap su lua chon cua ban:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            do
            {
                system("cls");
                StoreController.DisplayEmployeesList();

                cout << "\n\tVui long nhap su lua chon cua ban:";
                cout << "\n\t\t1.Them thong tin nhan vien moi ";
                cout << "\n\t\t2.Xoa nhan vien moi ";
                cout << "\n\t\t3.Lui lai ";

                cout << "\n\n\t Nhap su lua chon cua ban: ";
                cin >> option;
                switch (option)
                {
                case 1:
                    StoreController.addEmployee();
                    system("cls");
                    StoreController.DisplayEmployeesList();
                    break;
                case 2:
                    StoreController.removeEmployee();
                    system("cls");
                    StoreController.DisplayEmployeesList();
                    break;
                case 3:
                    break;
                }
            } while (option != 3);
            break;
        case 2:
            do
            {
                system("cls");
                StoreController.DisplayCustomerList();

                cout << "\n\tVui long nhap su lua chon cua ban:";
                cout << "\n\t\t1.Them thong tin khach hang moi ";
                cout << "\n\t\t2.Xoa thong tin khach hang ";
                cout << "\n\t\t3.Lui lai ";

                cout << "\n\n\t Nhap su lua chon cua ban: ";
                cin >> option;
                switch (option)
                {
                case 1:
                    StoreController.addCustomer();
                    system("cls");
                    StoreController.DisplayCustomerList();
                    break;
                case 2:
                    StoreController.removeCustomer();
                    system("cls");
                    StoreController.DisplayCustomerList();
                    break;
                case 3:
                    break;
                }
            } while (option != 3);
            break;
        case 3:
            manageOrders();
            break;
        case 4:
            do
            {
                system("cls");
                ProductController.Display();

                cout << "\n\tVui long nhap su lua chon cua ban:";
                cout << "\n\t\t1.Them thong tin san pham moi";
                cout << "\n\t\t2.Xoa thong tin san pham ";
                cout << "\n\t\t3.Lui lai ";

                cout << "\n\n\t Nhap su lua chon cua ban: ";
                cin >> option;
                switch (option)
                {
                case 1:
                    ProductController.addProduct();
                    system("cls");
                    ProductController.Display();
                    break;
                case 2:
                    ProductController.removeProduct();
                    system("cls");
                    ProductController.Display();
                    break;
                case 3:
                    break;
                }
            } while (option != 3);
            break;
        case 5:
            system("cls");
            cout << "\tNeu ban co loi gi thi ban hay toi chung toi phong so 2 o khach san vtc chi nhanh Ho Chi Minh";
            cout << "\n\tCam on ban da lang nghe chung toi!!";
            int e;
            cout << "\n\tNhan 0 de lui lai hoac 1 la thoat";
            cin >> e;
            switch (e)
            {
            case 0:
                system("cls");
                break;
            case 1:
                exit(1);
            default:
                cout << "Ban nhap ngu vui long nhap lai !!!" << endl;
                cout << "Nhap lai";
                cin >> e;
                break;
            }
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "Vui long nhap lai!!";
            break;
        }
    } while (choice <= 7);
    cout << "Cam on ban nhei!!";

    return 0;
}
