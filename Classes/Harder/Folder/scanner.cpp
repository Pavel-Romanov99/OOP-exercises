#include "Header.h"

Scanner::Scanner()
{
	this->paper_price = 100;
	this->paper_out = true;
}

Scanner::Scanner(int paper_price, bool paper_out)
{
	this->paper_price = paper_price;
	this->paper_out = paper_out;
}

void Scanner::Alert()
{
	if (this->paper_out)
	{
		cout << "Scanner is out of paper!" << endl;
	}
	else cout << "Scanner still has paper!" << endl;
}
