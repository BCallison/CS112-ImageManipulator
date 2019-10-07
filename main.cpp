#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{
	string file;

	ifstream inPix;
	inPix.open(file);
	string input_file;
	string line;
	string input_name;
	string output_file_name;
	int counter = 0;
	int max_color = 0;
	int image_effect = 0;


	//Getting source file
	cout << "What file would you like to open?" << endl;
	cin >> input_file;

	//Getting output file
	cout << "Enter destination file: " << endl;
	cin >> output_file_name;

	// Prompting for image effect wanted
	cout << "Enter the number associated with the desired image effect would you like?." << endl;
	cout << "1. Remove Red" << endl;
	cout << "2. Remove Blue" << endl;
	cout << "3. Remove Green" << endl;
	cout << "4. Negate Red" << endl;
	cout << "5. Negate Blue" << endl;
	cout << "6. Negate Green" << endl;
	cout << "7. Grayscale" << endl;
	cin >> image_effect;


	//Open the input file
	ifstream input{ input_file };

	//Open the output file
	ofstream output_file{ output_file_name };

	vector<string> lines{};
	if (input.is_open() == true)
	{
		while (input.good() == true)
		{
			string line;
			getline(input, line);
			lines.push_back(line);
		}
	}


	vector<int> vals{};
	for (int i = 3; i != lines.size(); i++)
	{
		string sentence = lines[i];
		istringstream iss(sentence);

		while(iss.good() == true)
		{
			int sub;
			iss >> sub;
			if (iss.fail() == false)
			{
				vals.push_back(sub);
			}
			
		} 
	}

	output_file << lines[0] << endl << lines[1] << endl << lines[2] << endl;

	//This effect removes red values from the image
	if (image_effect == 1)
	{
		for (int i = 0; i < vals.size(); i++)
		{
			if ((i + 0) % 3 == 0)
			{
				output_file << 0 << endl;
			}
			else
			{
				output_file << vals[i] << endl;
			}

		}
	}

	//This effect removes green values from the image
	if (image_effect == 2)
	{
		for (int i = 1; i < vals.size(); i++)
		{
			if ((i + 1) % 3 == 0)
			{
				output_file << 0 << endl;
			}
			else
			{
				output_file << vals[i] << endl;
			}

		}
	}

	//This effect removes blue values from the image
	if (image_effect == 3)
	{
		for (int i = 3; i < vals.size(); i++)
		{
			if ((i + 2) % 3 == 0)
			{
				output_file << 0 << endl;
			}
			else
			{
				output_file << vals[i] << endl;
			}

		}
	}
}