// Given specification file for the InvItem class

#ifndef INVITEM_H
#define INVITEM_H
#include <string>
using namespace std;

class InvItem
{
	private:
		long serialNum;			// Serial number
		string manufactDate;	// Manufacture date

	public:
		// Default constructor
		InvItem()
		{ 
			serialNum = 0;
			manufactDate = "";
		}

		// Constructor
		InvItem(long s, string m, int lot)
		{ 
			serialNum = s;
			manufactDate = m;
		}

		void setSerialNum(long s)
		{ 
			serialNum = s; 
		}

		void setManufactDate(string m)
		{ 
			manufactDate = m; 
		}

		long getSerialNum() const
		{ 
			return serialNum; 
		}

		string getManufactDate()
		{ 
			return manufactDate; 
		}
};

#endif