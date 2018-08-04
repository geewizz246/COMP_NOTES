// ----- PROBLEM : COUNT WORDS IN FILE -----
// After each line print the number of words in each line. 
// At the end, print the average word length.

#include <iostream>
#include <iomanip> // std::setpercision
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

std::vector<std::string> StringToVector(std::string line, char delim);

int main() {
	std::ofstream writeToFile;
	std::ifstream readFromFile;
	std::string txtToWrite = "";
	std::string txtFromFile = "";
	
	writeToFile.open("test.txt", std::ios_base::out | std::ios_base::trunc);
	if (writeToFile.is_open())
	{
		writeToFile << "Beginning of File";
		std::cout << "Enter data to write (Ctrl + Z to stop) : \n";
		while (getline(std::cin, txtToWrite))
		{
			writeToFile << "\n" << txtToWrite;
		}

		// Close the file
		writeToFile.close();
	}

	// Open the file for reading
	readFromFile.open("test.txt", std::ios_base::in);
	if (readFromFile)
	{
		int totalWords = 0,
			numOfLines = 0;
		double averageWords = 0.0;

		// Read text from file
		while (readFromFile.good())
		{
			getline(readFromFile, txtFromFile);

			std::vector<std::string> vec = StringToVector(txtFromFile, ' ');
			int numWords = vec.size();
			std::cout << txtFromFile << "   :   " 
				<< numWords << " words\n";

			totalWords += numWords;
			numOfLines++;
		}

		averageWords = (float)totalWords / (float)numOfLines;
		std::cout << "Average number of words per line : "
			<< std::setprecision(3) << averageWords << "\n";
		readFromFile.close();
	}


	return 0;
}

std::vector<std::string> StringToVector(std::string line, char delim)
{
	std::vector<std::string> words;
	std::stringstream ss(line);
	std::string str = "";
	
	while (getline(ss, str, delim))
	{
		words.push_back(str);
	}

	return words;
}

// ----- END PROBLEM : COUNT WORDS IN FILE -----