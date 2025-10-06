#ifndef PASSPORTLIB_IDENTITY_H
#define PASSPORTLIB_IDENTITY_H

#include <string>
#include <stdexcept>

#include "Nationality.h"
#include "Gender.h"

namespace Passportlib
{
	class Identity
	{
		public:
			Identity(Nationality nationality, Gender gender, std::string first_name, std::string surname, int age, double height, double weight);
			std::string nationality_to_string();
			std::string gender_to_string();
			std::string get_first_name();
			std::string get_surname();
			int get_age();
			double get_height();
			double get_weight();

		private:
			Nationality nationality;
			Gender gender;
			std::string first_name;
			std::string surname;
			int age;
			double height;
			double weight;
	};
};

#endif