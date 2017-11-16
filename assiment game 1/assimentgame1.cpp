// assimentgame1.cpp : Defines the entry point for the console application.
//


//#includes 
#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string>
using namespace std;



//initilize variables

// p is for player 
// e is for enemy 
// player stats int 
int p_hp;
int p_max_hp =100;
int p_stamina;
int p_max_stamina = 50;
int p_stamina_regen = 10;
int p_attack = 10;
int p_super = 25;
int p_heal;
bool p_heal_useage;


// enemys stat int
int e_hp;
int e_max_hp = 70;
int e_attack = 10;
int e_hit_chance = 5;

// game bool
bool player_loop=true;
bool enemy_loop;
bool game_loop=false;
char start_menu;
int player_choice;
// hit chance 
int random_attack_chance;


// bool game loop 



int main()
{

	//ask player to start game
	string name;
	cout << "What is your name... beast? ";
	getline(cin, name);
	cout << "greetings " << name << "!\n";
	cout << "are you ready to fight your opponeit? y or n" << endl;
	cin >> start_menu;
	
	switch (start_menu)
	{
	case'y':
		game_loop = true;
		break;

	case'n':
			game_loop = false;
			break;

	default: cout << "you crazy?!?! I said y or n?" << endl;
		break;

	}

		p_hp += p_max_hp;
		p_stamina += p_max_stamina;
		e_hp += e_max_hp;


	//game loop start
	while (game_loop==true)
	{	
		
		cout << "player hp" << p_hp << endl;
		cout << "stamina" << p_stamina << endl;
		cout << "enemy hp" << e_hp << endl;
		
		cout << "1 = attack  " "2 = super  " "3 = dodge  " "4 = heal  " "5 = wait  " << endl;


		player_loop = true;

		while (player_loop==true)
		{
			

			srand((unsigned int)time(0));
			int random_number = rand();
			cin >> player_choice; 
			switch (player_choice)
			{
				//attack
			case 1:

				
			 random_attack_chance = (random_number % 10) + 1;

				if (random_attack_chance <= 8) 
				{
					e_hp -= p_attack;
					p_stamina += p_stamina_regen;
					cout << "you hit the enemy!!" << endl; // attack hit
					player_loop = false;
				}
				else
				{

					cout << "you missed!!" << endl; //attack missed 
					player_loop = false;

				}


				break;

				//super
			case 2:
				
				
				 random_attack_chance = (random_number % 10) + 1;

				if (random_attack_chance <= 5)
				{
					e_hp -= p_super;
					p_stamina -= p_max_stamina;
					cout << "super bankai... you hit" << endl; //super hit
					player_loop = false;
				
				
				}
				else
				{
					
					cout << "you missed" << endl; //super missed
					player_loop = false;

				}
				
				player_loop = false;
				break;


				//dodge
			case 3:

				e_hit_chance -= 3;
				p_stamina += p_stamina_regen/2;
				cout << "youve become faster and are able to dodge easyer" << endl;
				player_loop = false;
				break;

				//heal
			case 4:
				if(p_heal_useage == true)
				{
					p_hp += p_heal;
					p_heal = false;
					cout << "you healed 20 hp" << endl;
				}
				else

				{
					cout << "you cant heal again" << endl;

				}
				break;

				//wait
			case 5:
				e_hit_chance += 1;
				p_stamina += p_stamina_regen*4;
				cout << "you waited and recoverd stamina" << endl;
				
				player_loop = false;
				break;


			default: cout << "press one of the numbers" << endl;
				break;


			}

		
		}
	if (p_stamina > p_max_stamina)
			{
				p_stamina = p_max_stamina;
			
			}

		
		
		
	//enemy AI
			srand((unsigned int)time(0));
			int random_number = rand();
			int random_enemy_chance = (random_number % 10) + 1;
			
			if(random_enemy_chance > e_hit_chance)
			{
				p_hp -= e_attack;
				cout << "enemy hit you!!" << endl;
			}
			else 
			{
				cout << "enemy missed" << endl;
			}

			//creats a space
			cout << endl << endl;
			
			//win or lose state
			if (p_hp <= 0) {
				bool enemy_win = true;
				while (enemy_win) {
					
					cout << "gameover, you lose" << endl;
					getchar();
				}
			}
			else if (e_hp <= 0) {
				bool player_win = true;
				while (player_win) {
					cout << "you win!!" << endl;
					getchar();
				}
			}


			//run loop




	}



	//player loop



	//enemy loop



	// game loop end 
















    return 0;
}

