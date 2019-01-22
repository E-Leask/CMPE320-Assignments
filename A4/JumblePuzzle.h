#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>


typedef char* charArrayPtr;

using namespace std;

class BadJumbleException {					//Exceptions
public:
	BadJumbleException(const string& msg); 
	string what() const;
private:
	string message;
};

class JumblePuzzle {
public:
	charArrayPtr* getJumble() const;		// returns deep copy pointer
	int getSize() const;					// returns grid size
	int getRowPos() const;					// returns row of hidden word
	int getColPos() const;					// returns column of hidden word
	char getDirection() const;				// returns the direction the word faces up(n), down(s), left(w), right(e)

	JumblePuzzle();														// the default constructor
	JumblePuzzle(const JumblePuzzle& old);								// making a deep copy of a puzzle
	JumblePuzzle(const string& hiddenWord, const string& difficulty);	// With hiddenWord, make a puzzle with word hidden in it
	
	virtual ~JumblePuzzle();											// deletes the puzzle located on the heap

	JumblePuzzle& operator=(const JumblePuzzle& right);					// make a deep copy of a puzzle

private:
	char** jumble;
	char chDir;
	int size, col, row;
	
};

