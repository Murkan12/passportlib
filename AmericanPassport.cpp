#include "AmericanPassport.h"

namespace Passportlib 
{
	Passportlib::AmericanPassport::AmericanPassport(NamesDatabase& ndb, PassportStatistics& ps) : Passportlib::Passport(Passportlib::Nationality::AMERICAN, ndb, ps) 
	{}
}
