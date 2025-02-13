#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Cryptographer.h"

using std::vector;
using std::string;

class WordsManager
{
private:
	std::vector<string> words;
	Cryptographer crypto;
public:
	WordsManager() {
		Load(5);
	}

	const vector<string>& GetWords() const {
		return words;
	}


	void Save(int key) {
		std::ofstream output("words.txt");
		if (output.is_open())
		{
			std::vector<std::string> Words;
			Words = crypto.Encrypt(words, key);

			for (auto& word : Words) {
				output << word << std::endl;
			}
		}
	}

	void Load(int key) {
		std::ifstream input("words.txt");
		std::string word;
		while (std::getline(input, word)) {
			if (!word.empty()) {
				std::string decryptedWord = crypto.Decrypt(word, key);
				words.push_back(decryptedWord);
			}
		}
	}


	void Append(string& word, int key) {
		std::ofstream output("words.txt", std::ios::app);
		if (output.is_open()) {
			output << std::endl << crypto.Encrypt(word, key);
		}
	}

	std::vector<string>& GetWords() {
		return words;
	}
};