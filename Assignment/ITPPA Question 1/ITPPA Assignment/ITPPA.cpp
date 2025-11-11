#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
using namespace std;
const float COFFEE_PRICE = 15.00;
const float SANDWICH_PRICE = 30.00;
const float SALAD_PRICE = 25.00;
const float JUICE_PRICE = 10.00;
const float MUFFIN_PRICE = 20.00;
const float PIZZA_PRICE = 35.00;
const float SOUP_PRICE = 18.00;
const float BURGER_PRICE = 40.00;
const float DISCOUNT_RATE = 0.1;
const float DISCOUNT_THRESHOLD = 100.00;
int main() {
	//cafeteria order system, question 1
	string name, surname;
	int numOrder, i, order, ordertotal;//numOrder is the amount of items that you're ordering, order is the menu item's NUMBER
	float price, discountedprice;

	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Enter your surname: ";
	getline(cin, surname);
	cout << "How many items would you like? (You can select up to 8 items): ";
	cin >> numOrder;
	if ((numOrder > 0) && (numOrder <= 8)) {//make sure that the amount of items is correctly selected.


		cout << "Menu\n" << "1. Coffee - R"<< COFFEE_PRICE<<"\n" << "2. Sandwich - R" << SANDWICH_PRICE << "\n" << "3. Salad - R" << SALAD_PRICE << "\n" << "4. Juice - R" << JUICE_PRICE << "\n" << "5. Muffin - R" << MUFFIN_PRICE << "\n" << "6. Pizza Slice - R" << PIZZA_PRICE << "\n" << "7. Soup - R" << SOUP_PRICE << "\n" << "8. Burger - R" << BURGER_PRICE << "\n";


		ordertotal = 0;
		price = 0;//price and ordertotal will be continually incremented, so they need starting values.
		


		for (i = 0; i < numOrder; i++) {
			cout << "Select item " << i+1 << " (1-8): ";
			cin >> order;
			if ((order >= 1) && (order <= 8)) {//another if statement to ensure that the menu items are correctly selected


				switch (order) {
				case 1:
					ordertotal = ordertotal + COFFEE_PRICE;
					break;
				case 2:
					ordertotal = ordertotal + SANDWICH_PRICE;
					break;
				case 3:
					ordertotal = ordertotal + SALAD_PRICE;
					break;
				case 4:
					ordertotal = ordertotal + JUICE_PRICE;
					break;
				case 5:
					ordertotal = ordertotal + MUFFIN_PRICE;
					break;
				case 6:
					ordertotal = ordertotal + PIZZA_PRICE;
					break;
				case 7:
					ordertotal = ordertotal + SOUP_PRICE;
					break;
				case 8:
					ordertotal = ordertotal + BURGER_PRICE;
					break;
				}
			}
			else {
				cout << "That is not a valid menu number.\n";
				break;
			}

		}
		cout << "Total Bill: R" << ordertotal << endl;
		if (ordertotal > DISCOUNT_THRESHOLD){
			ordertotal = ordertotal * (1-DISCOUNT_RATE);
			cout << "Discount is applied.\nFinal Bill: R" << ordertotal << endl;
		}
		else {
			cout << "No discount is applied.\n"<<"Final Bill: R"<<ordertotal << endl;
		}
		
	}
	else {
		cout << "Please enter a valid amount of items you'd like to order.\n";
		exit;
	}
	ofstream Bill("CafeteriaBill.txt"); //this part of the code is to simply open or create a file, check if it exists, and write to it.
	if (Bill.is_open()) {
		Bill << name << " " << surname << " Final Bill: R" << ordertotal << endl;
		Bill.close();
		cout << "The bill has been written to CafeteriaBill.txt.\n";
	}
	else {
		cerr << "Error opening the file.\n";
	}
		
		return 0;
}