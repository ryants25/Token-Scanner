#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int tokenCheck(ifstream &x, char *t[])
{
	char line[1000];
	int counter = 0;
	char *tokptr;

	while (x.getline(line, 1000))
	{
		tokptr = strtok(line, " ");
		while (tokptr != nullptr)
		{
			t[counter] = new char[strlen(tokptr + 1)];
			strcpy(t[counter++], tokptr);
			tokptr = strtok(nullptr, " ");
		}
	}
	return counter;
}

void displayTokens(char *tokens[], int count)
{
	int characterCount = 0;
	int digitCount = 0;
	int specialCount = 0;
	int dataTypeCount = 0;
	int libCount = 0;
	int includeCount = 0;
	int TotalCounter = 0;

	for (int i = 0; i < count; i++)
	{
		cout << tokens[i];
		if (strcmp(tokens[i], "a") == 0 || (strcmp(tokens[i], "b") == 0) || (strcmp(tokens[i], "c") == 0) || (strcmp(tokens[i], "d") == 0) || (strcmp(tokens[i], "e") == 0) || (strcmp(tokens[i], "f") == 0) || (strcmp(tokens[i], "g") == 0) || (strcmp(tokens[i], "h") == 0) || (strcmp(tokens[i], "i") == 0) || (strcmp(tokens[i], "j") == 0) || (strcmp(tokens[i], "k") == 0) || (strcmp(tokens[i], "l") == 0) || (strcmp(tokens[i], "m") == 0) || (strcmp(tokens[i], "n") == 0) || (strcmp(tokens[i], "o") == 0) || (strcmp(tokens[i], "p") == 0) || (strcmp(tokens[i], "q") == 0) || (strcmp(tokens[i], "r") == 0) || (strcmp(tokens[i], "s") == 0) || (strcmp(tokens[i], "t") == 0) || (strcmp(tokens[i], "u") == 0) || (strcmp(tokens[i], "v") == 0) || (strcmp(tokens[i], "w") == 0) || (strcmp(tokens[i], "x") == 0) || (strcmp(tokens[i], "y") == 0) || (strcmp(tokens[i], "z") == 0) || (strcmp(tokens[i], "A") == 0) || (strcmp(tokens[i], "B") == 0) || (strcmp(tokens[i], "C") == 0) || (strcmp(tokens[i], "D") == 0) || (strcmp(tokens[i], "E") == 0) || (strcmp(tokens[i], "F") == 0) || (strcmp(tokens[i], "G") == 0) || (strcmp(tokens[i], "H") == 0) || (strcmp(tokens[i], "I") == 0) || (strcmp(tokens[i], "J") == 0) || (strcmp(tokens[i], "K") == 0) || (strcmp(tokens[i], "L") == 0) || (strcmp(tokens[i], "M") == 0) || (strcmp(tokens[i], "N") == 0) || (strcmp(tokens[i], "O") == 0) || (strcmp(tokens[i], "P") == 0) || (strcmp(tokens[i], "Q") == 0) || (strcmp(tokens[i], "R") == 0) || (strcmp(tokens[i], "S") == 0) || (strcmp(tokens[i], "T") == 0) || (strcmp(tokens[i], "U") == 0) || (strcmp(tokens[i], "V") == 0) || (strcmp(tokens[i], "W") == 0) || (strcmp(tokens[i], "X") == 0) || (strcmp(tokens[i], "Y") == 0) || (strcmp(tokens[i], "Z") == 0))
		{
			cout << "				<character>" << endl;
			characterCount++;
			TotalCounter++;
		}
		else if (strcmp(tokens[i], "0") == 0 || (strcmp(tokens[i], "1") == 0) || (strcmp(tokens[i], "2") == 0) || (strcmp(tokens[i], "3") == 0) || (strcmp(tokens[i], "4") == 0) || (strcmp(tokens[i], "5") == 0) || (strcmp(tokens[i], "6") == 0) || (strcmp(tokens[i], "7") == 0) || (strcmp(tokens[i], "8") == 0) || (strcmp(tokens[i], "9") == 0))
		{
			cout << "				<digit>" << endl;
			digitCount++;
			TotalCounter++;
		}
		else if (strcmp(tokens[i], "(") == 0 || (strcmp(tokens[i], ")") == 0) || (strcmp(tokens[i], "[") == 0) || (strcmp(tokens[i], "]") == 0) || (strcmp(tokens[i], "{") == 0) || (strcmp(tokens[i], "}") == 0) || (strcmp(tokens[i], "+") == 0) || (strcmp(tokens[i], "-") == 0) || (strcmp(tokens[i], "*") == 0) || (strcmp(tokens[i], "/") == 0) || (strcmp(tokens[i], "=") == 0) || (strcmp(tokens[i], ",") == 0) || (strcmp(tokens[i], ";") == 0) || (strcmp(tokens[i], "<") == 0) || (strcmp(tokens[i], ">") == 0) || (strcmp(tokens[i], ".") == 0))
		{
			cout << "				<special>" << endl;
			specialCount++;
			TotalCounter++;
		}
		else if (strcmp(tokens[i], "int") == 0 || (strcmp(tokens[i], "double") == 0) || (strcmp(tokens[i], "float") == 0))
		{
			cout << "				<data type>" << endl;
			dataTypeCount++;
			TotalCounter++;
		}
		else if (strcmp(tokens[i], "<iostream>") == 0 || (strcmp(tokens[i], "<string>") == 0) || (strcmp(tokens[i], "<stdio.h>") == 0) || (strcmp(tokens[i], "<fstream>") == 0) || (strcmp(tokens[i], "<iomanip>") == 0))
		{
			cout << "				<library>" << endl;
			libCount++;
			TotalCounter++;
		}
		else if (strcmp(tokens[i], "#include") == 0)
		{
			cout << "				<include>" << endl;
			includeCount++;
			TotalCounter++;
		}
		else
		{
			cout << endl;
			TotalCounter++;
		}
	}

	cout << endl;
	cout << "Total number of tokens: " << TotalCounter << endl;
	cout << endl;
	cout << "Number of characters: " << characterCount << endl;
	cout << "Number of digits: " << digitCount << endl;
	cout << "Number of special: " << specialCount << endl;
	cout << "Number of data types: " << dataTypeCount << endl;
	cout << "Number of libraries: " << libCount << endl;
	cout << "Number of include: " << includeCount << endl;
}


int main()
{
	char *tokenArr[1000];
	int tokCount = 0;

	string x;
	cout << "What file do you want to open? ";
	cin >> x;

	ifstream file;
	file.open(x);

	if (!file)
	{
		cout << "File not open!" << endl;
	}
	else
	{
		tokCount = tokenCheck(file, tokenArr);
		file.close();
		cout << endl;
		cout << "Tokens" << endl;
		cout << "----------" << endl;
		displayTokens(tokenArr, tokCount);
	}
	cin.get();
	cin.ignore();
}