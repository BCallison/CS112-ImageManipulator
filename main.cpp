#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>

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
	char image_effect = 0;
	int color_val = 0;
	int gray_val = 0;
	int count = 0;
	int randNum = 0;
	int randMin = -10;
	int randMax = 10;
	int true_input = 0;
	vector<int> output;


	//Getting source file
	cout << "What file would you like to open?" << endl;
	cin >> input_file;

	//Getting output file
	cout << "Enter destination file: " << endl;
	cin >> output_file_name;

	while (image_effect != 'Q')
	{
		// Prompting for image effect wanted
		cout << "Enter the number associated with the desired image effect would you like?." << endl;
		cout << "1. Remove Red" << endl;
		cout << "2. Remove Green" << endl;
		cout << "3. Remove Blue" << endl;
		cout << "4. Negate Red" << endl;
		cout << "5. Negate Green" << endl;
		cout << "6. Negate Blue" << endl;
		cout << "7. Grayscale" << endl;
		cout << "8. Add Noise" << endl;
		cout << "9. High Contrast" << endl;
		cout << "Q. Quit" << endl;


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

			while (iss.good() == true)
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
		if (image_effect == '1')
		{
			if (output.size() > 0)
			{
				vals = output;
				output.clear();
			}
			for (int i = 0; i < vals.size(); i++)
			{
				if ((i + 0) % 3 == 0)
				{
					output.push_back(0);
				}
				else
				{
					output.push_back(vals[i]);
				}

			}
		}

		//This effect removes green values from the image
		if (image_effect == '2')
		{
			if (output.size() > 0)
			{
				vals = output;
				output.clear();
			}
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
		if (image_effect == '3')
		{
			if (output.size() > 0)
			{
				vals = output;
				output.clear();
			}
			for (int i = 2; i < vals.size(); i++)
			{
				if ((i + 2) % 3 == 0)
				{
					output.push_back(0);
				}
				else
				{
					output.push_back(vals[i]);
				}

			}
		}

		// Negating Red
		if (image_effect == '4')
		{
			if (output.size() > 0)
			{
				vals = output;
				output.clear();
			}
			for (int i = 0; i < vals.size(); i++)
			{
				if ((i + 0) % 3 == 0)
				{
					color_val = 255 - vals[i];
					output.push_back(color_val);
				}
				else
				{
					output.push_back(vals[i]);
				}

			}
		}

		// Negating Green
		if (image_effect == '5')
		{
			if (output.size() > 0)
			{
				vals = output;
				output.clear();
			}
			for (int i = 1; i < vals.size(); i++)
			{
				if ((i + 1) % 3 == 0)
				{
					color_val = 255 - vals[i];
					output.push_back(color_val);
				}
				else
				{
					output.push_back(vals[i]);
				}

			}
		}

		// Negating Blue
		if (image_effect == '6')
		{
			if (output.size() > 0)
			{
				vals = output;
				output.clear();
			}
			for (int i = 2; i < vals.size(); i++)
			{
				if ((i + 2) % 3 == 0)
				{
					color_val = 255 - vals[i];
					output.push_back(color_val);
				}
				else
				{
					output.push_back(vals[i]);
				}

			}
		}

		// Grayscale
		if (image_effect == '7')
		{
			if (output.size() > 0)
			{
				vals = output;
				output.clear();
			}
			while (count <= 3)
			{
				for (int i = 0; i < vals.size(); i += 3)
				{
					gray_val = (vals[i] + vals[i + 1] + vals[i + 2]) / 3;
					output_file << gray_val << endl;
					output_file << gray_val << endl;
					output_file << gray_val << endl;
					count = count++;
				}

			}
		}
		//Adds Noise to the image

		if (image_effect == '8')
		{
			if (output.size() > 0)
			{
				vals = output;
				output.clear();
			}
			srand(time(0));
			randNum = rand() % (randMax - randMin + 1) + randMin;

			for (int i = 0; i < vals.size(); i++)
			{
				if (i % 3 == 0)
				{
					randNum = rand() % (randMax - randMin + 1) + randMin;
				}
				if ((vals[i] + randNum > 0) && (vals[i] + randNum < 255))
				{
					color_val = randNum + vals[i];
					output.push_back(color_val);

				}

				else if (vals[i] + randNum >= 255)
				{
					output.push_back(255);

				}

				else if (vals[i] + randNum <= 0)
				{
					output.push_back(0);

				}
			}

		}

		if (image_effect == '9')
		{
			if (output.size() > 0)
			{
				vals = output;
				output.clear();
			}
			for (int i = 0; i < vals.size(); i++)
			{
				if (vals[i] > (255 / 2))
				{
					output.push_back(255);

				}

				else
				{
					output.push_back(0);

				}
			}

		}


		// Quits program
		if (image_effect == 'Q')
		{
			for (int i = 0; i < output.size(); i++)
			{
				output_file << output[i] << endl;
			}
			return 0;
		}
	}
}
