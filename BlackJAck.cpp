//David Hu
//Lab 9.cpp
//October 29 2018
#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std;

string DealCard(int k[52], int b);
int ScoreHand ( int cardArray[52], int x);
int main (){



	srand(time(NULL));
		int players;

				
		int cardArray [52] = {0};
					
		string suit [4] = { "H", "D", "C", "S"}; 
		string faceValue [13] = { "A", "2" , "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

		string cardArr [52]; 

	for(int i = 0; i < 52; i ++){
	cardArr[i] = faceValue [i%13] + suit [i/13];
		}
	
		

		
		string card1;
		string card2;
		string card3;
		string card4;
		vector <string> dealer;
		vector <string > player;
		card1 = DealCard(cardArray, 1);
	
		dealer.push_back(card1);
		

		card2 = DealCard(cardArray, 1);
	
		dealer.push_back(card2);	
		
		card3 = DealCard(cardArray, 2);

		player.push_back(card3);

		card4 = DealCard(cardArray, 2);

		player.push_back(card4);

	int score1 = 0;
	int score2 = 0;
	string response;
	 
	

	
	//Deal the cards to the players
	cout << setw(20) << left <<"Dealer has cards: " << card1 << " " << card2 << " ";
	
	score1 = ScoreHand (cardArray, 1);
	cout <<  "(" << score1 << ")" << endl;
	cout << setw(20) << left << "You have cards: " << card3<< " " << card4 << " ";
	score2 = ScoreHand (cardArray,2);
	cout <<  "(" <<score2 << ")" << endl;
	
	
	

	cout << setw(20) << left << "Hit or Stand? ";
	cin >> response;
					

	while(!(response == "Stand" || response == "Hit")){
	
	cout << setw(20) << left << "Hit or Stand? ";
	cin >> response;

	}//Checks if the input is correct

do{	if(response == "Stand")
	break;
	if(score1 > 21)
	break;
	if (response == "Hit"){
	string x = DealCard(cardArray, 2);
	player.push_back(x);//Gives a card to player if hit is entered

										} 
	
	cout << setw(20) << left << "Dealer has cards: ";
	for (int i = 0; i < dealer.size(); i ++){
		cout << dealer.at(i) << " ";
	}
	cout <<"(" << score1 <<")" << endl;
									
	cout << setw(20) << left <<"You have cards: ";
	for (int i = 0; i < player.size(); i ++){
		cout << player.at(i) << " ";
													
		} 
	score2 = ScoreHand (cardArray, 2);
	if(score2 == 21){
	cout << "(" << score2 << ")" <<endl;
	cout << "Player wins!" << endl;
		return 5;
				}
	if (score2 > 21){
	cout <<"(" <<score2 << ")" << endl;
	cout << setw(20) << left << "Player busts, dealer wins!" << endl;
			return 7;
																					
	}
	cout << "(" << score2 << ")" << endl;
														
	cout << setw(20) << left << "Hit or Stand? ";
	cin >> response;
																
	while(!(response == "Stand" || response == "Hit")){

	cout << setw(20) << left << "Hit or Stand? ";
		cin >> response;

		}
}while (response == "Hit");//Keeps loop going if hit is repeatedly inputed



	if (response == "Stand"){
	while (score1 <= 18){
		cout << setw(20) << left << "Dealer hits: ";
	string y = DealCard(cardArray,1);
	dealer.push_back(y);
	score1 = ScoreHand(cardArray, 1);
	
		
	for(int i = 0; i < dealer.size(); i++)
		cout << dealer.at(i) << " ";
												        
	cout <<"(" << score1 << ")"<< endl;
	}
if(score1 > 21){
	cout<< "Dealer has busted, player wins!" << endl;
		return 5;
}
	
	
	
			
	if(score1 >18 && score1 < 21){
	cout << setw(20) << left << "Dealer stands: ";
	for (int i = 0; i < dealer.size(); i++)
		cout << dealer.at(i) << " ";
	cout << "(" << score1 << ")";
	 cout << endl;

	}




	if (score1 == 21){
		cout << "Dealer wins!" << endl;
		return 5;
	}//If dealer gets 21 points automatically wins
}	
		
	
	cout << setw(20) << left << "Dealer has cards: ";
		for (int i = 0; i < dealer.size(); i ++){
					cout << dealer.at(i) << " ";
						}
	cout <<"(" << score1 <<")" << endl;
										
		cout << setw(20) << left <<"You have cards: ";
			for (int i = 0; i < player.size(); i ++){
						cout << player.at(i) << " ";
																			
		}
	cout << "(" << score2 << ")" << endl;

if (score1 > 21 ){
		cout << setw(20) << left << "Dealer busts, player wins!" << endl;
	}
	if (score1 <= 21 && score2 <= 21){
		if(score1 < score2)
			cout << setw(20) << left << "Player wins!" <<endl;
		if (score1 > score2)
			cout <<  setw(20) << left <<"Dealer wins!" << endl;
		if (score1 == score2)
			cout <<  setw(20) << left <<"Player and dealer draw." << endl;

	}
}
	


int GetRandom ( int min, int max){
		
		return( min+rand() % (max - min + 1));
}

string DealCard (int cardArray[52], int  player){
	string suit [4] = { "H", "D", "C", "S"};
	string faceValue [13] = { "A", "2" , "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

	string cardArr [52];

	for(int i = 0; i < 52; i ++){
	cardArr[i] = faceValue [i%13] + suit [i/13];
								 }
	int randomNum;
							 
	randomNum = GetRandom(0, 51);

	while ( cardArray[randomNum] != 0)
		randomNum = GetRandom(0,51);
	
	cardArray[randomNum] = player;

	return cardArr[randomNum];
} 
int ScoreHand(int cardArray[52], int player){
int score = 0;	
	//for all cards
	for(int i = 0; i < 52 ; i++)
	{	if( cardArray[i] == player)
		{	if (i % 13 >= 10)
				score = score + 10;
		else
			score = score +( i % 13 + 1);
					}
		}
	return score;

}
