#pragma once
#include<string>
#include<vector>
#include"GameWord.h"
#include"WordsManager.h"

using std::shared_ptr;

class GameWordsBuilder
{
private:
	vector<string> buffer;
	shared_ptr<WordsManager> manager;
public:
	GameWordsBuilder(const shared_ptr<WordsManager>& manager) : manager(manager) {
		buffer = manager->GetWords();
	}

	GameWord GetRandomWord() {
		try {
			int rand_value = rand() % buffer.size();
			auto&& first = buffer[rand_value];

			GameWord result(first);

			auto bck = buffer.back();
			buffer.back() = buffer[rand_value];
			buffer[rand_value] = bck;

			buffer.pop_back();
			return result;
		}
		catch(const std::exception& e){
			throw "no more word";
		}
	}
};

