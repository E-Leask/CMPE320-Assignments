/* A demo of simple text file I/O */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;
#include "insultgenerator_16efl.h"
// Function prototypes.
// Allows you to implement functions in any order since they have already been identified, and
// provides a concise list of the functions in this program at the top of the source code.

InsultGenerator::InsultGenerator(){
	srand((unsigned)time(0));
}

void InsultGenerator::initialize(){
	int i=0;
	 //Get file
	ifstream fileIn(filename.c_str());
		string word;
		if (fileIn.fail()) {
			throw FileException("Insults source file can't be read.");
			return;
		}
			while (fileIn >> word) {//Store columns seperately
				if (i==0){
					col1.push_back(word);
				}else if (i==1){
					col2.push_back(word);
				}else if(i==2){
					col3.push_back(word);
				}
				i++;
				i=i%3;
				}
			fileIn.close();
}
string InsultGenerator::talkToMe(){
	string output;
	    int rand1,rand2,rand3;
	    int lowest=0, highest=49;
	    int range=(highest-lowest)+1;
	    rand1= lowest+int(range*rand()/(RAND_MAX + 1.0));
	    rand2= lowest+int(range*rand()/(RAND_MAX + 1.0));
	    rand3= lowest+int(range*rand()/(RAND_MAX + 1.0));
		output = "Thou " + col1[rand1];
		output += " " + col2[rand2];
		output += " " + col3[rand3];
		output+= "!";
	    return output;
}

vector<string> InsultGenerator::generate(int numInsults){
	string output;
	set<string> insultSet;
	
	if (numInsults < 1 || numInsults > INSULT_MAX){
		throw NumInsultsOutOfBounds("Non valid num of insults. Range: 1-10,000");
	}
		while (insultSet.size()<numInsults){
			output=talkToMe();
			insultSet.insert(output);
		}
		vector<string> myVector(insultSet.begin(), insultSet.end());
		return myVector;
}

void InsultGenerator::generateAndSave(const string& filename, int numInsults){
	vector <string> insultVector = generate(numInsults);
	ofstream fileOut(filename.c_str());
	if (fileOut.fail()) {
		throw FileException(filename + " can't be written to");
	}
	vector<string>::const_iterator i;
	for( i = insultVector.begin(); i != insultVector.end(); ++i)
		fileOut << *i << endl;
	fileOut.close();
}
NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& m) : message(m) {} 
FileException::FileException(const string& m) : message(m) {}
string NumInsultsOutOfBounds::what() const {
	return message;
} 
string FileException::what() const {
	return message;
}
