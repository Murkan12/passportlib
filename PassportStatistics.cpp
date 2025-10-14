#include "PassportStatistics.h"

namespace Passportlib
{
	PassportStatistics::PassportStatistics(double AGE_MEAN, double AGE_STDDEV, double HEIGHT_MEAN, double HEIGHT_STDDEV, double WEIGHT_MEAN, double WEIGHT_STDDEV, double HEIGHT_WEIGHT_CORELLATION) :
	AGE_MEAN {AGE_MEAN}, AGE_STDDEV {AGE_STDDEV}, HEIGHT_MEAN {HEIGHT_MEAN}, HEIGHT_STDDEV {HEIGHT_STDDEV}, WEIGHT_MEAN {WEIGHT_MEAN}, WEIGHT_STDDEV {WEIGHT_STDDEV}, HEIGHT_WEIGHT_CORELLATION {HEIGHT_WEIGHT_CORELLATION}
	{}

	int PassportStatistics::get_age()
	{
		return std::lround(age_dist(gen));
	}

	double PassportStatistics::get_height()
	{
		return std::ceil(height_dist(gen) * 100.0) / 100.0;
	}

	int PassportStatistics::get_weight(double height)
	{
		if (height <= 0.0)
		{
			throw std::runtime_error("Invalid height (" + std::to_string(height) + ") to produce weight!");
		}

		return std::ceil(WEIGHT_MEAN + HEIGHT_WEIGHT_CORELLATION * (WEIGHT_STDDEV / HEIGHT_STDDEV) * (height - HEIGHT_MEAN) + WEIGHT_STDDEV 
			* std::sqrt(1 - HEIGHT_WEIGHT_CORELLATION * HEIGHT_WEIGHT_CORELLATION) * noise_generator(gen));
	}

	int PassportStatistics::get_coin_flip()
	{
		return coin_flip(gen);
	}

	int PassportStatistics::get_random_index(int min_value, int max_value)
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

		std::uniform_int_distribution<int> uni{min_value, max_value};
		return uni(gen);
	}
}