#pragma once
#include<iostream>
#include"IGameView.h"
class ConsoleGameView : public IGameView
{
	int mistakes;
public:
	void DisplayWord(const std::string& word) override {
		for (char letter : word) {
			if (letter == ' ')
			{
				std::cout << "_ ";
			}
			else
			{
				std::cout << letter << ' ';
			}
		}
		std::cout << std::endl;
	}
	void DisplayMistakes(int mistaked) override {
		std::cout << "|---" << '\n';
		std::cout << "| | " << '\n';
		std::cout << "| " << (mistaked > 0 ? "O" : " ") << '\n';
		std::cout << "|" << (mistaked > 1 ? "/" : " ") << (mistaked > 2 ? "|" : " ") << (mistaked > 3 ? "\\" : " ") << '\n';
		std::cout << "|" << (mistaked > 4 ? "/" : " ") << " " << (mistaked > 5 ? "\\" : " ") << '\n';
		std::cout << "|" << '\n';
		std::cout << "----- " << '\n';
		std::cout << "Mistakes(" << mistaked << "/6)" << '\n';
	}

	void DisplayMessage(const std::string& word) override {
		std::cout << "Display Message:" << word << '\n';
	}

	void WordGuessed() override {
		std::cout << "Word Guessed!!!" << '\n';
	}

	void GameOver() override {
		std::cout << "!!! GameOver !!!\n";
		system("pause");
	}

	bool IsGameExit() override {
		char input;
		while (true) {
			std::cout << "Do you wnat to exit? (y/n)";
			std::cin >> input;
			switch (input)
			{
			case 'y':
			case 'Y':
				return true;
				break;
			case 'n':
			case 'N':
				return false;
				break;
			default:
				system("cls");
				break;
			}
		}
	}

	/*void IsGuessedLetter(bool value) override {

	}*/

	char GatInputLatter() override {
		char input;
		std::cout << "input latter";
		std::cin >> input;
		return input;
	}
};


