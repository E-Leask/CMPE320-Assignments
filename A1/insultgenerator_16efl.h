#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

const int INSULT_MAX(10000);

class InsultGenerator {
public:

	string filename="InsultsSource.txt";
	list<string>	myList;
	vector<string> 	col1;
	vector<string> 	col2;
	vector<string>	col3;
	InsultGenerator();//Constructor
	//The initialize() method should load all the source phrases
	//from the InsultsSource.txt file into the attributes
	void initialize();
	//Opens file,outputs to three string vectors


	// talkToMe() returns a single insult, generated at random.
	string talkToMe();
	//random pick from each vector
	//return combined string

	// generate() generates the requested number of unique insults.
	vector<string> generate(const int numInsults);
	//call talkToMe for as many times as numInsults
	//move into set which orders and removes duplicates

	// generateAndSave() generates the requested number of unique insults and saves them to the filename
	//If the file cannot be written, the method should throw an exception.  
	// insults in the file should be in alphabetical order!
	void generateAndSave(const string& filename,const int numInsults);
	//call generate
	//store in file
};

class NumInsultsOutOfBounds {
public:
	NumInsultsOutOfBounds(const string&);
	string what() const;
private:
	string message;
}; 

class FileException {
public:
	FileException(const string&);
	string what() const;
private:
	string message;
};
