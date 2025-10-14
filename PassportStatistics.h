#ifndef PASSPORTLIB_PASSPORTSTATISTICS_H
#define PASSPORTLIB_PASSPORTSTATISTICS_H

#include <iostream>
#include <stdexcept>
#include <random>

namespace Passportlib
{
	class PassportStatistics
	{
		public:
			PassportStatistics(double AGE_MEAN, double AGE_STDDEV, double HEIGHT_MEAN, double HEIGHT_STDDEV, double WEIGHT_MEAN, double WEIGHT_STDDEV, double HEIGHT_WEIGHT_CORELLATION);

			int get_age();
			double get_height();
			int get_weight(double height);
			int get_coin_flip();
			int get_random_index(int min_value, int max_value);

		private:
			double AGE_MEAN;
			double AGE_STDDEV;
			double HEIGHT_MEAN;
			double HEIGHT_STDDEV;
			double WEIGHT_MEAN;
			double WEIGHT_STDDEV;
			double HEIGHT_WEIGHT_CORELLATION;

			std::random_device rd{};
			std::mt19937 gen{rd()};
			std::normal_distribution<double> age_dist{AGE_MEAN, AGE_STDDEV};
			std::normal_distribution<double> height_dist{HEIGHT_MEAN, HEIGHT_STDDEV};
			std::normal_distribution<double> weight_dist{WEIGHT_MEAN, WEIGHT_STDDEV};					
			std::normal_distribution<double> noise_generator{0.0, 1.0};
			std::bernoulli_distribution coin_flip{0.5};
	};
}

#endif