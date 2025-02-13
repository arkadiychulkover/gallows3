#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

class Cryptographer {
private:
    std::map<char, char> replacementMap = {
    {'a', 'm'}, {'b', 'n'}, {'c', 'o'}, {'d', 'p'}, {'e', 'q'},
    {'f', 'r'}, {'g', 's'}, {'h', 't'}, {'i', 'u'}, {'j', 'v'},
    {'k', 'w'}, {'l', 'x'}, {'m', 'y'}, {'n', 'z'}, {'o', 'a'},
    {'p', 'b'}, {'q', 'c'}, {'r', 'd'}, {'s', 'e'}, {'t', 'f'},
    {'u', 'g'}, {'v', 'h'}, {'w', 'i'}, {'x', 'j'}, {'y', 'k'},
    {'z', 'l'},
    {'A', 'M'}, {'B', 'N'}, {'C', 'O'}, {'D', 'P'}, {'E', 'Q'},
    {'F', 'R'}, {'G', 'S'}, {'H', 'T'}, {'I', 'U'}, {'J', 'V'},
    {'K', 'W'}, {'L', 'X'}, {'M', 'Y'}, {'N', 'Z'}, {'O', 'A'},
    {'P', 'B'}, {'Q', 'C'}, {'R', 'D'}, {'S', 'E'}, {'T', 'F'},
    {'U', 'G'}, {'V', 'H'}, {'W', 'I'}, {'X', 'J'}, {'Y', 'K'},
    {'Z', 'L'}
    };

    std::map<char, char> replacementDecryptMap = {
        {'m', 'a'}, {'n', 'b'}, {'o', 'c'}, {'p', 'd'}, {'q', 'e'},
        {'r', 'f'}, {'s', 'g'}, {'t', 'h'}, {'u', 'i'}, {'v', 'j'},
        {'w', 'k'}, {'x', 'l'}, {'y', 'm'}, {'z', 'n'}, {'a', 'o'},
        {'b', 'p'}, {'c', 'q'}, {'d', 'r'}, {'e', 's'}, {'f', 't'},
        {'g', 'u'}, {'h', 'v'}, {'i', 'w'}, {'j', 'x'}, {'k', 'y'},
        {'l', 'z'},
        {'M', 'A'}, {'N', 'B'}, {'O', 'C'}, {'P', 'D'}, {'Q', 'E'},
        {'R', 'F'}, {'S', 'G'}, {'T', 'H'}, {'U', 'I'}, {'V', 'J'},
        {'W', 'K'}, {'X', 'L'}, {'Y', 'M'}, {'Z', 'N'}, {'A', 'O'},
        {'B', 'P'}, {'C', 'Q'}, {'D', 'R'}, {'E', 'S'}, {'F', 'T'},
        {'G', 'U'}, {'H', 'V'}, {'I', 'W'}, {'J', 'X'}, {'K', 'Y'},
        {'L', 'Z'}
    };

    std::string temp;

public:
    std::string& Decrypt(const std::string& path, int key) {
        std::ifstream file(path);
        if (file) {
            char ch;
            while (file.get(ch)) {
                if (replacementDecryptMap.find(ch) != replacementDecryptMap.end())
                {
                    temp += replacementDecryptMap[ch - key];
                }
                else if (ch == '\n' || ch == ' ')
                {
                    temp += ch;
                }
                else
                {
                    temp += replacementDecryptMap[ch - key];
                }
            }
            std::cout << temp;
            return temp;
        }
        else
        {
            std::cout << "Can't open\n";
            return temp;
        }
    }

    std::string Decrypt(std::string& word, int key) {
        std::string tempik;
        for (char ch : word)
        {
            if (replacementDecryptMap.find(ch) != replacementDecryptMap.end())
            {
                tempik += replacementDecryptMap[ch - key];
            }
            else
            {
                tempik += replacementDecryptMap[ch - key];
            }
        }
        return tempik;
    }

    std::vector<std::string> Encrypt(std::vector<std::string>& words, int key) {
        std::vector<std::string> encryptedWords;
        
        for (auto& word : words) {
            std::string encryptedWord;
            for (auto& ch : word) {
                if (replacementMap.find(ch) != replacementMap.end()) {
                    encryptedWord += replacementMap[ch] + key;
                } else {
                    encryptedWord += ch + key;
                }
            }
            encryptedWords.push_back(encryptedWord);
        }
        for (const auto& word : encryptedWords) {
            std::cout << word << " ";
        }
        std::cout << std::endl;

        return encryptedWords;
    }

    std::string Encrypt(std::string& word, int key) {// не могу возвращать по ссылке оно логику ламает
        std::string tempik;
        for (char ch : word)
        {
            if (replacementMap.find(ch) != replacementMap.end())
            {
                tempik += replacementMap[ch] + key;
            }
            else
            {
                tempik += replacementMap[ch] + key;
            }
        }
        return tempik;
    }
};
