/**
 * Line and Letter count
 * this program reads a text, outputs the text, and also prints
 * the number of lines and number of times each letter appears in
 * the text. An uppercase letter and lowercase letter are treated as
 * being the same, that is, they are tallied together.
 */

#include <iostream>
#include <fstream>
using namespace std;

// initializes the variables to 0
void initialize(int &lineCount, int letterCount[]);

// reads a line and outputs the line. after reading a char, it calls
// characterCount to update the letter count
void copyText(ifstream &intext, ofstream &outtext, char &ch, int letterCount[]);

// increments the letter count. it converts letter to uppercase, find index
// of the array corresponding to this letter, ignore non letters
void characterCount(char ch, int letterCount[]);

// outputs the line and letter count
void writeTotal(ostream &outtext, int lineCount, int letterCount[]);

int main()
{
	// declare variables
	int lineCount;
	int letterCount[26];
	char ch;
	ifstream infile;
	ofstream outfile;

	// open infile
	infile.open("textin.txt");

	// if it doesn't open, then it doesn't exist
	if (!infile)
	{
		cout << "Cannout open the input file.\n";
		return 1;
	}

	// open outfile
	outfile.open("textout.out");

	// initialize the variables
	initialize(lineCount, letterCount);

	// get the first character
	infile.get(ch);

	// while not at the end of input file
	while (infile)
	{
		// process the next line
		copyText(infile, outfile, ch, letterCount);
		lineCount++;	// increment the line count
		infile.get(ch); // read the next character
	}

	// output the line and letter counts
	writeTotal(outfile, lineCount, letterCount);

	// close files
	infile.close();
	outfile.close();

	return 0;
}

// initializes the variables to 0
void initialize(int &lineCount, int letterCount[])
{
	lineCount = 0;

	for (int index = 0; index < 26; index++)
	{
		letterCount[index] = 0;
	}
}

// reads a line and outputs the line. after reading a char, it calls
// characterCount to update the letter count
void copyText(ifstream &intext, ofstream &outtext, char &ch, int letterCount[])
{
	// go through the entire line of text
	while (ch != '\n')
	{
		outtext << ch;					 // output the character
		characterCount(ch, letterCount); // get the count
		intext.get(ch);					 // read next char
	}

	outtext << ch;
}

// increments the letter count. it converts letter to uppercase, find index
// of the array corresponding to this letter, ignore non letters
void characterCount(char ch, int letterCount[])
{
	int index;

	ch = toupper(ch); // converts all char to uppercase

	// find index of array that corresponds to the letter
	// static cast converts letter to integars
	index = static_cast<int>(ch) - static_cast<int>('A');

	// counts only letters
	if (0 <= index && index < 26)
	{
		letterCount[index]++; // increments count
	}
}

// outputs the line and letter count
void writeTotal(ostream &outtext, int lineCount, int letterCount[])
{
	outtext << endl;
	outtext << "The number of lines = " << lineCount << endl;

	for (int index = 0; index < 26; index++)
	{
		// outputs and converts the letter from integar to char
		outtext << static_cast<char>(index + static_cast<int>('A'))
				<< " count = " << letterCount[index] << endl;
	}
}