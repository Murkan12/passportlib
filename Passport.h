#ifndef PASSPORTLIB_PASSPORT_H
#define PASSPORTLIB_PASSPORT_H

#include <random>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>

#include "Nationality.h"
#include "Identity.h"
#include "Gender.h"

namespace Passportlib 
{
	class Passport
	{
		public:
			Passport(Nationality pp_n);
			Identity generate_identity();
			int get_male_names_count();
			int get_female_names_count();
			int get_surname_count();

		private:
			static constexpr double AGE_MEAN = 35.0;
			static constexpr double AGE_STDDEV = 7.5;
			static constexpr double HEIGHT_MEAN = 1.71;
			static constexpr double HEIGHT_STDDEV = 0.07;
			static constexpr double WEIGHT_MEAN = 80.0;
			static constexpr double WEIGHT_STDDEV = 8.0;
			static constexpr double HEIGHT_WEIGHT_CORELLATION = 0.75;

			std::string male_names_file;
			std::string female_names_file;
			std::string surnames_file;
			int male_names_count;
			int female_names_count;
			int surnames_count;

			std::random_device rd{};
			std::mt19937 gen{rd()};
			std::normal_distribution<double> age_dist{AGE_MEAN, AGE_STDDEV};
			std::normal_distribution<double> height_dist{HEIGHT_MEAN, HEIGHT_STDDEV};
			std::normal_distribution<double> weight_dist{WEIGHT_MEAN, WEIGHT_STDDEV};
			std::normal_distribution<double> noise_generator{0.0, 1.0};

			int produce_random_name_index(int max_value, int min_value = 1);
			std::string produce_name_from_index(std::ifstream& names_file, int index);
			int count_names(std::string names_file);
			Gender produce_gender();
			std::string produce_name(Gender g);
			std::string produce_surname();

			int produce_age();
			double produce_height();
			double produce_weight();
			double produce_weight(double height);
			Nationality passport_nationality;
	};
}

#endif