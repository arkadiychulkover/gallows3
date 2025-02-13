#include<iostream>
#include"ConsoleGameView.h"
#include"WordsManager.h"
#include"Game.h"
#include<Windows.h>
#include"Cryptographer.h"

int main() {
	srand(time(0));

	try
	{
		WordsManager manager;
		ConsoleGameView consoleView;
		const auto var = std::make_shared<WordsManager>(manager);

		Game game(std::make_shared<WordsManager>(manager), std::make_unique<ConsoleGameView>(consoleView));
		game.Start();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}

	/*WordsManager manager;
	string testword = "banana";
	manager.Append(testword, 5);*/

	return 0;
}