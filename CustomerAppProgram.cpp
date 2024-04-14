 //product person customer class and whose data members and functions
#include<iostream>
#include<vector>
#include<String>
using namespace std;
class Product{
    public:
    string id;
    string pname;
    double price;

    Product(string id,string pname,double price)
    {
        this->id=id;
        this->pname=pname;
        this->price=price;
    }

};
class Person{
    public:
    string name;
    Person(string name)
    {
        this->name=name;
    }
};
class Customer:public Person{
    public:
    string mobile_no;
    vector<Product> PurchaseProduct;//purchase product
    //constructor
    Customer(string name ,string mobile_no):Person(name)
    {
        this->mobile_no=mobile_no;
    }

};
//make function
void display_all_products(  vector<Product>& products)
{
    
    for(auto& p:products)//for each loop
    {
        cout<<"ID:"<<p.id<<":"<<"P_Name:"<<p.pname<<":"<<"Price:"<<p.price<<endl;
    }
}
//display customer details
void display_all_customers(vector<Customer>& customers)
{
	for(auto& c:customers)
	{
		cout<<"customer Name:"<<c.name<<"::"<<" Mobile Number:"<<c.mobile_no<<endl;
	}
}
void add_new_customer(vector<Customer>&customers)
{
    cin.get();
    string name,mobile;
    cout<<"Enter Customer name:"<<endl;
    getline(cin,name);
    cout<<"Enter mobile number:"<<endl;
    getline(cin,mobile);
    Customer customer(name,mobile);
    customers.push_back(customer);
    cout<<" Customer Registered---------- ";
}
void add_new_product(vector<Product>&products)
{
    string id,p_name;
    double price;
    cout<<"Enter Product ID:"<<endl;
    cin.get();
    getline(cin,id);
    cout<<"Enter product Name:"<<endl;
    getline(cin,p_name);
    cout<<"Enter Product price:"<<endl;
    cin>>price;
    Product product(id,p_name,price);
    products.push_back(product);
}
void customerPurchaseProduct(vector<Customer>& customers,  vector<Product>& products)
{
	string mobile_no,product_id;
	cout<<"Enter Customer mobile Number:"<<endl;
	cin>>mobile_no;
	bool found_customer=false;
	for(auto& customer:customers)
	{
		if(customer.mobile_no==mobile_no)
		{
		
		found_customer=true;
		//display product
		display_all_products(products);
		//select product
		cout<<"Enter product id to purchases:"<<endl;
		cin>>product_id;
		bool found_product=false;
		for( auto& product:products)
		{
			if(product.id==product_id)
			{
			customer.PurchaseProduct.push_back(product);
			cout<<"product purchases successfully!"<<endl;
			found_product=true;
			break;	
			}
		}
		if(!found_product)
		{
			cout<<"product not found:"<<endl;
		}
		break;
		}
	}
	if(!found_customer)
	{
		cout<<"Customer not found!"<<endl;
	}
	
}
void displaypurchasesproduct(vector<Customer>& customers)
{
	string mobile_no;
	cout<<"Enter mobile number:to search customer:"<<endl;
	cin>>mobile_no;
	bool found_customer=false;
	for(auto& customer:customers)
	{
		if( customer.mobile_no==mobile_no)
		{
			found_customer=true;
			cout<<"purchases product by:"<<customer.name<<":"<<endl;
			for(auto& product:customer.PurchaseProduct)
			{
				cout<<"product name:"<<product.pname<<":"<<" price"<<":"<<product.price<<endl;
			}
			break;
		}
	}
	if(!found_customer)
	{
		cout<<"Customer not found"<<endl;
	}
}
int main()
{
    vector<Product> products;
    vector<Customer> customers;
    int choice;
    do{
        cout<<"----------Menu-------------"<<endl;
        cout<<"1.Display all products:"<<endl;
        cout<<"2.Add new Customer:"<<endl;
        cout<<"3.Display all customers:"<<endl;
        cout<<"4.Add new product: "<<endl;
        cout<<"5.Customer purchage the product:"<<endl;
        cout<<"6.Display product by a specific customer:"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"Enter choice:"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
        cout<<"Display all Product:"<<endl;
        display_all_products(products);
            break;
        case 2:
        cout<<"Add new Customer:"<<endl;
        
        add_new_customer(customers);
        cout<<"Added Successfully:"<<endl;
        break;
        case 3:
        	display_all_customers(customers);
        	break;
        case 4:
        cout<<"Add new product:"<<endl;
            add_new_product(products);
        break;
        case 5:
        	customerPurchaseProduct(customers,products);
        	break;
        case 6:
        	displaypurchasesproduct(customers);
        	break;
        		
        default:
            break;
        }
        
    }while(choice!=0);

    return 0;
}
