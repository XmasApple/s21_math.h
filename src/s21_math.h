#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define S21_PI 3.1415926535897932384626433832795028841971

// вычисляет абсолютное значение целого числа
int s21_abs(int x);

long double s21_sqrt(double x);

// вычисляет абсолютное значение числа с плавающей точкой
long double s21_fabs(double x);

// возвращает ближайшее целое число, не меньшее заданного значения
long double s21_ceil(double x);

// возводит число в заданную степень
long double s21_pow(double base, double exp);

// возвращает значение e, возведенное в заданную степень
long double s21_exp(double x);

// возвращает ближайшее целое число, не превышающее заданное значение
long double s21_floor(double x);

// остаток операции деления с плавающей точкой
long double s21_fmod(double x, double y);

// возвращат арксинус значения
long double s21_asin(double x);

// возвращает значение арккосинуса
long double s21_acos(double x);

// возвращает арктангенс числа
long double s21_atan(double x);

long double s21_sin(double x);

// вычисляет косинус
long double s21_cos(double x);

// логарифм
long double s21_log(double x);

long double s21_tan(double x);

// Вспомоогательные функции

// function for fmod
double s21_trunc(double d);

long double s21_fact_double(int x);

#endif  // SRC_S21_MATH_H_
