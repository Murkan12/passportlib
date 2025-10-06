#include "Passport.h"
namespace Passportlib 
{
	Passportlib::Passport::Passport(Nationality pp_n)
	{
		passport_nationality = pp_n;
		switch (passport_nationality)
		{
			case Nationality::AMERICAN:
				male_names_file = "names_db/american_male";
				female_names_file = "names_db/american_female";
				surnames_file = "surnames_db/american_surnames";
				break;
		}

		male_names_count = count_names(male_names_file);
		female_names_count = count_names(female_names_file);
		surnames_count = count_names(surnames_file);

		if (male_names_count == 0 || female_names_count == 0)
		{
			std::cout << "The count of names in files is equal to 0! Check if the names database is setup correctly.";
			std::terminate();
		}
	}

	// ADD ERROR HANDLING
	int Passportlib::Passport::count_names(std::string names_file)
	{
		std::ifstream file(names_file);

		if (file.fail())
		{
			return 0;
		}

		int count = std::count_if(std::istreambuf_iterator<char>{file}, {}, [](char c) { return c == '\n'; });

		return count;
	}

	std::string Passportlib::Passport::produce_name(Gender g)
	{
		std::string file_name;
		int max_range{};
		std::string name;

		if (g == Gender::MALE)
		{
			file_name = male_names_file;
			max_range = male_names_count;
		}
		else if (g == Gender::FEMALE)
		{
			file_name = female_names_file;
			max_range = female_names_count;
		}

		int name_index = produce_random_name_index(max_range);

		std::ifstream names_file(file_name);
		name = produce_name_from_index(names_file, name_index);

		return name;
	}

	int Passportlib::Passport::produce_random_name_index(int max_value, int min_value)
	{
		if (min_value < 0)
		{
			throw std::runtime_error("The min value for random name index is negative!");
		}

		if (max_value < 0)
		{
			throw std::runtime_error("The max value for random name index is negative!");
		}

		if (max_value < min_value)
		{
			throw std::runtime_error("The max value is lesser than the min value!");
		}

		std::random_device rd;
		std::mt19937 rng(rd());
		std::uniform_int_distribution<int> uni(min_value, max_value);
		return uni(rng);
	}

	std::string Passportlib::Passport::produce_name_from_index(std::ifstream& names_file, int index)
	{
		if (index <= 0)
		{
			throw std::runtime_error("The value of index must be positive!");
		}

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

	Gender Passportlib::Passport::produce_gender()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::bernoulli_distribution d(0.5);

		int dist_result = d(gen);

		if (dist_result == 1)
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
		std::ifstream file(surnames_file);
		int index = produce_random_name_index(surnames_count);
		std::string surname = produce_name_from_index(file, index);

		return surname;
	}

	int Passportlib::Passport::produce_age()
	{
		return std::lround(age_dist(gen));
	}

	double Passportlib::Passport::produce_height()
	{
		return std::ceil(height_dist(gen) * 100.0) / 100.0;
	}

	double Passportlib::Passport::produce_weight()
	{
		return std::lround(weight_dist(gen));
	}

	double Passportlib::Passport::produce_weight(double height)
	{
		if (height <= 0.0)
		{
			throw std::runtime_error("Invalid height (" + std::to_string(height) + ") to produce weight!");
		}

		return std::ceil(WEIGHT_MEAN + HEIGHT_WEIGHT_CORELLATION * 
			(WEIGHT_STDDEV / HEIGHT_STDDEV) * 
			(height - HEIGHT_MEAN) + WEIGHT_STDDEV * 
			std::sqrt(1 - HEIGHT_WEIGHT_CORELLATION * HEIGHT_WEIGHT_CORELLATION) * noise_generator(gen));
	}

	int Passportlib::Passport::get_female_names_count()
	{
		return female_names_count;
	}

	int Passportlib::Passport::get_male_names_count()
	{
		return male_names_count;
	}

	int Passportlib::Passport::get_surname_count()
	{
		return surnames_count;
	}

	Passportlib::Identity Passportlib::Passport::generate_identity()
	{
		Gender gender = produce_gender();
		std::string first_name = produce_name(gender);
		std::string surname = produce_surname();
		int age = produce_age();
		double height = produce_height();
		double weight = produce_weight();

		return Passportlib::Identity(passport_nationality, gender, first_name, surname, age, height, weight);
	}
};