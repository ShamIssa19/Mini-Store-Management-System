#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

int DisplayMainMenu()
{
    int choice;
    cout << "========== MINI STORE SYSTEM ==========" << endl;
    cout << "1. Add Products" << endl;
    cout << "2. Display All Products" << endl;
    cout << "3. Search for Product" << endl;
    cout << "4. Update Product Quantity" << endl;
    cout << "5. Sell a Product" << endl;
    cout << "6. Show Low Stock Products" << endl;
    cout << "7. Find Most Expensive Product" << endl;
    cout << "8. Sort Products by Price" << endl;
    cout << "9. Store Statistics" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter Your Choice : " << endl;
    cin >> choice;

    return choice;
}

void AddProduct(string names[], int ids[], double prices[], int quantities[], string categories[], int count)
{
    for(int i =0; i < count ; i++)
    {
        cout << "\nProduct" << (i+1) << " : " << endl;

        cin.ignore(10000, '\n');
        cout << "Name : ";
        getline(cin, names[i]);

        cout << "ID : ";
        cin >> ids[i];

        cout << "Price : ";
        cin >> prices[i];

        cout << "Quantity : ";
        cin >> quantities[i];

        cin.ignore(10000, '\n');
        cout << "Category : ";
        getline(cin, categories[i]);
    }
}

void DisplayAllProducts(const string names[], const int ids[], const double prices[], const int quantities[], int count)
{
    cout << "\n---------------------------------------------------" << endl;
    cout << setw(10) << left << "ID"
    << setw(15) << "Name"
    << setw(10) << "Price"
    << setw(10) << "Quantity" << endl;
    cout << "---------------------------------------------------" << endl;

    for(int i = 0; i < count ; i ++)
    {
        cout << setw(10) << left << ids[i]
        << setw(15) << names[i]
        << setw(10) << prices[i]
        << setw(10) << quantities[i] << endl;
    }
    cout << "---------------------------------------------------" << endl;
}

int SearchProductByID(const int ids[], int count, int TargetID)
{
    for(int i =0; i <count; i++)
    {
        if(ids[i] == TargetID)
        {
            return i;
        }
    }
    return -1;
}

void SearchAndPrintProduct(const string names[], const int ids[], const double prices[], const int quantities[], const string categories[], int count)
{
    int TargetID;
    cout << "Enter The ID of the product your searching for : " << endl;
    cin >> TargetID;

    int Index = SearchProductByID(ids, count, TargetID);

    if(Index != -1)
    {
        cout << "The Product is Found !" << endl;
        cout << "Name : " << names[Index] << endl;
        cout << "Price = " << prices[Index] << endl;
        cout << "Quantity = " << quantities[Index] << endl;
        cout << "Category : " << categories[Index] << endl;
    }
    else
    {
        cout << "The Product is Not Found!" << endl;
    }
}

void UpdateProductQuantity(const int ProductID[], int Quantities[], int count)
{
    cout << "Enter The ID of the product : " << endl;
    int TargetID;
    cin >> TargetID;
    int index = SearchProductByID(ProductID, count, TargetID);
    if(index != -1)
    {
        cout << "Enter the new Quantity : " << endl;
        int New_Quantity;
        cin >> New_Quantity;
        Quantities[index] = New_Quantity;
        cout << "The New Quantity = " << New_Quantity << endl;
    }
    else if(index == -1)
    {
        cout << "Product Is Not Found!" << endl;
    }
}

 void SellProduct(const int ProductID[], int Quantities[], int count, double ProductPrice[])
 {
     cout << "Enter the ID of the product you want to buy : " << endl;
     int TargetID;
     cin >> TargetID;

     int index = SearchProductByID(ProductID, count, TargetID);
     if(index == -1)
     {
         cout << "Product Not Found!" << endl;
     }
     else if(index != -1)
     {
         cout << "Enter the Quantity you want to buy : " << endl;
         int SellQuantity;
         cin >> SellQuantity;

         if(SellQuantity > Quantities[index])
         {
             cout << "The Process is Not Valid!" << endl;
         }
         else
         {
             Quantities[index] -= SellQuantity;
             double TotalPrice = SellQuantity * ProductPrice[index];
             cout << "Total Price = " << TotalPrice << endl << "Successful Process" << endl << "Remaining Stock = " << Quantities[index] << endl;
         }
     }
 }

void ShowSystemStats(double ProductPrice[], const int Quantities[], int count)
{
    if(count == 0)
    {
        cout << "No Products In The System" << endl;
    }

    double TotalInventoryValue = 0.0;
    for(int i =0 ; i < count; i++)
    {
        TotalInventoryValue += (ProductPrice[i] * Quantities[i]);
    }

    int Total_Stock_Items = 0;
    for(int i =0; i < count; i++)
    {
        Total_Stock_Items += Quantities[i];
    }


    cout << "\n=======================================" << endl;
    cout << "            STORE STATICS                " << endl;
    cout << "\n=======================================" << endl;
    cout << "Total Product : " << count << endl;
    cout << "Total Inventory Value = $" << TotalInventoryValue << endl;
    cout << "Total Quantity Stock = " << Total_Stock_Items << endl;
    cout << "=======================================\n" << endl;

}

void LowStockProduct(const string names[], const int ids[], const double prices[], const int quantities[], int count)
{
    if(count == 0)
    {
        cout << "No Products In The System" << endl;
    }
    int minIndex = 0;
    for(int i =0; i < count; i++)
    {
        if(quantities[i] < quantities[minIndex])
        {
            minIndex = i;
        }
    }

    cout << "\n===Lowest Stock Product ===" << endl;
    cout << "Name : " << names[minIndex] << endl;
    cout << "ID : " << ids[minIndex] << endl;
    cout << "Price : " << prices[minIndex] << endl;
    cout << "Quantity : " << quantities[minIndex] << endl;
    cout << "==============================\n" << endl;

}

void MostExpinsiveProduct(const string names[], const int ids[], const double prices[], const int quantities[], int count)
{
    if(count == 0)
    {
       cout << "No Products In The System" << endl;
       return;
    }

    int mostIndex = 0;
    for(int i =0; i < count; i++)
    {
        if(prices[i] > prices[mostIndex])
        {
            mostIndex = i;
        }
    }

    cout << "\n===MOST EXPINSIVE PRODUCT===" << endl;
    cout << "Name : " << names[mostIndex] << endl;
    cout << "ID : " << ids[mostIndex] << endl;
    cout << "Price = $" << prices[mostIndex] << endl;
    cout << "Quantity : " << quantities[mostIndex] << endl;
    cout << "==============================\n" << endl;
}

void SortingByPrice(int ids [], int quantities[], double prices[], string names[], string category[], int count)
{
   if(count == 0)
   {
       cout << "No Products In System" << endl;
       return;
   }

   for(int i =0; i < count - 1 ; i++)
   {
       int MaxIndex = i;

       for(int j =i+1 ; j < count - 1; j++)
       {
           if(prices[j] > prices[MaxIndex])
           {
               MaxIndex = j;
           }
       }

       if(MaxIndex != i)
       {
           int tempID = ids[i];
           ids[i] = ids[MaxIndex];
           ids[MaxIndex] = tempID;


           int tempQuantity = quantities[i];
           quantities[i] = quantities[MaxIndex];
           quantities[MaxIndex] = tempQuantity;


           string tempnames = names[i];
           names[i] = names[MaxIndex];
           names[MaxIndex] = tempnames;


           double tempPrice = prices[i];
           prices[i] = prices[MaxIndex];
           prices[MaxIndex] = tempPrice;


           string tempcategory = category[i];
           category[i] = category[MaxIndex];
           category[MaxIndex] = tempcategory;

       }
   }

   cout << "\n PRODUCTS SORTED BY PRICES SUCCESSFULLY " << endl;
}

void Exiting()
{
    cout << "Exiting The System" << endl;
}


int main()
{
    int count;

    // اخذ عدد المنتجات من المستخدم
    cout << "Enter the number of products : " << endl;
    cin >> count;

    //انشاء المصفوفات الديناميكية
    string *ProductName  = new string[count];
    int *ProductID       = new int[count];
    double *ProductPrice = new double[count];
    int *Quantity        = new int[count];
    string *Category     = new string[count];

    int choice;
    do
    {
        choice = DisplayMainMenu();
        switch(choice)
        {
        case 1 :
            AddProduct(ProductName, ProductID, ProductPrice, Quantity, Category, count); // call add
            break;

        case 2 :
            DisplayAllProducts(ProductName, ProductID, ProductPrice, Quantity, count); // call display
            break;

        case 3 :
            SearchAndPrintProduct(ProductName, ProductID, ProductPrice, Quantity, Category, count); // call search
            break;

        case 4 :
            UpdateProductQuantity(ProductID, Quantity, count); // call update
            break;

        case 5 :
            SellProduct(ProductID, Quantity, count, ProductPrice); // call sell
            break;

        case 6 :
            LowStockProduct(ProductName, ProductID, ProductPrice, Quantity, count); // call show
            break;

        case 7 :
            MostExpinsiveProduct(ProductName, ProductID, ProductPrice, Quantity, count); // call find
            break;

        case 8 :
            SortingByPrice(ProductID, Quantity, ProductPrice, ProductName, Category, count); // call sort
            break;

        case 9 :
            ShowSystemStats(ProductPrice, Quantity, count); // call store
            break;

        case 0 :
            Exiting(); // call exit
            break;

        default :
            cout << "Invalid Choice" << endl;
        }
    }
    while(choice != 0);



    //لتفريغ الذاكرة العشوائية المفتوحة
    delete[] ProductName;
    delete[] ProductID;
    delete[] ProductPrice;
    delete[] Quantity;
    delete[] Category;

    return 0;
}
