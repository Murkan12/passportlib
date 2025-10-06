#include "Passport.h"

int main()
{
	using namespace Passportlib;

	Passport p(Nationality::AMERICAN);
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