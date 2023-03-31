/*
 * Course: CS215-00x
 * Project: Lab 8 (as part of Project 2)
 * File: Nim.h
 * Purpose: it declares the class named Nim
 *
 */
#ifndef NIM_H
#define NIM_H
#include<iostream>
using namespace std;

const int PILE_MAX = 250;
const int PILE_MIN = 10;
const char MARBLE = static_cast<char>(232);  //use code 232 in ASCII Table to represent marble
const int WIDTH = 10;   // for layout purpose
const int PILE_SIZE_TEST = 50;		//the pile size for testing purpose in Lab8 only

class Nim
{
public:
	//default constructor
	Nim(){}

	//constructor
	Nim(int iniSize){
		pileSize=iniSize;
	}

	//set the current size of the pile 
	void setPileSize(int size){
		pileSize=size;
	}

	//get how many marbles on the pile
	int getPileSize() {return pileSize;};

	//if it is computer's turn to play
	//computer takes a legal move, and takes off some marbles
	//computer alwasys takes "perfect stategy" trying to win
	void computer_play(){
		 int min_take = 1;  // minimum number of marbles to take
    int max_take = pileSize / 2;  // 
		if(!is_power_of_two_minus_one(pileSize)){
			int largest_pow_two_minus_one = 1;
        while (largest_pow_two_minus_one <= pileSize) {
            largest_pow_two_minus_one = largest_pow_two_minus_one * 2 + 1;
        }
        largest_pow_two_minus_one = (largest_pow_two_minus_one - 1) / 2;

        // calculate the number of marbles to take off
        int take_off = pileSize - largest_pow_two_minus_one;
        pileSize = largest_pow_two_minus_one;

      std::cout<<"Computer takes off " << take_off << " marbles"<<endl;

		}
		else{
			int take_off = min_take + rand() % (max_take - min_take + 1);
        pileSize -= take_off;

       std::cout<< "Computer takes off " << take_off << " marbles"<<endl;
		}
	}

	//if it is human player's (the user's) turn to play
	//comment out in Lab8 only
	//you still need to define this member function in Project2
	//void player_play();

	//display the current marbles on the pile
	void print() { 
		
		std::cout<<"There are "<<pileSize<<" marbles in the pile"<<endl;};

	bool is_power_of_two_minus_one(int n) {
    if (n <= 0) {
        return false;
    }
    int m = n + 1;
    while (m % 2 == 0) {
        m /= 2;
    }
    return m == 1;
}

private:
	int pileSize;	// represents how many marbles on the 
};
#endif	/* NIM_H */
