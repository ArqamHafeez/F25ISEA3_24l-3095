
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// function to load words from file
vector<string> loadwordsfromfile(const string& filename);

// function to choose a random word
string selectrandomword(const vector<string>& words);

// function to convert string to lowercase
void tolowercase(string& str);

// function to play one game of hangman
void playhangman(const string& secretword);

int main() {
    vector<string> words = loadwordsfromfile("words.txt");
    if (words.empty()) {
        cout << "error: could not load words or file is empty!\n";
        return 1;
    }

    string secretword = selectrandomword(words);
    tolowercase(secretword);
    playhangman(secretword);
}

vector<string> loadwordsfromfile(const string& filename) {
    ifstream file(filename);
    vector<string> words;
    string word;

    if (!file.is_open()) {
        cout << "error: could not open file: " << filename << endl;
        return words;
    }

    while (getline(file, word)) {
        if (!word.empty())
            words.push_back(word);
    }
    return words;
}

string selectrandomword(const vector<string>& words) {
    srand(time(0));
    return words[rand() % words.size()];
}

void tolowercase(string& str) {
    for (char& c : str) {
        if (c >= 'a' && c <= 'z')
            c += 32;
    }
}

void playhangman(const string& secretword) {
    string guessedword(secretword.size(), '_');
    vector<char> guessedletters;
    int mistakes = 0;
    const int maxmistakes = 7;

    cout << "\nwelcome to hangman game!\n";
    cout << "you have " << maxmistakes << " chances to guess the word.\n\n";

    while (mistakes < maxmistakes && guessedword != secretword) {
        cout << "word: " << guessedword << endl;
        cout << "guessed letters: ";
        for (char c : guessedletters) cout << c << ' ';
        cout << "\nremaining mistakes: " << (maxmistakes - mistakes) << endl;

        cout << "\nenter a letter: ";
        char guess;
        cin >> guess;
        if (guess >= 'a' && guess <= 'z') guess += 32;

        // already guessed check
        bool alreadyguessed = false;
        for (char c : guessedletters)
            if (c == guess) alreadyguessed = true;
        if (alreadyguessed) {
            cout << "you already guessed that letter!\n\n";
            continue;
        }

        guessedletters.push_back(guess);

        bool found = false;
        for (size_t i = 0; i < secretword.size(); ++i)
            if (secretword[i] == guess) {
                guessedword[i] = guess;
                found = true;
            }

        if (found) cout << "good guess!\n\n";
        else {
            mistakes++;
            cout << "wrong guess! remaining mistakes: "
                << (maxmistakes - mistakes) << "\n\n";
        }
    }

    if (guessedword == secretword)
        cout << "🎉 congratulations! you guessed the word: " << secretword << endl;
    else
        cout << "❌ you lost! the word was: " << secretword << endl;
}
