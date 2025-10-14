#ifndef PASSPORTLIB_NAMESDATABASE_H
#define PASSPORTLIB_NAMESDATABASE_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <fstream>
#include <algorithm>
#include <limits>

#include "Nationality.h"

namespace Passportlib
{
	enum class NameFlag
	{
		MALE,
		FEMALE,
		SURNAME
	};

	class NamesDatabase
	{
		public:
			NamesDatabase(Nationality n);
			int get_male_names_count();
			int get_female_names_count();
			int get_surnames_count();
			std::string get_name_from_index(int index, NameFlag flag);

		private:
			const std::string db_root = "names_db/";

			std::string male_names_file;
			std::string female_names_file;
			std::string surnames_file;
			int male_names_count;
			int female_names_count;
			int surnames_count;

			void build_file_path(std::string& file_path, std::string nationality_selector, std::string suffix);

			int count_names(std::string names_file);
	};
}

#endif