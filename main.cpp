#include "BTree.cpp"
#include "Dictionary.h"
#include "Couple.cpp"
#include<fstream>


int main()
{
	setlocale(0, "");

	Couple<string, Dictionary> cpl, cpl1;
	string word = "penguin";
	string word1 = "mango";
	Dictionary d, d1;

	//std::cin >> d >> d1;

	/*cpl.makeCouple(word, d);
	cpl1.makeCouple(word1, d1);*/

	BTree<Couple<string, Dictionary>> tree;
	std::ifstream in("Text.txt");
	
	while (!in.eof())
	{
		in >> word;
		in >> d;
		cpl.makeCouple(word, d);
		tree.add(cpl);
	}

	tree.print();

	/*std::cout << "Enter a word in english: ";
	std::cin >> word;*/

	cpl1.makeCouple(word, d);
	cpl1 = tree.find(cpl);
	std::cout << cpl1.second.translateRus() << std::endl;

	return 0;
}