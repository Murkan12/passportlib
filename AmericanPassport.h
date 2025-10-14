#ifndef PASSPORTLIB_AMERICAN_PASSPORT_H
#define PASSPORTLIB_AMERICAN_PASSPORT_H

#include "Passport.h"
#include "Nationality.h"
#include "NamesDatabase.h"
#include "PassportStatistics.h"

namespace Passportlib 
{
	class AmericanPassport : public Passportlib::Passport
	{
		public:
			AmericanPassport(NamesDatabase& ndb, PassportStatistics& ps);
	};
}

#endif