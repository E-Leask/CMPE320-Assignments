#include "JumblePuzzle.h"

using namespace std;
int JumblePuzzle::getRowPos() const  //Getters
{
	return row;
}
int JumblePuzzle::getSize() const 
{
	return size;
}
int JumblePuzzle::getColPos() const 
{
	return col;
}
char JumblePuzzle::getDirection() const 
{
	return chDir;
}

JumblePuzzle::JumblePuzzle()  //Simple COnstructor
{
	size = 0;
	row = 0;
	col = 0;
	jumble = NULL;
	chDir = 0;
}

JumblePuzzle::JumblePuzzle(const string& hiddenWord, const string& difficulty) //Constructor with difficulty and word
{
	bool lowerCaseFlag=true; //CHANGE THIS IS YOU WANT TO SEE UPPERCASE WORDS			
	int s_inc, e_inc;
	int dir = rand() % 4;	
	string compass = "nesw";

	int south[4] = {-1, 0, 1, 0};
	int east[4] = {0, 1, 0, -1};

	chDir = compass[dir];
	s_inc = south[dir];
	e_inc = east[dir];

	string lowerWord = hiddenWord;
	int wordLength = lowerWord.length();
	if (wordLength < 3 || wordLength > 10) 
	{
        throw BadJumbleException("Choose word of length 3 to 10 letters long.");
	} 
	for (int i = 0; i < lowerWord.length(); i++) 
	{
		if (!isalpha(lowerWord[i])) 
		{
			throw BadJumbleException("Word must only include letters.");
		}
		if(lowerCaseFlag==true)
			lowerWord[i] = tolower(lowerWord[i]);
	}
	if (lowerWord == "fuck" || lowerWord == "shit" || lowerWord == "dick" || lowerWord == "cunt" || lowerWord == "kkk" || lowerWord == "penis" || lowerWord == "poop") {
		throw BadJumbleException("I bet you kiss your mother with that mouth, you sick fuck...");
	}
	if (difficulty == "hard") 
	{
		size = 4 * wordLength;
	} 
	else if (difficulty == "medium")
	{
		size = 3 * wordLength;
	} 
	else if (difficulty == "easy") 
	{
		size = 2 * wordLength;
	} 
	else 
	{
		throw BadJumbleException("Difficulty \"" + difficulty + "\"does not exist.\nDifficulties expected are easy, medium, or hard.");
	}

	col = rand() % (size - ( e_inc ? wordLength - 1 : 0)) + ( e_inc == -1 ? wordLength - 1 : 0);
	row = rand() % (size - (s_inc ? wordLength - 1 : 0)) + (s_inc == -1 ? wordLength - 1 : 0);
	
	int i, j;
	jumble = new charArrayPtr[size];

	for (i=0; i<size ; i++)
		jumble[i]= new char[size];
	for (i=0;i<size; i++) 
	{
		for (j=0; j<size; j++) {
			jumble[i][j] =rand() % 26+ 'a';
		}
	}

	j = col;
	i = row;
	int count;

	for (count = 0; count < wordLength; count++) 
	{
		jumble[i][j] = lowerWord[count];
		j += e_inc;
		i += s_inc;
	}
}

JumblePuzzle::JumblePuzzle(const JumblePuzzle& old) 
{
	int i, j;
	
	size = old.getSize();
	row = old.getRowPos();
	col = old.getColPos();
	chDir = old.getDirection();
	if (old.getJumble()) {
		jumble = new char*[size];
		for (i=0; i<size; i++)
			jumble[i] = new char[size];
		for (i=0; i<size; i++) 
		{
			for (j=0; j<size; j++) 
			{
				jumble[i][j] = old.getJumble()[i][j];
			}
		}
	}
}

JumblePuzzle& JumblePuzzle::operator=(const JumblePuzzle& puz) 
{
	if (this != &puz) {
		int i, j;
		for (i=size-1; i>=0; i--) {
			delete[] jumble[i];
		}
		delete[] jumble;

		row = puz.getRowPos();
		col = puz.getColPos();
		chDir = puz.getDirection();
		size = puz.getSize();
		

		if (puz.getJumble()) 
		{
			jumble = new char*[size];
			for (i=0; i<size; i++)
				jumble[i] = new char[size];

			for (i=0; i<size; i++) 
			{
				for (j=0; j<size; j++) 
				{
					jumble[i][j] = puz.getJumble()[i][j];
				}
			}
		}
	}
	return *this;
}

JumblePuzzle::~JumblePuzzle() 
{
	int i;
	for (i=size-1; i>=0; i--) 
	{
		delete[] jumble[i];
		jumble[i] = NULL;
	}
	delete[] jumble;
	jumble = NULL;
}

char** JumblePuzzle::getJumble() const 
{
	int i, j;
	char** replicatedJumble = new char*[size];
	for (i=0; i<size; i++)
		replicatedJumble[i] = new char[size];
	for (i=0; i<size; i++) 
	{
		for (j=0; j<size; j++) {
			replicatedJumble[i][j] = jumble[i][j];
		}
	}
	return replicatedJumble;
}

BadJumbleException::BadJumbleException(const string& msg) 
{
	 message = msg + '\n';
}

string BadJumbleException::what() const 
{
	return message;
}

