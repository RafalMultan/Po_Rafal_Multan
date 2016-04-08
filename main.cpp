#include <iostream>
#include "Card.h"
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
using namespace std;


int main(int argc,char **argv)
{
	cout<<" wojna"<<endl;
	Card cards[52];
	random_device rd;
	default_random_engine generator(rd());
	shuffle(cards,cards+52,generator);
	for(int i=0;i<52;i++)
		cout<<cards[i].description()<<endl;
	
	std::vector<Card*> player1;
	std::vector<Card*> player2;
	int j=0;
	for(int i=52;i>0;i--)
	{
		player1.push_back(&cards[i--]);
		player2.push_back(&cards[i]);
		
	}
	cout<<player1.size()<<" "<<player2.size()<<endl;
	for(int i=0;i<26;i++)
		cout<<player1[i]->description()<<" "<<player2[i]->description()<<endl;
	//while(!(player1.empty() || player2.empty()))
	//{
		if((*player1[0]).compare((player2[0]))==win)
			{
				(player1).push_back(player2[0]);
				player2.erase(player2.begin());
			}
			else if((*player1[0]).compare((player2[0]))==lose)
			{
				(player2).push_back(player1[0]);
				player1.erase(player1.begin());
			}
				
			//else
			//	for(int i=1;i<=player1.size();i++)
			//		if((*player1[i]).compare((player2[i]))!=)
	//}
	
}