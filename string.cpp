#include <iostream>		// for cout, cin, etc
#include <string>		// for strings
#include <vector>		// for vectors
#include <fstream> 		// for file i/o input

using namespace std;	

int main() {

	cout << "\n---------------- Combine --------------\n";
	char happyArray[6] = {'H', 'a', 'p', 'p', 'y', '\0'};

	string birthdayString = " Birthday";

	// Combime the char array and string
	cout << happyArray + birthdayString << endl;

	cout << "\n---------------- Get & Print Input --------------\n";
	string yourName;
	cout << "What is your name?: ";
	getline(cin, yourName);

	cout << "hello " << yourName << endl;

	cout << "\n---------------- User Guess --------------\n";
	double eulersContant = 0.57721;
	string eulerGuess;
	double eulerGuessDouble;

	cout << "What is Euler's Constant?: ";
	getline(cin, eulerGuess);

	// change the string to double
	eulerGuessDouble = stod(eulerGuess);

	if(eulerGuessDouble == eulersContant) {
		cout << "You are right!" << endl;
	}
	else {
		cout << "Sorry, you are incorrect" <<endl;
	}

	cout << eulerGuess.append(" was your guess") << endl;

	cout << "\n---------------- Size of String --------------\n";
	cout << "Size of String?: " << eulerGuess.size() << endl;
	cout << "Is string empty?: " << eulerGuess.empty() << endl;

	cout << "\n---------------- Compare String --------------\n";
	string a = "a";
	string b = "b";
	cout << "a == b?: " << a.compare(b) << endl;
	cout << "b == a?: " << b.compare(a) << endl;

	string dogString = "dog";
	string catString = "cat";

	cout << "dog == cat?: " << dogString.compare(catString) << endl;
	cout << "dog == dog?: " << dogString.compare(dogString) << endl;
	cout << "cat == dog?: " << catString.compare(dogString) << endl;

	cout << "\n---------------- Assign Copies --------------\n";
	string wholeName = yourName.assign(yourName);
	cout << "Copy of your name: " << wholeName <<endl;

	string nickName = wholeName.assign(wholeName, 0, 2);
	cout << "Your nick name: " << nickName << endl;

	cout << "\n---------------- Find Index of: --------------\n";
	// find index of a substring
	int substringIndex = yourName.find("ang", 0);
	cout << "Index of 'ang': " << substringIndex << endl;

	cout << "\n---------------- Insert/Remove/Replace At: --------------\n";
	yourName.insert(2, "ili");
	cout << "After inserting 'ili': " << yourName <<endl;

	// erase those characters
	yourName.erase(2, 3);
	cout << "Removing 'ili': " << yourName << endl;

	// replace characters
	yourName.replace(2, 4, "mila");
	cout << "Replacing characters: " << yourName << endl;



	return 0;
}