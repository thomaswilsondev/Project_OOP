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
<<<<<<< HEAD
=======

class Supplier : public Person
{
private:
    int supplierId;
    string companyName;
    string taxCode;

protected:
public:
    // Getter
    int getSupplierId() { return supplierId; };
    string getCompanyName() { return companyName; };
    string getTaxCode() { return taxCode; };
    // Setter
    void setSupplierId(int supplierId)
    {
        this->supplierId = supplierId;
    };
    void setCompanyName(string companyName)
    {
        this->companyName = companyName;
    }
    void setTaxCode(string taxCode)
    {
        this->taxCode = taxCode;
    }
    // Contructor
    Supplier(int supplierId, string companyName, string taxCode);
    ~Supplier(){};
};
>>>>>>> a1fc41bf74c4274177175c448ceebd2dd2daf198
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
    OrderItem(int orderItemId, string product, int quantity, int price);
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
    void getOrderItem(vector<OrderItem> orderItem);
    int getTotalPrice(vector<OrderItem> orderItem);
    void getOrderDate(string orderDate);
    // SETTER
    int setTotalPrice(vector<OrderItem> orderItem, int tip);
    void setCustomer(string customer);
    void setOrderID();
    void setOrderItem(vector<OrderItem> orderItem);
    void setOrderDate();
    void addOrderIteam(vector<OrderItem> orderItem);
    // CONTRUCTOR
    Order(int orderId, string customer, vector<OrderItem> orderItem, string orderDate);
};
class Product
{
private:
    int productId;
    string productName;
    string productType;
    string description;
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
    string getProductType()
    {
        return this->productType;
    };
    string getDescription()
    {
        return this->description;
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
    void setProductType(string productType)
    {
        this->productType = productType;
    };
    void setDescription(string description)
    {
        this->description = description;
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
    Product(int productId, string productName, string productType, string description, float price, int inventory);
    ~Product(){};
};

class ProductFile
{
public:
    // Read input from csv file and return product list;
    vector<Product> loadProduct(string filename);
    // write product list into file csv
    void saveProduct(string filename, vector<Product> ProductList);
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
    void Display();
    // Add item into product list
    void addProduct();
    // Remove item form product list
    void removeProduct();
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

    void addEmployee(Employee employee)
    {
        this->employeesList.push_back(employee);
    }
};
int main()
{
    // Employee a(1, "a", 2.3, "b", "c", "d", "e", "f", "g");

    // cout << a.getName() << " "
    //      << a.getDateOfBrith() << " "
    //      << a.getAddress() << " "
    //      << a.getPhone() << " "
    //      << a.getEmail() << endl;

    int choice;
    do
    {
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
            system("clear");
            int a;
            cout << "\n\tVui lòng lự chọn một số option:";
            cout << "\n\t\t1.Thêm thông tin nhân viên mới ";
            cout << "\n\t\t2.Xoá thông tin nhân viên ";
            cout << "\n\t\t3.Sửa thông tin nhân viên ";
            cout << "\n\t\t4.Lùi lại ";
            cout << "\n\t\t5.Thoát";
            cout << "\n\t Nhập vào sự lựa chọn của bạn: ";
            cin >> a;
            switch (a)
            {
            case 1:
                /* code */
                break;
            case 2:
                /* code */
                break;
            case 3:
                /* code */
                break;
            case 4:
                system("clear");
                break;
            default:
                exit(1);
            }
            break;
        case 2:
            system("clear");
            int b;
            cout << "\n\tVui lòng lự chọn một số option:";
            cout << "\n\t\t1.Thêm thông tin khách hàng mới ";
            cout << "\n\t\t2.Xoá thông tin khách hàng ";
            cout << "\n\t\t3.Sửa thông tin khách hàng ";
            cout << "\n\t\t4.Lùi lại";
            cout << "\n\t\t5.Thoát";
            cout << "\n\t Nhập vào sự lựa chọn của bạn: ";
            cin >> b;
            switch (b)
            {
            case 1:
                /* code */
                break;
            case 2:
                /* code */
                break;
            case 3:
                /* code */
                break;
            case 4:
                system("clear");
                break;
            default:
                exit(1);
            }
            break;
        case 3:
            system("clear");
            int c;
            cout << "\n\tVui lòng lự chọn một số option:";
            cout << "\n\t\t1.Thêm thông tin sản phẩm mới trong kho hàng";
            cout << "\n\t\t2.Xoá thông tin sản phẩm trong kho hàng";
            cout << "\n\t\t3.Sửa thông tin sản phẩm trong kho hàng";
            cout << "\n\t\t4.Lùi lại";
            cout << "\n\t\t5.Thoát";
            cout << "\n\t Nhập vào sự lựa chọn của bạn: ";
            cin >> c;
            switch (c)
            {
            case 1:
                /* code */
                break;
            case 2:
                /* code */
                break;
            case 3:
                /* code */
                break;
            case 4:
                system("clear");
                break;
            default:
                exit(1);
            }
            break;
        case 4:
            system("clear");
            int d;
            cout << "\n\tVui lòng lự chọn một số option:";
            cout << "\n\t\t1.Xem đơn đặt hàng của khách hàng";
            cout << "\n\t\t2.Thêm đơn đặt hàng của khách hàng";
            cout << "\n\t\t3.Sửa đơn đặt hàng của khách hàng";
            cout << "\n\t\t4.Xoá đơn đặt hàng của khách hàng";
            cout << "\n\t\t5.Lùi lại";
            cout << "\n\t\t6.Thoát";
            cout << "\n\t Nhập vào sự lựa chọn của bạn: ";
            cin >> d;
            switch (d)
            {
            case 1:
                /* code */
                break;
            case 2:
                /* code */
                break;
            case 3:
                /* code */
                break;
            case 4:
                /* code */
                break;
            case 5:
                system("clear");
                break;
            default:
                exit(1);
            }
            break;
        case 5:
            system("clear");
            cout << "\tNếu bạn đang bị lỗi lầm gì. Xin hãy liên hệ cho sđt này: 08888888889, chúng tôi sẽ lắng nghe bạn 24/24";
            cout << "\n\tCảm ơn bạn đã lắng nghe và ủng hộ chúng tôi!!";
            int e;
            cout << "\n\tVui lòng nhấn 0 để lùi lại hoặc nhấn 1 để lùi lại:";
            cin >> e;
            switch (e)
            {
            case 0:
                system("clear");
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
//-----------------------------------------------Product----------------------------------------------------
// CONTRUCTOR
Product::Product(int productId, string productName, string productType, string description, float price, int inventory)
{
    this->productId = productId;
    this->productName = productName;
    this->productType = productType;
    this->description = description;
    this->price = price;
    this->inventory = inventory;
}
//------------------------------------------ControllProduct----------------------------------
void ControllProduct::Display()
{
    cout << setw(5) << left << "ID"
         << setw(20) << left << "Ten sanp pham"
         << setw(20) << left << "Loai san pham"
         << setw(30) << left << "Mo ta"
         << setw(15) << left << "Gia"
         << setw(8) << left << "Ton kho"
         << endl;

    for (int i = 0; i < this->ProductList.size(); i++)
    {
        cout << setw(5) << left << this->ProductList[i].getProductId()
             << setw(20) << left << this->ProductList[i].getProductName()
             << setw(20) << left << this->ProductList[i].getProductType()
             << setw(30) << left << this->ProductList[i].getDescription()
             << setw(15) << left << this->ProductList[i].getPrice()
             << setw(8) << left << this->ProductList[i].getInventory()
             << endl;
    }
}
void ControllProduct::addProduct()
{
    int n;
    string productName;
    string productType;
    string description;
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
        cout << "Nhap loai san pham: ";
        getline(cin, productType);
        cout << "Nhap mo ta san pham: ";
        getline(cin, description);
        cout << "Nhap gia san pham: ";
        cin >> price;
        cout << "Nhap so luong ton kho: ";
        cin >> inventory;

        Product item(this->AutoID(), productName, productType, description, price, inventory);
        this->ProductList.push_back(item);
    }
}
void ControllProduct::removeProduct()
{
    int idRemovedProduct;
    cout << "Nhap ID san pham can xoa: ";
    cin >> idRemovedProduct;
    for (int i = 0; i < this->ProductList.size(); i++)
    {
        if (this->ProductList[i].getProductId() == idRemovedProduct)
        {
            ProductList.erase(ProductList.begin() + i);
            return;
        }
    }
    cout << "San pham khong ton tai" << endl;
}
//------------------------------------------ProductFile----------------------------------
void ProductFile::saveProduct(string filename, vector<Product> ProductList)
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
                   << ProductList[i].getProductType() << ","
                   << ProductList[i].getDescription() << ","
                   << ProductList[i].getPrice() << ","
                   << ProductList[i].getInventory() << endl;
        }
    }
    output.close();
}
vector<Product> ProductFile::loadProduct(string filename)
{
    vector<Product> ProductList;
    int productId;
    string productName;
    string productType;
    string description;
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
            getline(ss, productType, ',');
            getline(ss, description, ',');
            getline(ss, data, ',');
            price = stof(data);
            getline(ss, data, ',');
            inventory = stoi(data);

            ProductList.push_back(Product(productId, productName, productType, description, price, inventory));
        }
    }
    input.close();
    return ProductList;
};
//-----------------------------------------------Order----------------------------------------------------
void Order::getOrderItem(vector<OrderItem> orderItem)
{
    for (int i = 0; i < orderItem.size(); i++)
    {
        cout << "Product " << orderItem[i].getOrderItemId() << " :"
             << orderItem[i].getProduct() << " ,"
             << orderItem[i].getQuantity() << " ,"
             << orderItem[i].getPrice();
    }
}
int Order::getTotalPrice(vector<OrderItem> orderItem)
{
    int sum = 0;
    for (int i = 0; i < orderItem.size(); i++)
    {
        sum = sum + orderItem[i].getPrice() * orderItem[i].getQuantity();
    }
    return sum;
}
void Order::getOrderDate(string orderDate)
{
    this->orderDate = orderDate;
}
int Order::setTotalPrice(vector<OrderItem> orderItem, int tip)
{
    int total = getTotalPrice(orderItem) + getTotalPrice(orderItem) * (tip / 100);
    return total;
}
void Order::setCustomer(string customer)
{
    this->customer = customer;
}
void Order::setOrderID()
{
    this->orderId = indexOrderID++;
}
void Order::setOrderItem(vector<OrderItem> orderItem)
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
void Order::setOrderDate()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "Time: " << ltm->tm_sec << endl;
    cout << "Date: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year;
}
void Order::addOrderIteam(vector<OrderItem> orderItem)
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
Order::Order(int orderId, string customer, vector<OrderItem> orderItem, string orderDate)
{
    this->orderId = orderId;
    this->customer = customer;
    this->orderItem = orderItem;
    this->orderDate = orderDate;
}
//-----------------------------------------------OrderItem----------------------------------------------------
OrderItem::OrderItem(int orderItemId, string product, int quantity, int price)
{
    this->orderItemId = orderItemId;
    this->product = product;
    this->quantity = quantity;
    this->price = price;
}
//-----------------------------------------------Supplier----------------------------------------------------
Supplier::Supplier(int supplierId, string companyName, string taxCode)
{
    this->supplierId = supplierId;
    this->companyName = companyName;
    this->taxCode = taxCode;
}