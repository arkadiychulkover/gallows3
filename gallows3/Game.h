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
public:
	Game(const shared_ptr<WordsManager> manager, unique_ptr<IGameView> view) : wordsBuilder(std::move(manager)), view(std::move(view)) {
		mistakes = 0;
	}

	void Start() {
		current_word = std::make_unique<GameWord>(wordsBuilder.GetRandomWord());
		view->DisplayMistakes(mistakes);
		int count = 0;

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
			}
			else
			{
				view->GameOver();
				break;
			}
		} while (!view->IsGameExit());
	}

	void End() {
		
	}


};

