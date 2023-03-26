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
protected:
public:
};

class Store
{
private:
protected:
public:
};

class Customer : public Person
{
private:
protected:
public:
};

class Employee
{
private:
protected:
public:
};

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
    Supplier(int supplierId, string companyName, string taxCode)
    {
        this->supplierId = supplierId;
        this->companyName = companyName;
        this->taxCode = taxCode;
    }
    ~Supplier(){};
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

    Product(int productId, string productName, string productType, string description, float price, int inventory)
    {
        this->productId = productId;
        this->productName = productName;
        this->productType = productType;
        this->description = description;
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
                       << ProductList[i].getProductType() << ","
                       << ProductList[i].getDescription() << ","
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

public:
    // contructor
    ControllProduct(vector<Product> ProductList)
    {
        this->ProductList = ProductList;
    }

    // Display product list
    void Display()
    {
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

    // Add item into product list

    void addProduct(Product item)
    {
        this->ProductList.push_back(item);
    }

    // Remove item form product list
    void removeProduct(int idRemovedProduct)
    {
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
};
int main()
{
    // string filename = "product.csv";
    // ProductFile data;
    // cout << "Dau vao" << endl;
    // ControllProduct controller(data.loadProduct(filename));
    // controller.Display();

    // cout << "\n\nSau khi them" << endl;

    // controller.addProduct(Product(7, "Cat", "Cat bien vung tau", "Cat ok xay nha bao dep", 1000, 100));
    // controller.Display();

    // cout << "\n\nSau khi xoa" << endl;
    // controller.removeProduct(5);
    // controller.Display();

    //--------------Supplier----------------------
    // Supplier s(1, "ABC Company", "123456");
    // cout << "Supplier ID: " << s.getSupplierId() << endl;
    // cout << "Company Name: " << s.getCompanyName() << endl;
    // cout << "Tax Code: " << s.getTaxCode() << endl;
    // s.setCompanyName("XYZ Company");
    // cout << "New Company Name: " << s.getCompanyName() << endl;

    //---------------OrderItem-------------------------
    // OrderItem oi(1, "Product A", 2, 10);
    // cout << "Order Item ID: " << oi.getOrderItemId() << endl;
    // cout << "Product: " << oi.getProduct() << endl;
    // cout << "Quantity: " << oi.getQuantity() << endl;
    // cout << "Price: " << oi.getPrice() << endl;
    // oi.setQuantity(3);
    // cout << "New Quantity: " << oi.getQuantity() << endl;

    //---------------Order---------------------------
    // OrderItem oi1(1, "Product A", 2, 10);
    // OrderItem oi2(2, "Product B", 3, 20);
    // vector<OrderItem> items = {oi1, oi2};
    // Order o(1, "Customer A", items, "2022-01-01");
    // cout << "Order ID: " << o.getOrderId() << endl;
    // cout << "Customer: " << o.getCustomer() << endl;
    // o.getOrderItem(items);
    // cout << "\nTotal Price: " << o.getTotalPrice(items) << endl;

    return 0;
}
