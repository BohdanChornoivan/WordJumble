#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] = { 
		{"wall", "Do you feel you're banding your head against something?"},
		{"glasses", "These might help you see the answer."},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it."},
		{"jumble", "It's what the game is all about."}
	};

	srand(static_cast<unsigned int>(time(0)));
	int choiceWord = (rand() % NUM_WORDS);
	string theWord = WORDS[choiceWord][WORD];
	string theHint = WORDS[choiceWord][HINT];

	cout << theWord;

	string jumble1 = theWord;
	int lengthWords = jumble1.size();
	for (int i = 0; i < lengthWords; ++i)
	{
		int index1 = (rand() % lengthWords);
		int index2 = (rand() % lengthWords);
		char temp = jumble1[index1];
		jumble1[index1] = jumble1[index2];
		jumble1[index2] = temp;
	}

	cout << "\t\tWelcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter 'hint' for a hint.\n";
	cout << "Enter 'quit' to quit the game.\n\n";
	cout << "The jumble is: " << jumble1 << "\n\n";
	cout << "Your quess: ";
	string quess;
	cin >> quess;
	unsigned int bonus = 0;
	int tries = 0;

	do
	{
		while ((quess != theWord) && (quess != "quit"))
		{
			if (quess == "hint")
			{
				cout << theHint << endl;
				if (bonus > 0) {
					bonus -= 1;
				}
			}
			else
			{
				cout << "Sorry, that's not it.";
			}
			cout << "\nYour quess: ";
			cin >> quess;
		}

		if (quess == theWord)
		{
			cout << "\nThat's it! You guessed it!\n";
			bonus += theWord.length();
			if (tries != 1)
			{
				cout << "\nYour quess: ";
				cin >> quess;
			}
		}
		if (tries == 1)
		{
			cout << "Your bonus: " << bonus;
			cout << "\nThanks for playing.\n";
		}

		tries++;

		if (quess == "quit")
		{
			break;
		}

	} while (tries != 2);


	return 0;
}