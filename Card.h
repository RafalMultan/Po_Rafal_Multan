#pragma once
#include <string>
using namespace std;
enum result{win='w',lose='l',draw='d'};
class Card
{
	int figure;
	int colour;
	static int counter;
public:
	result compare(Card *);
	Card();
	string description();
};