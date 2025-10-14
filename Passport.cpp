#include "Passport.h"

namespace Passportlib 
{
	Passportlib::Passport::Passport(Nationality pp_n, NamesDatabase& ndb, PassportStatistics& ps)
	: passport_nationality {pp_n}, ndb {ndb}, ps {ps}
	{}

	std::string Passportlib::Passport::produce_name(Gender g)
	{
		int max_range{};
		int index{};
		std::string name;

		if (g == Gender::MALE)
		{
			index = ps.get_random_index(MIN_NAME_INDEX, ndb.get_male_names_count());
			name = ndb.get_name_from_index(index, NameFlag::MALE);
		}
		else if (g == Gender::FEMALE)
		{
			index = ps.get_random_index(MIN_NAME_INDEX, ndb.get_female_names_count());
			name = ndb.get_name_from_index(index, NameFlag::FEMALE);
		}

		return name;
	}

	Gender Passportlib::Passport::produce_gender()
	{
		int coin_flip = ps.get_coin_flip();

		if (coin_flip == 1)
		{
			return Gender::MALE;
		}
		else
		{
			return Gender::FEMALE;
		}
	}

	std::string Passportlib::Passport::produce_surname()
	{
		int index = ps.get_random_index(MIN_NAME_INDEX, ndb.get_surnames_count());

		return ndb.get_name_from_index(index, NameFlag::SURNAME);
	}

	Passportlib::Identity Passportlib::Passport::generate_identity()
	{
		Gender gender = produce_gender();
		std::string first_name = produce_name(gender);
		std::string surname = produce_surname();
		int age = ps.get_age();
		double height = ps.get_height();
		double weight = ps.get_weight(height);

		return Passportlib::Identity(passport_nationality, gender, first_name, surname, age, height, weight);
	}
};