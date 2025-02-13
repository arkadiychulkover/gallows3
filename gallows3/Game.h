#pragma once
#include"GameWord.h"
#include"GameWordsBuilder.h"
#include"IGameView.h"
#include<memory>

using std::unique_ptr;

class Game
{
private:
	unique_ptr<GameWord> current_word;
	int mistakes;
	GameWordsBuilder wordsBuilder;
	unique_ptr<IGameView> view;
	const int max_mistakes = 6;
	int players_count;
public:
	Game(const shared_ptr<WordsManager> manager, unique_ptr<IGameView> view) : wordsBuilder(std::move(manager)), view(std::move(view)) {
		mistakes = 0;
	}

	void Start() {
		current_word = std::make_unique<GameWord>(wordsBuilder.GetRandomWord());
		view->DisplayMistakes(mistakes);
		EnterName();
		//GetPlayersCount();
		int count = 0;
		int words_count = 0;

		do {
			if (count != 0)
				current_word = std::make_unique<GameWord>(wordsBuilder.GetRandomWord());
			count++;
			while (!current_word->IsGuessed() && mistakes < max_mistakes)
			{
				view->DisplayWord(current_word->GetExternal_word());
				char letter = view->GatInputLatter();
				if (!current_word->InputLetter(letter))
					++mistakes;
				
				view->DisplayMistakes(mistakes);
			}
			if (mistakes < max_mistakes)
			{
				view->WordGuessed();
				words_count++;
			}
			else
			{
				view->GameOver();
				SaveReecord(words_count);
				break;
			}
		} while (!view->IsGameExit());
	}

	void End() {
		
	}

	void EnterName() {
		std::string name;
		std::cout << "Enter your name: ";
		std::cin >> name;
		std::ofstream output("Records.txt", std::ios::app);
		if (output.is_open())
		{
			output << name << " ";
		}
	}

	void SaveReecord(int wordsCount) {
		std::ofstream output("Records.txt", std::ios::app);
		if (output.is_open())
		{
			output << wordsCount << std::endl;
		}
	}

	/*void GetPlayersCount() {
		std::cout << "Records" << std::endl;
		std::ifstream input("PlayersCount.txt");
		std::string records;
		std::getline(input, records);
		players_count = std::stoi(records);
	}*/
};

