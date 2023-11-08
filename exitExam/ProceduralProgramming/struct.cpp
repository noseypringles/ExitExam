/**
 * this program processes sales data for a company. for each
 * salesperson, it outputs the ID, the total sales by each quarter,
 * and the total sales for the year. it also outputs the salesperson's
 * ID generating the maxium sale for the year and the sales amount.
 * The quarter generating the maxium sale and the sales amount is also output.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int NO_OF_SALES_PERSON = 6;

struct salesPersonRec
{
	string ID;
	double saleByQuarter[4];
	double totalSale;
};

void initialize(ifstream &indata, salesPersonRec list[], int listSize);

void getData(ifstream &infile, salesPersonRec list[], int listSize);

void saleByQuarter(salesPersonRec list[], int listSize, double totalByQuarter[]);

void totalSaleByPerson(salesPersonRec list[], int listSize);

void printReport(ofstream &outfile, salesPersonRec list[], int listSize,
				 double saleByQuarter[]);

void maxSaleByPerson(ofstream &outData, salesPersonRec list[], int listSize);

void maxSaleByQuarter(ofstream &outData, double saleByQuarter[]);

int main()
{
	// variables
	ifstream infile;
	ofstream outfile;
	string inputFile;
	string outputFile;

	double totalSaleByQuarter[4]; // array to hold sale by quarter

	salesPersonRec salesPersonList[NO_OF_SALES_PERSON]; // hold person's data

	cout << "Enter the salesPerson ID file name: ";
	cin >> inputFile;
	cout << endl;

	infile.open(inputFile.c_str());

	if (!infile)
	{
		cout << "Cannot open the input file.\n";
		return 1;
	}

	initialize(infile, salesPersonList, NO_OF_SALES_PERSON);

	infile.close();
	infile.clear();

	cout << "Enter the sales data file name: ";
	cin >> inputFile;
	cout << endl;

	infile.open(inputFile.c_str());

	if (!infile)
	{
		cout << "Cannot open the input file.\n";
		return 1
	}

	cout << "Enter the output file name: ";
	cin >> outputFile;
	cout << endl;

	outfile.open(outputFile.c_str());

	outfile << fixed << showpoint << setprecision(2);

	getData(infile, salesPersonList, NO_OF_SALES_PERSON);

	saleByQuarter(salesPersonList, NO_OF_SALES_PERSON, totalSaleByQuarter);

	totalSaleByPerson(salesPersonList, NO_OF_SALES_PERSON);

	printReport(outfile, salesPersonList, NO_OF_SALES_PERSON, totalSaleByQuarter);

	maxSaleByPerson(outfile, salesPersonList, NO_OF_SALES_PERSON);

	maxSaleByQuarter(outfile, totalSaleByQuarter);

	infile.close();
	outfile.close();

	return 0;
}

// reads the ID from inputFile and stores the ID in array. initializes the sales to 0
void initialize(ifstream &indata, salesPersonRec list[], int listSize)
{
	for (int index = 0; index < listSize; index++)
	{
		indata >> list[index].ID; // gets the ID

		for (int quarter = 0; quarter < 4; quarter++)
		{
			list[index].saleByQuarter[quarter] = 0.0;
		}

		list[index].totalSale = 0.0;
	}
}

// reads the sales data from the input file and stores info in salesPersonList
void getData(ifstream &infile, salesPersonRec list[], int listSize)
{
	// list variables
	int index;	   // to curr pos in listSize
	int quarter;   // determines which quarter of year we are in
	string sID;	   // ID stored as a string
	int month;	   // month in the quarter
	double amount; // amount of sales

	infile >> sID;

	while (infile)
	{
		infile >> month >> amount;

		for (index = 0; index < listSize; index++)
		{
			if (sID == list[index].ID)
			{
				break;
			}
		}

		if (1 <= month && month <= 3)
		{
			quarter = 0;
		}

		else if (4 <= month && month <= 6)
		{
			quarter = 1;
		}

		else if (7 <= month && month <= 9)
		{
			quarter = 2;
		}

		else
			quarter = 3;

		if (index < listSize)
		{
			list[index].saleByQuarter[quarter] += amount;
		}

		else
		{
			cout << "Invalid salesperson's ID.\n";
		}

		infile >> sID;
	}
}

// finds the company's total sales for each quarter
void saleByQuarter(salesPersonRec list[], int listSize, double totalByQuarter[])
{
	for (int quarter = 0; quarter < 4; quarter++)
	{
		totalByQuarter[quarter] = 0.0;
	}

	for (int quarter = 0; quarter < 4; quarter++)
	{
		for (int index = 0; index < listSize; index++)
		{
			totalByQuarter[quarter] += list[index].saleByQuarter[quarter];
		}
	}
}

// finds each salesperson's yearly sales amount
void totalSaleByPerson(salesPersonRec list[], int listSize)
{
	for (int index = 0; index < listSize; index++)
	{
		for (int quarter = 0; quarter < 4; quarter++)
		{
			list[index].totalSale += list[index].saleByQuarter[quarter];
		}
	}
}

// prints the annual report
void printReport(ofstream &outfile, salesPersonRec list[], int listSize,
				 double saleByQuarter[])
{
	outfile << "----------- Annual Sales Report -------------" << endl;
	outfile << "  ID        QT1        QT2        QT3        QT4         Total"
			<< endl;
	outfile << "_____________________________________________________________\n";

	for (int index = 0; index < listSize; index++)
	{
		outfile << list[index].ID << "    ";

		for (int quarter = 0; quarter < 4; quarter++)
		{
			outfile << setw(10) << list[index].saleByQuarter[quarter];
		}

		outfile << setw(10) << list[index].totalSale << endl;
	}

	outfile << "Total   ";

	for (int quarter = 0; quarter < 4; quarter++)
	{
		outfile << setw(10) << saleByQuarter[quarter];
	}

	outfile << endl
			<< endl;
}

// prints the name of the salesperson who produces max sales amount
void maxSaleByPerson(ofstream &outData, salesPersonRec list[], int listSize)
{
	int maxIndex = 0;

	for (int index = 1; index < listSize; index++)
	{
		if (list[maxIndex].totalSale < list[index].totalSale)
		{
			maxIndex = index;
		}
	}

	outData << "Max Sale by SalesPerson: ID = " << list[maxIndex].ID
			<< ", Amount = $" << list[maxIndex].totalSale << endl;
}

// prints the quarter in which max sales were made
void maxSaleByQuarter(ofstream &outData, double saleByQuarter[])
{
	int maxIndex = 0;

	for (int quarter = 0; quarter < 4; quarter++)
	{
		if (saleByQuarter[maxIndex] < saleByQuarter[quarter])
		{
			maxIndex = quarter;
		}
	}
	
	outData << "Max Sale by Quarter: Quarter = " << maxIndex + 1
			<< ", Amount = $" << saleByQuarter[maxIndex] << endl;
}