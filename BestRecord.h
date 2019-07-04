#pragma once
#include <fstream>
#include <sstream> 

class BestRecord
{
private:
	int _bestRecordSeconds; 
public:
	BestRecord() {
		std::string line;
		std::ifstream fs("../TEXTS/record.txt"); 
		getline(fs, line);

		_bestRecordSeconds= stoi(line);
		fs.close();

	}
	void setRecord(int x) {
		if (x > _bestRecordSeconds) {
			std::ofstream myfile("../TEXTS/record.txt");
			if (myfile.is_open())
			{
				std::string temp = std::to_string(x);
				myfile << temp;
				myfile.close();
			}
		}
	}
	int getRecord() {
		return _bestRecordSeconds;
	}
};

