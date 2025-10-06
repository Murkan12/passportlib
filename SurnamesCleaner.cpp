#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream in_surnames_file("./surnames_db/american_surnames_orig");
	std::ofstream out_surname_file("./surnames_db/american_surnames", std::ios_base::trunc);
	if (in_surnames_file.fail() || out_surname_file.fail())
	{
		return 1;
	}

	std::string line;
	while (std::getline(in_surnames_file, line))
	{
		char& last_char = line.back();
		if (last_char == ',')
		{
			line.pop_back();
		}

		out_surname_file << line << "\n";
	}
}