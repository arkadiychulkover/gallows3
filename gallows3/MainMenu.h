#pragma once
#include<string>
#include<iostream>
#include<algorithm>
#include"WordsManager.h"
#include<fstream>
#include"Cryptographer.h"

class MainMenu
{
private:
	WordsManager manager;
	Cryptographer crypto;
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
		std::string temp;
		int space = 0;
		int afterSpace = 0;
		while (std::getline(input, records)) {
			for (char ch : records) {
				if (ch == ' ') {
					space++;
				}

				if (space == 1) {
					temp = crypto.Decrypt(temp, 5);
					if (afterSpace == 0)
					{
						std::cout << "Name: " << temp << " Words:";
						temp.clear();
					}
					afterSpace++;
				}

				temp += ch;
				if (afterSpace == 2)
					std::cout << temp << std::endl;
			}
			temp.clear();
			space = 0;
			afterSpace = 0;
		}
	}
};

