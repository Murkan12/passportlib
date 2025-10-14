#ifndef PASSPORTLIB_PASSPORT_H
#define PASSPORTLIB_PASSPORT_H

#include <random>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

#include "PassportStatistics.h"
#include "NamesDatabase.h"
#include "Nationality.h"
#include "Identity.h"
#include "Gender.h"

namespace Passportlib
{
	class Passport
	{
		public:
			Passport(Nationality pp_n, NamesDatabase& ndb, PassportStatistics& ps);
			Identity generate_identity();
			//int get_male_names_count();
			//int get_female_names_count();
			//int get_surname_count();

		private:
			const int MIN_NAME_INDEX = 1;

			NamesDatabase& ndb;
			PassportStatistics& ps;
			Nationality passport_nationality;

			/*std::string male_names_file;
			std::string female_names_file;
			std::string surnames_file;
			int male_names_count;
			int female_names_count;
			int surnames_count;*/

			//std::string produce_name_from_index(std::ifstream& names_file, int index);
			//int count_names(std::string names_file);
			Gender produce_gender();
			std::string produce_name(Gender g);
			std::string produce_surname();
	};
}

#endif