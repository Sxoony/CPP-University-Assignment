#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <fstream>


using namespace std;
string name;
int accountnumber;
double balance;
fstream AccountDetail("AccountDetails.txt");//DECLARE GLOBAL VARIABLES THAT WILL BE USED BY MULTIPLE PROCESSES
string tempname;//Temp as in the input from the user that isnt validated yet.
int tempnum;
double tempdepo;


string createAccount(string &name, int &accountnumber, double &balance) {
	balance = -1;//if the account is created, then reset the balance from whatever it was to -1.
	

		cout << "Enter your name: ";
		cin >> tempname;
		cout << "Please enter your account number: ";// To ensure that the account number doesnt exist.
		cin >> tempnum;
		if (tempnum == accountnumber) {
			return("Account Number is invalid. Try another one.\n");
			
		}
		else {
			accountnumber = tempnum;
		}
		cout << "Enter your initial deposit (must be greater than 0): ";
		cin >> balance;
		if (balance <=0){
			while (balance <= 0) { //until the deposit is a positive number, greater than 0, this will loop.
				cout<< "Invalid deposit. Please try again"<<endl;
				cout << "Enter your initial deposit (must be greater than 0): ";
				cin >> balance;
			}
		}
		AccountDetail << name << " " << accountnumber << " " << balance;//write to the text file.

		return ("Account Successfully Created!\n");
	}
	
	


string depositBalance(double &balance) {
	
	cout << "Account Holder: ";
	cin >> tempname;
	if (tempname == name) {//make sure that the name is valid throughout the entire process
		cout << "Account Number: ";
		cin >> tempnum;
		if (tempnum == accountnumber) {//makes sure the account number is also valid throughout the process
			cout << "How much would you like to depoist? (Deposit must be greater than 0) ";
			cin >> tempdepo;
			if (tempdepo <= 0) {
				while (tempdepo <= 0) { //until the deposit is valid, this will forever loop. The program cannot crash.
					cout << "Invalid deposit. Please try again" << endl;
					cout << "Enter your deposit (must be greater than 0): ";
					cin >> tempdepo;
				}
			}
			balance = balance + tempdepo;
			return ("Deposit successful!\n");
		}
		else {
			return("Account Number not found. Try again.\n");
		}
	}
	else {
		return("Name not found. Try again.\n");
	}

}

string withdrawMoney(double &balance) {

	cout << "Account Holder: ";
	cin >> tempname;
	if (tempname == name) {//same validation as with every other function
		cout << "Account Number: ";
		cin >> tempnum;
		if (tempnum == accountnumber) {
			cout << "How much would you like to withdraw? (Must be less or equal to your available balance, and greater than 0) ";
			cin >> tempdepo;
			if ((tempdepo > balance)||(tempdepo<=0)) {// if the withdrawal is greater than the available balance, or if it is negative or 0, then you will be prompted to re-enter.
				while (((tempdepo>balance)||tempdepo<=0)) {
					cout << "Invalid withdrawal. Please try again" << endl;
					cout << "Enter your withdrawal (must be greater than 0 and less or equal to balance): ";
					cin >> tempdepo;
				}
			}
			balance = balance - tempdepo;
			return ("Withdrawal successful! Your remaining balanec is R"+ to_string(balance)+"\n");
		}
		else {
			return("Account Number not found. Try again.\n");
		}
	}
	else {
		return("Name not found. Try again.\n");
	}
}

string checkBalance(const double &balance) {
	cout << "Account Holder: ";
	cin >> tempname;
	if (tempname == name) {
		cout << "Account Number: ";
		cin >> tempnum;
		if (tempnum == accountnumber) {//this is the only bit of actual code that isnt just datavalidation
			return ("Your balance is R" + to_string(balance)+"\n");
		}
		else {
			return("Account Number not found. Try again.\n");
		}

	}
	else {
		return("Name not found. Try again.\n");
	}
}

string displayAccountDetails(const string &name, const int &accountnumber, const double &balance) {
	string returntext;//returntext is a temporary string for the lines in the text file to be read into. 
	cout << "Account Holder: ";
	cin >> tempname;
	if (tempname == name) {
		cout << "Account Number: ";
		cin >> tempnum;
		if (tempnum == accountnumber) {
			while (getline(AccountDetail, returntext)) {//this just lists the account details from the entire text file, which will only be 1 line.
				cout << returntext;
				
			}
			return(returntext);
		}
		else {
			return("Account Number not found. Try again.\n");
		}

	}
	else {
		return("Name not found. Try again.\n");
	}
}

int main() {
	string returntext;
	bool bDone = false;
	int number;
	string tempB;
	ifstream in("AccountDetails.txt", ios_base::in); //This is to read from the text file and manipulate the line to get different parts of it assigned to variables
	while (getline(AccountDetail, returntext)) {

		name = returntext.substr(0, returntext.find(" ") );
		returntext.erase(0, returntext.find(" ")+1 );
		//Every detail (name, account number, balance) is seperated by a space, so that is used as a place marker for the line to be read and deleted from.
		(accountnumber)= stoi(returntext.substr(0, returntext.find(" ")));
		returntext.erase(0, returntext.find(" ") +1);
		
	(balance) = stoi(returntext);//stoi is string to integer. you cant do to_string for balance, because it will then just be =0, same with account number
		

	}
		while (bDone == 0) {
			cout << "Bank Account Management System\n";
			cout << "1. Create Account \n2. Deposit Money \n3. Withdraw Money \n4. Check Balance \n5. Display Account Details \n6. Exit\n";
			cout << "Enter your choice (1-6): ";
			cin >> number;


			switch (number) {
			case 1:
				cout << createAccount(name, accountnumber, balance);
				break;
			case 2:
				cout << depositBalance(balance);
				break;
			case 3:
				cout << withdrawMoney(balance);
				break;
			case 4:
				cout << checkBalance(balance);
				break;
			case 5:
				cout << displayAccountDetails(name, accountnumber, balance);
				break;
			case 6:
				bDone = true;//if bDone = true, then that means that its value is actually 1, and 0 if its false. Exactly how Binary works.
				break;


			}

		}
	}
		
