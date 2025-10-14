#include "NamesDatabase.h"

namespace Passportlib
{
	NamesDatabase::NamesDatabase(Nationality n)
	{
		std::string nationality_selector;
		switch (n)
		{
			case Nationality::AMERICAN:
				nationality_selector = "american";
				break;

			default:
				throw std::runtime_error("Nationality not implemented");
		}

		build_file_path(male_names_file, nationality_selector, "male");
		build_file_path(female_names_file, nationality_selector, "female");
		build_file_path(surnames_file, nationality_selector, "surnames");

		male_names_count = count_names(male_names_file);
		female_names_count = count_names(female_names_file);
		surnames_count = count_names(surnames_file);
	}

	void NamesDatabase::build_file_path(std::string& file_path, std::string nationality_selector, std::string suffix)
	{
		file_path = std::string {db_root} + nationality_selector + "/" + nationality_selector + "_" + suffix;
	}

	int NamesDatabase::get_male_names_count()
	{
		return male_names_count;
	}

	int NamesDatabase::get_female_names_count()
	{
		return female_names_count;
	}

	int NamesDatabase::get_surnames_count()
	{
		return surnames_count;
	}

	std::string NamesDatabase::get_name_from_index(int index, NameFlag flag)
	{
		if (index <= 0)
		{
			throw std::runtime_error("The value of index must be positive");
		}

		std::string file_name;

		switch (flag)
		{
			case NameFlag::MALE:
				file_name = male_names_file;
				break;
			case NameFlag::FEMALE:
				file_name = female_names_file;
				break;
			case NameFlag::SURNAME:
				file_name = surnames_file;
				break;
			default:
				throw std::runtime_error("Unsupported NameFlag");
		}

		std::ifstream names_file(file_name);

		if (names_file.fail())
		{
			throw std::runtime_error("The name file stream could not be opened!");
		}

		names_file.seekg(std::ios::beg);
		for (int i = 1; i < index; i++)
		{
			names_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		if (names_file.fail())
		{
			throw std::runtime_error("The provided index (" + std::to_string(index) + ") could not be extracted!");
		}

		std::string name;
		names_file >> name;

		return name;
	}

	int NamesDatabase::count_names(std::string names_file)
	{
		std::ifstream file(names_file);

		if (file.fail())
		{
			throw std::runtime_error("Error occurred trying to access file (" + names_file + ")");
		}

		int count = std::count_if(std::istreambuf_iterator<char>{file}, {}, [](char c) { return c == '\n'; });

		return count;
	}
}