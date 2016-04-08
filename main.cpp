#include <iostream>
#include "Card.h"
using namespace std;

int main(int argc,char **argv)
{
	cout<<" wojna"<<endl;
	Card cards[52];
	for(int i=0;i<52;i++)
		cout<<cards[i].description()<<endl;
}