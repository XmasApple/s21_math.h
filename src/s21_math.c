#include "s21_math.h"

int s21_abs(int x) { return x >= 0 ? x : x * -1; }

long double s21_fabs(double x) {
  double result;
  if (x != x) {
    result = x;
  } else if (x == 1. / 0.0) {
    result = 1. / 0.0;
  } else {
    result = x >= 0 ? x : x * -1;
  }
  return result;
}

long double s21_ceil(double x) {
  double result;
  if (x != x) {
    result = x;
  } else if (x == 1. / 0.0) {
    result = 1. / 0.0;
  } else if (x == -1. / 0.0) {
    result = -1. / 0.0;
  } else {
    result = (x - (long long int)x != 0 && x > 0) ? (long long int)x + 1
                                                  : (long long int)x;
  }
  return result;
}

long double s21_pow(double base, double exp) {
  long double result = base;
  if (base != 1) {
    if ((base != base) || exp != exp) {
      result = 0 / 0.0;
    } else if (base == 1. / 0.0 || exp == 1. / 0.0) {
      result = 1. / 0.0;
    } else {
      if (base == 0) {
        result = 0;
      } else {
        if (exp - (long long int)exp == 0) {
          if (exp > 0) {
            for (int i = 1; i < exp; i++) {
              result *= base;
            }
          } else if (exp < 0) {
            exp *= -1;
            for (int i = 1; i < exp; i++) {
              result *= base;
            }
            result = 1 / result;
          } else {
            result = 1;
          }
        } else {
          if (exp < 0 || base < 0) {
            result = 0. / 0.;
          } else

            result = s21_exp(exp * s21_log(base));
        }
      }
    }
  }
  return result;
}

long double s21_exp(double x) {
  int counter = 2;
  long double sum, factorial, number = x;
  factorial = number;
  sum = 1.0;
  if (x != x) {
    sum = x;
  } else if (x == 1. / 0.0) {
    sum = 1. / 0.0;
  } else if (x == -1. / 0.0) {
    sum = 0;
  } else {
    while (s21_fabs((double)factorial) > 0.000000000001) {
      sum += factorial;
      factorial *= number / counter;
      counter++;
    }
  }
  return sum;
}

long double s21_floor(double x) {
  double result;
  if (x != x) {
    result = x;
  } else if (x == 1. / 0.0) {
    result = 1. / 0.0;
  } else if (x == -1. / 0.0) {
    result = -1. / 0.0;
  } else {
    result = (x - (long long int)x != 0 && x < 0) ? (long long int)x - 1
                                                  : (long long int)x;
  }

  return result;
}

long double s21_fmod(double x, double y) {
  long double result;
  if ((x != x) || y != y) {
    result = 0 / 0.0;
  } else if (x == 1. / 0.0 || y == 1. / 0.0) {
    result = 0. / 0.0;
  } else {
    if (x == 0) {
      result = 0;
    } else {
      result = (y == 0) ? 0 / 0.0 : (x - s21_trunc(x / y) * y);
    }
  }
  return result;
}

long double s21_asin(double x) {
  long double sum = x;
  long double slog = x;
  int n = 1;
  if (s21_fabs(s21_fabs(x) - 1) < 0.000001) {
    sum = S21_PI / 2. * x;
  } else if (x < -1 || x > 1) {
    sum = 0 / 0.0;
  } else {
    while (s21_fabs((double)slog) > 0.000000000001) {
      slog *= (x * x * (2. * n - 1) * (2. * n - 1)) / (2. * (2. * n + 1) * n);
      sum += slog;
      n++;
    }
  }
  return sum;
}

long double s21_atan(double x) {
  int sign = x < 0 ? -1 : 1;
  long double result = sign * s21_acos(1. / (s21_pow(1 + x * x, 0.5)));
  return result;
}

long double s21_acos(double x) {
  long double result = 0.;
  if (x == 1 || x == -1) {
    result = S21_PI * (1 - x) / 2;
  } else if (x < -1 || x > 1) {
    result = 0 / 0.0;
  } else {
    result = (S21_PI / 2) - s21_asin(x);
  }
  return result;
}

long double s21_sin(double x) {
  x = s21_fmod(x, 2 * S21_PI);
  long double sum = x;
  long double d = 1;
  long double pow = x;
  int n = 1;
  long double fact = 1;

  while (s21_fabs((double)d) > 0.000000000001) {
    fact *= ((2 * n) * (2 * n + 1));
    pow *= (-1 * x * x);
    d = pow / fact;
    sum += d;
    n++;
  }
  return sum;
}

long double s21_sqrt(double x) {
  long double res = 0.0 / 0.;
  if (x == 1. / 0.) {
    res = 1. / 0.;
  } else if (x >= 0) {
    res = 1.0;
    for (int i = 0; i < 100; i++) {
      res -= (res * res - x) / (2 * res);
    }
  }
  return res;
}

long double s21_log(double x) {
  int ex_pow = 0;
  long double sum = 0;
  long double comp = 0;

  if (x != x) {
    sum = x;
  } else if (x == 1. / 0.0) {
    sum = 1. / 0.0;
  } else if (x == -1. / 0.0) {
    sum = 0 / 0.;
  } else {
    if (x < 0) {
      sum = 0 / 0.0;
    } else if (x != 0) {
      for (; x >= 2.7182818284; x /= 2.7182818284, ex_pow++) continue;

      for (int i = 0; i < 100; i++) {
        comp = sum;
        sum = comp + 2 * (x - s21_exp(comp)) / (x + s21_exp(comp));
      }
    } else {
      sum = -1.0 / 0.0;
    }
  }
  return (sum + ex_pow);
}

long double s21_cos(double x) {
  x = s21_fmod(x, 2 * S21_PI);
  long double k = -1;
  long double d = 0;
  int n = 1;
  long double pow = x * x;
  long double summ = 1;

  if (x != x) {
    summ = x;
  } else if (x == 1. / 0.0) {
    summ = 0. / 0.0;
  } else {
    do {
      summ += d;
      d = (k * pow) / s21_fact_double(2 * n);
      n++;
      k *= -1;
      pow *= x * x;
    } while (s21_fabs(d) > 0.0000000000000001);
  }
  return summ;
}

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

// Вспомогательные функции

// need for s21_fmod
double s21_trunc(double d) { return (d > 0) ? s21_floor(d) : s21_ceil(d); }

long double s21_fact_double(int x) {
  long double result = 1;
  for (int n = 1; n <= x; n++) {
    result *= n;
  }
  return result;
}
