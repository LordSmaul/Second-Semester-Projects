#include "markovList.h"

int main()
{
	markovList* chain = new markovList("corpus.txt");
	
	cout << chain->generate(100) << endl;
	return 0;
}