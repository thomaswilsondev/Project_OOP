#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

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

class Order
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
protected:
public:
};
class OrderItem : public Person
{
private:
protected:
public:
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
    string filename = "product.csv";
    ProductFile data;
    cout << "Dau vao" << endl;
    ControllProduct controller(data.loadProduct(filename));
    controller.Display();

    cout << "\n\nSau khi them" << endl;

    controller.addProduct(Product(7, "Cat", "Cat bien vung tau", "Cat ok xay nha bao dep", 1000, 100));
    controller.Display();

    cout << "\n\nSau khi xoa" << endl;
    controller.removeProduct(5);
    controller.Display();

    return 0;
}
