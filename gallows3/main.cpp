#include<iostream>
#include"ConsoleGameView.h"
#include"WordsManager.h"
#include"Game.h"
#include<Windows.h>
#include"Cryptographer.h"
#include"MainMenu.h"

int main() {
	srand(time(0));

	try
	{
		WordsManager manager;
		MainMenu menu;
		ConsoleGameView consoleView;
		const auto var = std::make_shared<WordsManager>(manager);

		while (true) {
			Game game(std::make_shared<WordsManager>(manager), std::make_unique<ConsoleGameView>(consoleView));
			switch (menu.Menu())
			{
			case 1:
				game.Start();
				break;
			case 2:
				menu.Records();
				break;
			case 3:
				return 0;
				break;
			case 4:
				menu.Settings();
				break;
			default:
				break;
			}
		}
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