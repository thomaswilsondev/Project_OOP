#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
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
    Person(){};

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

    string getName()
    {
        return this->name;
    }

    string getDateOfBrith()
    {
        return this->dateOfBirth;
    }

    string getAddress()
    {
        return this->address;
    }

    string getPhone()
    {
        return this->phone;
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
class OrderItem : public Person
{
private:
    int orderItemId;
    string product;
    int quantity;
    int price;

protected:
public:
    // GETTER
    int getOrderItemId() { return orderItemId; };
    string getProduct() { return product; };
    int getQuantity() { return quantity; };
    double getPrice() { return price; };
    // SETTER
    void setOrderItemId(int orderItemId)
    {
        this->orderItemId = orderItemId;
    }
    void setProduct(string product)
    {
        this->product = product;
    }
    void setQuantity(int quantity)
    {
        this->quantity = quantity;
    }
    void setPrice(int price)
    {
        this->price = price;
    }

    // CONTRUCTOR
    OrderItem(int orderItemId, string product, int quantity, int price)
    {
        this->orderItemId = orderItemId;
        this->product = product;
        this->quantity = quantity;
        this->price = price;
    }
};
class Order
{
private:
    int orderId;
    string customer;
    vector<OrderItem> orderItem;
    vector<OrderItem> totalPrice;
    string orderDate;

protected:
public:
    int indexOrderID = 0;
    // GETTER
    int getOrderId() { return orderId; };
    string getCustomer() { return customer; };
    void getOrderItem(vector<OrderItem> orderItem)
    {
        for (int i = 0; i < orderItem.size(); i++)
        {
            cout << "Product " << orderItem[i].getOrderItemId() << " :"
                 << orderItem[i].getProduct() << " ,"
                 << orderItem[i].getQuantity() << " ,"
                 << orderItem[i].getPrice();
        }
    }
    int getTotalPrice(vector<OrderItem> orderItem)
    {
        int sum = 0;
        for (int i = 0; i < orderItem.size(); i++)
        {
            sum = sum + orderItem[i].getPrice() * orderItem[i].getQuantity();
        }
        return sum;
    }
    void getOrderDate(string orderDate)
    {
        this->orderDate = orderDate;
    }
    // SETTER
    int setTotalPrice(vector<OrderItem> orderItem, int tip)
    {
        int total = getTotalPrice(orderItem) + getTotalPrice(orderItem) * (tip / 100);
        return total;
    }
    void setCustomer(string customer)
    {
        this->customer = customer;
    }
    void setOrderID()
    {
        this->orderId = indexOrderID++;
    }
    void setOrderItem(vector<OrderItem> orderItem)
    {
        for (int i = 0; i < orderItem.size(); i++)
        {
            string producer;
            int quantity = 0;
            double price = 0;
            orderItem[i].setOrderItemId(i);
            cout << "Product " << orderItem[i].getOrderItemId() << endl;
            cout << "Enter name Producer: ";
            cin >> producer;
            orderItem[i].setProduct(producer);
            cout << "Enter Quantity: ";
            cin >> quantity;
            orderItem[i].setQuantity(quantity);
            cout << "Enter Price: ";
            cin >> price;
            orderItem[i].setPrice(price);
            cout << "\n\n";
        }
    }
    void setOrderDate()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        cout << "Time: " << ltm->tm_sec << endl;
        cout << "Date: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year;
    }
    void addOrderIteam(vector<OrderItem> orderItem)
    {
        string producer;
        int quantity = 0;
        double price = 0;
        orderItem[orderItem.size()].setOrderItemId(orderItem.size());
        cout << "Product " << orderItem[orderItem.size()].getOrderItemId() << endl;
        cout << "Enter name Producer: ";
        cin >> producer;
        orderItem[orderItem.size()].setProduct(producer);
        cout << "Enter Quantity: ";
        cin >> quantity;
        orderItem[orderItem.size()].setQuantity(quantity);
        cout << "Enter Price: ";
        cin >> price;
        orderItem[orderItem.size()].setPrice(price);
        cout << "\n\n";
    }
    // CONTRUCTOR
    Order(int orderId, string customer, vector<OrderItem> orderItem, string orderDate)
    {
        this->orderId = orderId;
        this->customer = customer;
        this->orderItem = orderItem;
        this->orderDate = orderDate;
    }
};
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
                 << setw(15) << left << this->employeesList[i].getPhone()
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
                 << setw(15) << left << this->customerList[i].getPhone()
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
        cout << "\n\tVui lòng lự chọn một số option:";
        cout << "\n\t\t1.Quản lí Nhân viên ";
        cout << "\n\t\t2.Quản lí Khách hàng ";
        cout << "\n\t\t3.Quản lí đơn đặt hàng";
        cout << "\n\t\t4.Quản lí kho hàng";
        cout << "\n\t\t5.Thông tin liên hệ chăm sóc khách hàng ";
        cout << "\n\t\t6.Thoát";
        cout << "\n\t Nhập vào sự lựa chọn của bạn: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            do
            {
                system("cls");
                StoreController.DisplayEmployeesList();

                cout << "\n\tVui lòng lự chọn một số option:";
                cout << "\n\t\t1.Thêm thông tin nhân viên mới ";
                cout << "\n\t\t2.Xoá thông tin nhân viên ";
                cout << "\n\t\t3.Lùi lại ";

                cout << "\n\n\t Nhập vào sự lựa chọn của bạn: ";
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

                cout << "\n\tVui lòng lự chọn một số option:";
                cout << "\n\t\t1.Thêm thông tin khách hàng mới ";
                cout << "\n\t\t2.Xoá thông tin khách hàng ";
                cout << "\n\t\t3.Lùi lại ";

                cout << "\n\n\t Nhập vào sự lựa chọn của bạn: ";
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
            do
            {
                system("cls");

                cout << "\n\tVui lòng lự chọn một số option:";
                cout << "\n\t\t1.Thêm thông tin đặt hàng";
                cout << "\n\t\t2.Xoá thông tin đặt hàng";
                cout << "\n\t\t3.Lùi lại ";

                cout << "\n\n\t Nhập vào sự lựa chọn của bạn: ";
                cin >> option;
                switch (option)
                {
                case 1:

                    break;
                case 2:

                    break;
                case 3:
                    break;
                }
            } while (option != 3);
            break;
        case 4:
            do
            {
                system("cls");
                ProductController.Display();

                cout << "\n\tVui lòng lự chọn một số option:";
                cout << "\n\t\t1.Thêm thông tin sản phẩm mới ";
                cout << "\n\t\t2.Xoá thông tin sản phẩm ";
                cout << "\n\t\t3.Lùi lại ";

                cout << "\n\n\t Nhập vào sự lựa chọn của bạn: ";
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
            cout << "\tNếu bạn đang bị lỗi lầm gì. Xin hãy liên hệ cho sđt này: 08888888889, chúng tôi sẽ lắng nghe bạn 24/24";
            cout << "\n\tCảm ơn bạn đã lắng nghe và ủng hộ chúng tôi!!";
            int e;
            cout << "\n\tVui lòng nhấn 0 để lùi lại hoặc nhấn 1 để lùi lại:";
            cin >> e;
            switch (e)
            {
            case 0:
                system("cls");
                break;
            case 1:
                exit(1);
            default:
                cout << "Vui lòng bạn nhập lại vì bạn đã nhập sai cú pháp !!!" << endl;
                cout << "Nhập lại: ";
                cin >> e;
                break;
            }
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "Vui lòng nhập lại!!";
            break;
        }
    } while (choice <= 7);
    cout << "Cảm ơn bạn đã ủng hộ chúng tôi!!";

    return 0;
}
