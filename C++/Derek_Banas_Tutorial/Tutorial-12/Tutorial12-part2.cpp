// ----- FILE I/O TUTORIAL -----

#include <iostream>
#include <string>

// iostream allows use to read from the standard 
// input (keyboard) and write to the standard output
// (console)
// fstream is needed for working with files
#include <fstream>

int main() {
	std::ofstream writeToFile;
	std::ifstream readFromFile;
	std::string txtToWrite = "";
	std::string txtFromFile = "";

	// We open the file by providing a name and then either
	// ios::app : Append to the end of the file
	// ios::trunc : If the file exists delete content
	// ios::in : Open file for reading
	// ios::out : Open file for writing
	// ios::ate : Open writing and move to the end of the file
	// ios::binary : Consider stream as binary rather than text

	// You can open a file in one or more of these modes at once
	// Open the file for reading. Delete any content if the file is found.
	writeToFile.open("test.txt", std::ios_base::out | std::ios_base::trunc);
	if (writeToFile.is_open()) // or if (writeToFile)
	{
		// You can write with the stream insertion operator
		writeToFile << "Beginning of File\n";
		std::cout << "Enter data to write : ";
		getline(std::cin, txtToWrite);
		writeToFile << txtToWrite << "\n";
		
		// Close the file
		writeToFile.close();
	}

	// Open the file for reading
	readFromFile.open("test.txt", std::ios_base::in);
	if (readFromFile)
	{
		// Read text from file

		// good() ====> returns true if none of the stream's error state flags are set:
		//		> eofbit - end-of-file reached on input operation
		//		> failbit - logical error on i/o operation
		//		> badbit - read/writing error on i/o operation
		while (readFromFile.good())
		{
			getline(readFromFile, txtFromFile);
			std::cout << txtFromFile << "\n";
		}

		readFromFile.close();
	}


	return 0;
}

// ----- END FILE I/O TUTORIAL -----