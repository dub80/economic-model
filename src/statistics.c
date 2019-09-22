#include <gsl/gsl_randist.h>
#include <time.h>

gsl_rng *r;

void initialiseStatistics()
{
  r = gsl_rng_alloc(gsl_rng_ranlxs0);
  gsl_rng_set(r, time(NULL));
}

void cleanupStatistics() { free(r); }

double denormalise(double standardNormalValue, double mean, double stddev)
{
  return (standardNormalValue * stddev) + mean;
}

double getRandomGaussian(double mean, double stddev, double *min, double *max)
{
  double v = gsl_ran_gaussian(r, 1.0);
  double d = denormalise(v, mean, stddev);

  if (min != NULL)
  {
    if (d <= *min)
    {
      return getRandomGaussian(mean, stddev, min, max);
    }
  }
  if (max != NULL)
  {
    if (d >= *max)
    {
      return getRandomGaussian(mean, stddev, min, max);
    }
  }
  return d;
}
