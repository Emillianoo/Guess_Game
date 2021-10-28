#include <iostream>
#include <ctime>

using namespace std;

void PrintIntroduction(int Difficulty)
{
	cout << "You are a secret agent breaking into a level " << Difficulty;
	cout << " secure server room .." << endl << "Enter the correct code to continue.." << endl;
}

bool PlayGame(int Difficulty) 
{
	PrintIntroduction(Difficulty);

	//Losuje losowe liczby dla naszej funkcji 
	const int CodeA = rand() % Difficulty + 1;
	const int CodeB = rand() % Difficulty + 1;
	const int CodeC = rand() % Difficulty + 1;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	//Print CodeSum and CodeProduct
	cout << "There are 3 numbers in the code" << endl;
	cout << "The codes add-up to: " << CodeSum << endl;
	cout << "The code multiply to give: " << CodeProduct << endl;

	// Store player guess
	int GuessA, GuessB, GuessC;
	cin >> GuessA;
	cin >> GuessB;
	cin >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	// Check if polayer win or lose
	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		cout << "Nice! You move to the next level" << endl << endl;
		return true;
	}

	else
	{
		cout << "Wasted! Restart level" << endl << endl;
		return false;
	}
}

int main()
{
	srand(time(NULL));// generuje losowe liczby w zale¿noœci od pory dnia

	int LevelDifficulty = 1;
	const int MaxLevel = 5;

	while (LevelDifficulty <= MaxLevel) //Loop game until all level completed
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		cin.clear(); //Clears any errors
		cin.ignore(); //Discards the buffer

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}
	cout << "Congratulation. YOU WIN!!!";

	return 0;
}