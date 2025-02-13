#pragma once
#include<string>
class IGameView
{
public:
	virtual ~IGameView() = default;
	virtual void DisplayWord(const std::string& word) = 0;
	virtual void DisplayMistakes(int mistaked) = 0;
	virtual void DisplayMessage(const std::string& word) = 0;
	virtual char GatInputLatter() = 0;
	virtual void WordGuessed() = 0;
	virtual void GameOver() = 0;
	virtual bool IsGameExit() = 0;
	//virtual void IsGuessedLetter(bool value) = 0;
};

