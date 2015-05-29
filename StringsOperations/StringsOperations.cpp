// StringsOperations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

 
//Write a function to remove all trailing blanks from the right end of a string.Assume the prototype is
string trim(string a){

	char start = a.find(' ');
	while (start != string::npos){
		char runner = start;

		while (a[runner] != '\0'){
			a[runner] = a[runner + 1];
			runner++;
		}
		start = a.find(' ');
	}
	return a;
}


/*Write a function to add extra blanks to the right end of a string to make it at least length n.
If the string is already n characters or longer, do not change the string.*/
string padRight(string a, int n){
	int size = a.size();
	if (n <= size) return a;
	cout << "current size is " << a.size() << endl;
	a.resize(n);

	for (int i = size; a[i] != '\0'; i++){
		a[i] = ' ';
	}
	cout << "new size is " << a.size() << endl;
	return a;
}

string padLeft(string a, int n){
	int size = a.size();
	if (n <= size) return a;
	cout << "current size is " << a.size() << endl;
	a.resize(n);

	for (int i = n-1; i >= n-size ; i--){
		a[i] = a[i -(n-size)];
	}
	for (int i = n - size -1; i >= 0; i--){
		a[i] = ' ';
	}
	cout << "new size is " << a.size() << endl;
	return a;
}

/*Write a function to center a string by adding blanks to the front and back.
If the string is already n characters or longer, do not change the string.
If an odd number of blanks have to be added, put the extra blank on the right.
You can use the functions in the previous problems(padRight and padLeft) to solve this problem.*/
void center(string a, int n){
	cout << "sentence not centered : " << endl << a << endl;
	int size = a.size();
	if (size >= n) return;

	int nbSpaces = n - size;
	int nbLeftSpaces = nbSpaces / 2;

	a = padLeft(a, size + nbLeftSpaces);
	a = padRight(a, n);

	cout << "sentence centered with " << nbLeftSpaces << " leftSpaces and " << nbSpaces - nbLeftSpaces << " rightSpaces" << " : " << endl << a << ".";

}

bool isPalindrome(string word){
	int size = word.size();

	for (int i = 0; i <= size / 2; i++){
		if (word[i] != word[size - i - 1])
			return false;
	}

	return true;
}

string truncate(string a, int n) {
	int size = a.size();
	if (n > size) return a;

	a.resize(n);
	return a;
}

char toUpper(char letter){
	int smallA = 'a';
	int diff = 'a' - 'A';

	if ((int)letter > smallA) return letter;
	
	return letter - diff;
}

char toLower(char letter){
	int smallA = 'a';
	int diff = 'a' - 'A';

	if ((int)letter > smallA) return letter;

	return letter + diff;
}



/*Write a function which capitalizes the first letter in every word.
Assume the first letter is any letter at the beginning or preceded by a blank.
All other letters should be turned into lowercase.You can use the library toupper and tolower functions.*/
string capitalizeWords(string a){
	int size = a.size();
	if (a.empty()) return a;
	a[0] = toupper(a[0]);
	bool toLower = true;

	for (int i = 1; i < size; i++){
		if (a[i] == ' ') {
			toLower = false;
		}
		else{

			if (toLower) a[i] = tolower(a[i]);
			else{
				a[i] = toupper(a[i]);
				toLower = true;
			}
		}
	}
	return a;
}

//Write a function, reverse, which reverses the characters in the argument.Assume the prototype is
string reverse(string a){
	int size = a.size();
	string result;
	result.resize(size);

	for (int i = 0; i < size; i++){
		result[i] = a[size - i - 1];
	}
	return result;
}

string reverseInPlace(string a){
	int size = a.size();
	char tmp;
	
	for (int i = 0; i < (size/2); i++){
		tmp = a[size - i - 1];
		a[size - i - 1] = a[i] ;
		a[i] = tmp;
	}
	return a;
}

//Write a function, count, which counts the occurrences in the first argument, a, of the single character which is the second argument, c.
int count(string sentence, char c){
	int number = 0;
	int find = sentence.find(c, 0);
	while (find != string::npos){
		number++;
		find = sentence.find(c, find+1);
	}
	return number;
}

//Write a function, count, which counts the occurrences in the first argument, a, of the characters in the second argument, b.
int countMultiple(string a, string b){
	int number = 0;
	int size = b.size();

	for (int i = 0; i < size; i++){
		number += count(a, b[i]);
	}
	return number;
}

/*Write a function, deleteChar, which deletes any occurrence in the first argument, a, 
of the single character which is the second argument, c. */
void deleteChar(string* a, char c){
	int size = a->size();
	int index = a->find(c, 0);

	while (index != string::npos){
		for (int j = index; j < size -1; j++){
			a->at(j) = a->at(j + 1);
		}
		a->resize(size-1);
		size--;
		index = a->find(c, 0);
	}
}


int eval(string expression){
	int size = expression.size();
	int total = 0;
		int opera = expression.find(' ') + 1;
		int begin = opera + 2;
		int end = opera + 2;
		if (expression[opera] == '+'){
			while (expression[begin+1] != '\0'){
				end = expression.find(' ', begin );
				string subs = expression.substr(begin, end - begin);
				if (!subs.compare( "(")){
					end = expression.find(')', begin);
					string new_express = expression.substr(begin, end - begin+1);
					int num = eval(new_express);
					total += num;
				}
				else{
					total += atoi(subs.c_str());
				}

				begin = end + 1;
			}
		}
		else{
			if (total == 0) total = 1;
			while (expression[begin] != ')'){
				end = expression.find(' ', begin);
				string subs = expression.substr(begin, end - begin);
				if (!subs.compare("(")){
					end = expression.find(')', begin);
					string new_express = expression.substr(begin, end - begin + 1);
					int num = eval(new_express);
					total *= num;
				}
				else{
					total *= atoi(subs.c_str());
				}

				begin = end + 1;
			}
		}
	return total;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string sentence = "je suis UN CHAT.";
	/*cout << sentence << " without space is : " << trim(sentence) << endl;
	cout << sentence << " resized : " << padRight(sentence, 20) << endl;
	cout << sentence << " resized : " << padLeft(sentence, 20) << endl;
	center(sentence, 20);*/

	/*string word = "noon";
	cout << "Is " << word << " a palindrome? " << isPalindrome(word) << endl;
	word = "chapouniche";
	cout << "Is " << word << " a palindrome? " << isPalindrome(word) << endl;

	word = "lonnnnnnng mot";
	cout << "Truncate " << word << " is " << truncate(word, 5) << endl;*/

	/*cout << "capitalize " << sentence << " is " << endl << capitalizeWords(sentence) << endl;
	cout << "Reverse " << sentence << " is : " << reverse(sentence) << endl;
	cout << "Reverse (in place) " << sentence << " is : " << reverseInPlace(sentence) << endl;*/
	string word = "abracadabra";
	//cout << " there are " << count(word, 'a') << " a  in " << word << endl;

	/*string find = "bax";
	cout << " there are " << countMultiple(word, find) << " bax  in " << word << endl;

	deleteChar(&word, 'a');
	cout << " abracadabra without a is " << word  << endl;*/

	string expression = "( + 1 2  15 )";
//	cout << "total of " << expression << " is : " << eval(expression) << endl; 
	string bigger_expression = "( + ( * 2 2 ) ( * 3 3 ) )";
	cout << "total of " << bigger_expression << " is : " << eval(bigger_expression) << endl;

	string big_ass_expression = "( + ( * 2 2 ) ( * 3 3 ) ( + 5 1 ( + 7 2 ) ) )";
	cout << "total of " << big_ass_expression << " is : " << eval(big_ass_expression) << endl;


	system("pause");
	return 0;
}

