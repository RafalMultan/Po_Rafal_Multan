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
	int step_couter=0;
	while((player1.size()>0 && player2.size()>0))
	{
		if((*player1[0]).compare((player2[0]))==win)
			{
				(player1).push_back(player2[0]);
				player2.erase(player2.begin());
				player1.push_back(player1[0]);
				player1.erase(player1.begin());
				cout<<"w"<<player1.size()<<" "<<player2.size()<<endl;
			}
			else if((*player1[0]).compare((player2[0]))==lose)
			{
				(player2).push_back(player1[0]);
				player1.erase(player1.begin());
				player2.push_back(player2[0]);
				player2.erase(player2.begin());
				cout<<"l"<<player1.size()<<" "<<player2.size()<<endl;
			}
			else
				for(int i=0;i<player1.size() && i<player2.size();i+=2)
					{
						if((*player1[i]).compare((player2[i]))!=draw)
						{
							if((*player1[i]).compare((player2[i]))==win)
								{
									cout<<"dw";
									int how_many_to_delete=i;
									for(;i>=0;i--)
										{
											player1.push_back(player2[i]);
											player1.push_back(player1[i]);
										}
										player2.erase(player2.begin(),player2.begin()+how_many_to_delete+1);
										player1.erase(player1.begin(),player1.begin()+how_many_to_delete+1);	
										cout<<player1.size()<<" "<<player2.size()<<endl;	
										break;
								}
								else 
								{
									cout<<"dl";
									int how_many_to_delete=i;
									for(;i>=0;i--)
										{
											player2.push_back(player1[i]);
											player2.push_back(player2[i]);
										}
										player1.erase(player1.begin(),player1.begin()+how_many_to_delete+1);
										player2.erase(player2.begin(),player2.begin()+how_many_to_delete+1);
										cout<<player1.size()<<" "<<player2.size()<<endl;
										break;
								}
								
						}
						
					}
		++step_couter;

	}
	cout<<endl;
	if(player1.empty())cout<<"player2 has won"<<" in "<<step_couter<<" steps"<<endl;
	if(player2.empty())cout<<"player1 has won"<<" in "<<step_couter<<" steps"<<endl;
	
}