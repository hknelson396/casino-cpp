#include <iostream>
#include <ctime>

using namespace std;

// This code was written by Hunter Nelson for a project at The University of Alabama.

int money = 50;
int max = 300;
int gameType;
void playGames();
void playSlots();
void playDice();
void playRoulette();
const string arrayReels[6] = { "Elephant", "Computer", "Football", "Resume", "Capstone", "Crimson" };
const int arrayDice[6] = { 1, 2, 3, 4, 5, 6 };
const int arrayRoulette[37] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36 };
int main()
{
	cout << "Welcome you have " << money << " gils." << endl;
	playGames();
	system("pause");
	return 0;
}
// Function for options of games to play.
void playGames() {
	cout << "Type 1 for slots, 2 for dice, or 3 for Roulette." << endl;
	cin >> gameType;
	if (gameType == 1) {
		playSlots();
	}
	else if (gameType == 2) {
		playDice();
	}
	else if (gameType == 3) {
		playRoulette();
	}
	else {
		cout << "Invalid response." << endl;
		playGames();
	}
}
// Function for asking how much you want to bet.
int getBet() {
	int bet = 0;
	cout << "How much would you like to bet?" << endl;
	cin >> bet;
	if (bet <= 0) {
		cout << "Please enter an amount greater than 0." << endl;
		bet = getBet();
	}
	else if (bet > money) {
		cout << "You don't have that much money." << endl;
		bet = getBet();
	}
	return bet;
}
// Function for whether you want to play again or not.
int optionsPlay() {
	int options;
	cout << "To play again type 1 to return to menu type 2." << endl;
	cin >> options;
	if (options != 1 && options != 2) {
		cout << "Please enter a valid value." << endl;
		optionsPlay();
	}
	return options;
}
// Function for Slot Machine Game.
void playSlots()
{
	int options;
	int mybet = 0;
	cout << "Welcome to slots." << endl;
	cout << "Jackpot (3/1 Payout) = 3 words match." << endl;
	cout << "(2/1 Payout) = 2 words match." << endl;
	cout << "If none of the words match then you lose." << endl;
	cout << "You currently have " << money << " gils." << endl;
	mybet = getBet();
	string reelOne;
	string reelTwo;
	string reelThree;
	int randIndex = rand() % 6;
	reelOne = arrayReels[randIndex - 1];
	randIndex = rand() % 6;
	reelTwo = arrayReels[randIndex - 1];
	randIndex = rand() % 6;
	reelThree = arrayReels[randIndex - 1];
	if (reelOne == reelTwo && reelThree == reelTwo) {
		money = (money - mybet) + (3 * mybet);
		cout << "You have won jackpot and now have " << money << " gils." << endl;
	}
	else if (reelOne == reelTwo || reelOne == reelThree || reelTwo == reelThree) {
		money = (money - mybet) + (2 * mybet);
		cout << "You have won and now have " << money << " gils." << endl;
	}
	else {
		money = (money - mybet);
		cout << "You have lost. You now have " << money << " gils." << endl;
	}
	if (money <= 0) {
		cout << "Sorry you are out of money press any key to exit." << endl;
		system("pause");
		exit(0);
	}
	else if (money >= 300) {
		cout << "Congrats you have enough money to pay rent. Press any key to exit." << endl;
		system("pause");
		exit(0);
	}
	options = optionsPlay();
	if (options == 1) {
		playSlots();
	}
	else {
		playGames();
	}
}
// Function for guessing your number for dice.
int diceGuess() {
	int myguess = 0;
	cout << "Please enter your guess between 5 and 30." << endl;
	cin >> myguess;
	if (myguess < 5 || myguess > 30) {
		cout << "Please guees a value between 5 and 30" << endl;
		myguess = diceGuess();
	}
	else {
		return myguess;
	}
}
// Funtion for rolling the dice.
bool rollDice(int myGuess) {
	int diceOne;
	int diceTwo;
	int diceThree;
	int diceFour;
	int diceFive;
	int sumNum = 0;
	system("pause");
	int randIndex = rand() % 6;
	diceOne = arrayDice[randIndex - 1];
	randIndex = rand() % 6;
	diceTwo = arrayDice[randIndex - 1];
	randIndex = rand() % 6;
	diceThree = arrayDice[randIndex - 1];
	randIndex = rand() % 6;
	diceFour = arrayDice[randIndex - 1];
	randIndex = rand() % 6;
	diceFive = arrayDice[randIndex - 1];
	sumNum = diceOne + diceTwo + diceThree + diceFour + diceFive;
	cout << "Dice total was " << sumNum << " ." << "Your Guess was " << myGuess << " ." << endl;
	if (myGuess == sumNum) {
		money = (money - 3) + 50;
		return true;
	}
	else
	{
		money = money - 3;
		return false;
	}
}
// Function for the Dice Game.
void playDice()
{
	int options = 0;
	int maxtries = 4;
	int tried = 1;
	int guess;
	int diceSum = 0;
	cout << "Pick a number between 5-30." << endl;
	cout << "If the sum of the dice is the same number as the number" << endl;
	cout << "you guessed then you win." << endl;
	cout << "You get 4 tries and each guess is worth 3 gils." << endl;
	cout << "You currently have " << money << " gils." << endl;
	guess = diceGuess();
	while (!rollDice(guess) && tried < maxtries)
	{
		tried++;
		cout << "Your guess was not correct." << endl;
		if (money <= 0) {
			cout << "Sorry you are out of money press any key to exit." << endl;
			system("pause");
			exit(0);
		}
		else if (money >= 300) {
			cout << "Congrats you have enough money to pay rent. Press any key to exit." << endl;
			system("pause");
			exit(0);
		}
		cout << "You have " << maxtries - tried + 1 << " tries left." << endl;
		cout << "You now have " << money << " gils." << endl;
	}
	if (tried >= maxtries)
	{
		if (money <= 0) {
			cout << "Sorry you are out of money press any key to exit." << endl;
			system("pause");
			exit(0);
		}
		else if (money >= 300) {
			cout << "Congrats you have enough money to pay rent. Press any key to exit." << endl;
			system("pause");
			exit(0);
		}
		cout << "You are out of tries what would you like to do now?" << endl;
		if (options == 1) {
			playDice();
		}
		else {
			playGames();
		}
	}
	if (rollDice(guess) && tried < maxtries)
	{
		cout << "You guessed correctly you have won 50 gils." << endl;
		cout << "You now have " << money << " gils." << endl;
		options = optionsPlay();
		if (options == 1) {
			playDice();
		}
		else {
			playGames();
		}
	}
}
// Function for Roulette Game.
void playRoulette() {
	int colorGuess;
	int colorResults = 0;
	int green = 3;
	int black = 2;
	int red = 1;
	int wheelOne;
	int options;
	int betAmount = 0;
	cout << "Please enter 1 to guess Red, 2 to guess Black, or 3 to guess Green." << endl;
	cin >> colorGuess;
	if (colorGuess == 1) {
		colorGuess = red;
	}
	else if (colorGuess == 2) {
		colorGuess = black;
	}
	else if (colorGuess == 3) {
		colorGuess = green;
	}
	else {
		cout << "Invalid data." << endl;
	}
	betAmount = getBet();
	int randIndex = rand() % 37;
	wheelOne = arrayRoulette[randIndex - 1];
	cout << "The number rolled was " << wheelOne << " ." << endl;
	if (wheelOne == 0)
	{
		cout << "The color is green." << endl;
		colorResults = 3;
	}
	else if (wheelOne == 1 || wheelOne == 3 || wheelOne == 5 || wheelOne == 7 || wheelOne == 9 || wheelOne == 12 || wheelOne == 14 || wheelOne == 16 || wheelOne == 18 || wheelOne == 19 || wheelOne == 21 || wheelOne == 23 || wheelOne == 25 || wheelOne == 27 || wheelOne == 30 || wheelOne == 32 || wheelOne == 34 || wheelOne == 36)
	{
		cout << "The color is red.";
		colorResults = 1;
	}
	else if (wheelOne == 2 || wheelOne == 4 || wheelOne == 6 || wheelOne == 8 || wheelOne == 10 || wheelOne == 11 || wheelOne == 13 || wheelOne == 15 || wheelOne == 17 || wheelOne == 20 || wheelOne == 22 || wheelOne == 24 || wheelOne == 26 || wheelOne == 28 || wheelOne == 29 || wheelOne == 31 || wheelOne == 33 || wheelOne == 35)
	{
		cout << "The color is black.";
		colorResults = 2;
	}
	else
	{
		cout << "Invalid Data.:";
	}
	if (colorResults == colorGuess)
	{
		money = (money - betAmount) + (betAmount * 2);
		cout << "You have won and now have " << money << " gils." << endl;
	}
	else
	{
		money = (money - betAmount);
		cout << "You have lost and now have " << money << " gils." << endl;
	}
	if (money <= 0) {
		cout << "Sorry you are out of money press any key to exit." << endl;
		system("pause");
		exit(0);
	}
	else if (money >= 300) {
		cout << "Congrats you have enough money to pay rent. Press any key to exit." << endl;
		system("pause");
		exit(0);
	}
	options = optionsPlay();
	if (options == 1) {
		playRoulette();
	}
	else {
		playGames();
	}
}
