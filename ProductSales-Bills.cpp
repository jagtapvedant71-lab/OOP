```cpp
#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
    int productId;
    string productName;
    float price;
    float monthlySales[12];
    float totalBill;
    float monthlyQuantity;

public:
    void acceptDetails()
    {
        cout << "Enter Product ID: ";
        cin >> productId;
        cin.ignore();

        cout << "Enter Product Name: ";
        getline(cin, productName);

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Monthly Sales for 12 months: ";
        monthlyQuantity = 0;

        for (int i = 0; i < 12; i++)
        {
            cin >> monthlySales[i];
            monthlyQuantity += monthlySales[i];
        }

        totalBill = monthlyQuantity * price;
    }

    void displayDetails()
    {
        cout << "\nProduct ID: " << productId << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: " << price << endl;
        cout << "Total Quantity Sold: " << monthlyQuantity << endl;
        cout << "Total Bill: " << totalBill << endl;
    }

    float getTotalBill()
    {
        return totalBill;
    }
};

int main()
{
    int n;

    cout << "Enter number of products (1-100): ";
    cin >> n;

    if (n < 1 || n > 100)
    {
        cout << "Invalid number of products!" << endl;
        return 1;
    }

    Product products[100];
    float grandTotal = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- PRODUCT " << (i + 1)
             << " DETAILS ---" << endl;

        products[i].acceptDetails();
        grandTotal += products[i].getTotalBill();
    }

    cout << "\n--- ALL PRODUCT DETAILS ---" << endl;

    for (int i = 0; i < n; i++)
    {
        products[i].displayDetails();
    }

    cout << "\nGrand Total Bill: " << grandTotal << endl;

    return 0;
}
```
