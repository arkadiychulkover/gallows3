#pragma once
#include<string>
#include<iostream>
#include<algorithm>
#include"WordsManager.h"

class MainMenu
{
private:
	WordsManager manager;
public:
	int Menu() {
		std::cout << "Gallow!" << std::endl;
		std::cout << "1. New Game" << std::endl;
		std::cout << "2. Records" << std::endl;
		std::cout << "3. Exit" << std::endl;
		std::cout << "4. Settings" << std::endl;
		std::cout << "Enter: ";
		int choise;
		std::cin >> choise;
		return choise;
	}

	void Settings() {
		std::cout << "Settings" << std::endl;
		std::cout << "Do You want to Append word (y/n)" << std::endl;
		std::cout << "Enter: ";
		char input;
		while (true) {
			std::cin >> input;
			if (input == 'y') {
				std::cout << "Enter word: ";
				std::string word;
				std::cin >> word;
				manager.Append(word, 5);
				char a;
				std::cout << "enter letter to menu";
				std::cin >> a;
				break;
			}
			else if (input == 'n') {
				break;
			}
			else {
				std::cout << "Invalid input" << std::endl;
			}
		}
	}

	void Records() {
		std::cout << "Records" << std::endl;
		std::ifstream input("Records.txt");
		std::string records;
		while (std::getline(input, records)) {
			std::cout << records << std::endl;
		}
	}
};

