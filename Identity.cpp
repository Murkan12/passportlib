#include "Identity.h"

namespace Passportlib
{
	Identity::Identity(Nationality nationality, Gender gender, std::string first_name, std::string surname, int age, double height, double weight)
	: nationality{nationality}, gender{gender}, first_name{first_name}, surname{surname}, age{age}, height{height}, weight{weight}
	{}

	std::string Identity::nationality_to_string()
	{
		switch (nationality)
		{
			case Nationality::AMERICAN:
				return "American";
			default:
				throw std::logic_error("The given nationality does not have implemented string representation!");
		}
	}

	std::string Identity::gender_to_string()
	{
		switch (gender)
		{
			case Gender::MALE:
				return "Male";
			case Gender::FEMALE:
				return "Female";
			default:
				throw std::logic_error("The given gender does not have implemented string representation!");
		}
	}

	std::string Identity::get_first_name()
	{
		return first_name;
	}

	std::string Identity::get_surname()
	{
		return surname;
	}

	int Identity::get_age()
	{
		return age;
	}

	double Identity::get_height()
	{
		return height;
	}

	double Identity::get_weight()
	{
		return weight;
	}
};