#include "Nationality.h"
#include "NamesDatabase.h"
#include "AmericanPassport.h"
#include "PassportStatistics.h"

int main()
{
	using namespace Passportlib;

	NamesDatabase ndb{Nationality::AMERICAN};
	PassportStatistics ps{35.0, 7.5, 1.71, 0.07, 80.0, 8.0, 0.75};

	std::cout << "Male names count: " << ndb.get_male_names_count() << "\n";
	std::cout << "Surnames count: " << ndb.get_surnames_count() << "\n";
	std::cout << "Female names count: " << ndb.get_female_names_count() << "\n";


	AmericanPassport p{ndb, ps};
	Identity i = p.generate_identity();
	std::cout << "#------ PASSPORTLIB VER. 0.0.1 ------#" << "\n";
	std::cout << "@------------------------------------@" << "\n";
	std::cout << "	FIRST NAME:	" << i.get_first_name() << "\n";
	std::cout << "	LAST NAME:	" << i.get_surname() << "\n";
	std::cout << "	NATIONALITY:    " << i.nationality_to_string() << "\n";
	std::cout << "	GENDER:	        " << i.gender_to_string() << "\n";
	std::cout << "	AGE:            " << i.get_age() << " y.o." << "\n";
	std::cout << "	HEIGHT:         " << i.get_height() << "m" << "\n";
	std::cout << "	WEIGHT:         " << i.get_weight() << "kg" << "\n";
	std::cout << "@------------------------------------@" << "\n";

	return 0;
}