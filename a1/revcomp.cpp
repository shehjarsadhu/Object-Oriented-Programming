// including all the required liberaries in the program.
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;
//Following program calculates the reverse  complement given a DNA sequence.
// calling tester ; making a placehoder for function tester.
void tester(string str);
//main function to run the program.
int main(int argc, char *argv[])
{
// if condition to check if the DNA elements matches.
	if (argc != 2 ) exit(EXIT_FAILURE);
	else
	{
	string builtstring(argv[1]);
	if (builtstring.empty()) exit(EXIT_FAILURE);
	else tester(builtstring);
  }
}
// function tester, to test the string.
void tester(string str) // testing the string
{
	string result;
	int length = str.length();
// loop which goes through the length of the list.
	for (int i = 0; i < length; i++)
	{
	// if condition to check the reverse compliment od DNA.
	  if(str[i]=='G') result = result + "C";
		else if (str[i]=='C') result = result + "G";
		else if (str[i]=='A') result = result + "T";
		else if (str[i]=='T') result = result + "A";
		else 	exit(EXIT_FAILURE);// exit the loop if user enters any thing else
	}
	//calling the reverse function
	reverse(result.begin(), result.end());
// printing out the result.
	cout << result << endl;
