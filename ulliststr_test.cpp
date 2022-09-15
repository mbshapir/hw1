/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{

	ULListStr dat;
	dat.push_back("7");
	dat.push_front("8");
	dat.push_back("9");
	cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
	cout << dat.size() << endl; //was end in example instead of endl, should be a typo
	
  return 0;
}
