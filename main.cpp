#include<iostream.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

 int header (){
		cout<<"PIZAMAN CHICKENMAN"<<endl;
		cout<<"Tax INVOICE"<<endl;
		cout<<"ORIGINAL RECEIPT"<<endl;
		cout<<"ORDER NUMBER 19"<<endl;
		cout<<"AHODWO BRANCH"<<endl;
		cout<<"AHODWO, MELCOME"<<endl;
		cout<<"PHONE: 0556061647"<<endl;
		cout<<"RECEIPT NUMBER: "<<endl;
		cout<<"|AG0228/5578/9965"<<endl;
		cout<<"TIN: C0029854564"<<endl;
	}

int main() {	
	string salesPerson, customerName, paymentMethod, pay, option;
	string items;
	float amount, itemPrice, qty, total;
	const float discout = 15;
	const float vat = 0.50;
	const float covid = 0.10;
	const float rate = 0.20;
	
	fstream dbfile;
	dbfile.open("Enock's  Shop.txt",ios::in | ios::app);

	//check if rentdb exist 
	if (!"RentDb"){
		cout<<"Failed to connect Rentdb"<<endl;
	}
	else{
		//connected successfully
		cout<<"Database Connected"<<endl;
		system("pause");
		system ("cls");
	
	
	
	cout<<"Enter Sales Person's Name: ";
	getline(cin, salesPerson);
	
	cout<<"Customer Name: ";
	getline(cin, customerName);
	
	paymentMethod: 
	cout<<"Choose Payment Method: "<<endl;
	cout<<"Momo, Visa, Cash: ";
	getline(cin, paymentMethod);
	
	if (paymentMethod == "Momo" || paymentMethod == "momo"){
		
		pay: 
		cout<<"Enter Money Number: ";
		getline(cin, pay);
		
		if(pay.size() < 10){
		cout<<endl;
		cout<<"Phone Number should not be less than 10"<<endl;
		goto pay;
		
	}else if (pay.size() > 10){
		cout<<"Phone Number should not be more than 10"<<endl;
		goto pay;
		
	}else(pay.size() == 10);{
		cout<<"Confirm Appoval from Molibe Device"<<endl;
	}

	else if(pay.size() == 12){
		cout<<"Choose the same date as the previors one"<<endl;
		else if{
			case: 1{
				cout<<"Get line <<momo_payment<< number"<<endl;
				getline(cin. momo)
			}
		}
	}
		
		
		
	}else if(paymentMethod == "Visa" || paymentMethod == "visa" ){
		string expiryDate, Cvv;
		
		cout<<"Enter Visa Card Number: ";
		getline(cin, pay);
		
			if(pay.size() < 8){
		cout<<endl;
		cout<<"Card Number should not be less than 8"<<endl;
		goto pay;
		
	}else if (pay.size() > 8){
		cout<<"Card Number should not be more than 8"<<endl;
		goto pay;
		
	}else(pay.size() == 8);{
		cout<<endl;
		// continue
	}
	
		cvv:	
		cout<<"Enter Expiry dd/mm/yy: ";
		getline(cin, expiryDate);
		
		cout<<"Enter CVV: ";
		getline(cin, Cvv);
		
		if(Cvv.size() < 3){
		cout<<endl;
		cout<<"Cvv should not be less than 3"<<endl;
		goto cvv;
		
	}else if (Cvv.size() > 3){
		cout<<"Cvv should not be more than 3"<<endl;
		goto cvv;
		
	}else(Cvv.size() == 3);{
		cout<<endl;
		//continue
	}
	
	}else if (paymentMethod == "Cash" || paymentMethod == "cash"){
		cout<<"Amout should be payed to the attendant"<<endl;
		cout<<endl;
	}else{
		goto paymentMethod;
	}
	

	
	dbfile << setw(30)<< "TAX INVOICE" << endl;
	dbfile << setw(32)<< "ORIGINAL RECEIPT" << endl;
	dbfile << setw(32)<<"ORDER NUMBER 19" << endl;
	dbfile << setw(30)<< "AHODWO BRANCH" << endl;
	dbfile << setw(33)<< "PHONE: 0556061647" << endl;
	dbfile << endl;
	dbfile << setw(35)<< "RECEIPT NUMBER: 16653" << endl;
	dbfile << setw(33)<< "|AG0228/5578/9965" << endl;
	dbfile << setw(32)<< "TIN: C0029854564" << endl;
	dbfile << setw(30)<< "Sales Person's: " << salesPerson << endl;
	dbfile << setw(30)<< "Payment Method: " << paymentMethod << endl;
	dbfile << "-----------------------------------------------" << endl;
	dbfile << "ITEM        QTY            RATE          TOTAL" << endl;
	
	
	while (true) {
            cout << "Input Item to be Purchased (press enter to stop): ";
            getline(cin, items);

            if (items.empty()) {
                break;
            }

            cout << "Enter Quantity: ";
            cin >> qty;
			

            cout << "Enter Price: ";
            cin >> itemPrice;

            total += (itemPrice * qty);
            
            
			
		dbfile << left << items << setw(10) << right << qty << setw(15) << right << itemPrice << setw(15) << right << itemPrice * qty << endl;
		cin.ignore(); // ignore newline character from input stream
            
        }
	
	dbfile<<"-----------------------------------------------"<<endl;
	dbfile << "Subtotal:" << setw(35) << right << total << endl;
	dbfile << "Discount(" << discout << "%):" << setw(30) << right << (total * discout / 100) << endl;
	dbfile << "Tax(" << vat << "%):" << setw(33) << right << (total * vat / 100) << endl;
	dbfile << "Covid-19 Tax(" << covid << "%):" << setw(25) << right << (total * covid / 100) << endl;
	dbfile << "Service Charge(" << rate << "%):" << setw(23) << right << (total * rate / 100) << endl;
	dbfile << "Net Total:" << setw(35) << right << (total + (total * vat / 100) + (total * covid / 100) + (total * rate / 100) - (total * discout / 100)) << endl;
	dbfile << "";
	dbfile<<"-----------------------------------------------"<<endl;
	dbfile << setw(40)<< "THANK YOU FOR BUYING FROM US"<<endl;
	dbfile << setw(33)<<  "REACH OUT TO US"<<endl;
	dbfile << endl;
	dbfile << "END OF ORDER" <<endl;
	dbfile << endl; 
	
	
	
	dbfile.close();
}	     		
	return 0;