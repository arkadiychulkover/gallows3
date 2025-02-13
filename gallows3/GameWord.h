#pragma once
#include<string>
#include<iostream>
#include<algorithm>

class GameWord
{
private:
	std::string hiden_word;
	std::string external_word;
public:
	GameWord(std::string& word) : hiden_word(word) {
		auto len = word.length();
		std::string str;
		str.insert(0, word.length(), ' ');
		external_word.append(str);
	}

	bool InputLetter(char letter) {
		bool flag = false;
		for (size_t i = 0; i < hiden_word.length(); i++)
		{
			if (hiden_word[i] == letter) {
				external_word[i] = letter;
				flag = true;
			}
		}
		return flag;
	}

	std::string& GetExternal_word() {
		return external_word;
	}

	bool IsGuessed() const {
		return hiden_word == external_word;
	}
};

