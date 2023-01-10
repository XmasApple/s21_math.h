
#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(abs_tests) {
  ck_assert_int_eq(abs(-13), s21_abs(-13));
  ck_assert_int_eq(abs(13), s21_abs(13));
  ck_assert_int_eq(abs(-1000), s21_abs(-1000));
  ck_assert_int_eq(abs(32346234), s21_abs(32346234));
  ck_assert_int_eq(abs(0), s21_abs(0));
}
END_TEST

START_TEST(fabs_tests) {
  ck_assert_int_eq(fabs(-13.21313), s21_fabs(-13.21313));
  ck_assert_int_eq(fabs(13.21313), s21_fabs(13.21313));
  ck_assert_int_eq(fabs(-1000.21313), s21_fabs(-1000.21313));
  ck_assert_int_eq(fabs(32346234.21313), s21_fabs(32346234.21313));
  ck_assert_int_eq(fabs(0.0), s21_fabs(0.0));
  ck_assert_ldouble_nan(s21_fabs(NAN));
  ck_assert_ldouble_eq(fabs(INFINITY), s21_fabs(INFINITY));
  ck_assert_ldouble_eq(fabs(-INFINITY), s21_fabs(-INFINITY));
}
END_TEST

START_TEST(fmod_tests) {
  ck_assert_ldouble_eq(fmod(-13.21313, 2.5), s21_fmod(-13.21313, 2.5));
  ck_assert_ldouble_eq(fmod(13.21313, 2.5), s21_fmod(13.21313, 2.5));
  ck_assert_ldouble_eq(fmod(-1000.21313, 2.5), s21_fmod(-1000.21313, 2.5));
  ck_assert_ldouble_eq(fmod(32346234.21313, 2.5),
                       s21_fmod(32346234.21313, 2.5));
  ck_assert_ldouble_eq(fmod(32346234.21313, 213131313.5),
                       s21_fmod(32346234.21313, 213131313.5));
  ck_assert_ldouble_eq(fmod(0, 2.5), s21_fmod(0, 2.5));
  ck_assert_ldouble_eq(fmod(2.5, 2.5), s21_fmod(2.5, 2.5));
  ck_assert_int_eq(fmod(2.5, 0), s21_fmod(2.5, 0));
  ck_assert_double_nan(s21_fmod(2.5, 0));
  ck_assert_ldouble_nan(s21_fmod(NAN, 0));
  ck_assert_ldouble_nan(s21_fmod(INFINITY, INFINITY));
  ck_assert_ldouble_nan(s21_fmod(-INFINITY, -INFINITY));
}
END_TEST

START_TEST(pow_tests) {
  ck_assert_float_eq(pow(13.21313, 2.5), s21_pow(13.21313, 2.5));
  ck_assert_float_eq(pow(32346234.21313, 2.5), s21_pow(32346234.21313, 2.5));
  ck_assert_float_eq(pow(0, 2.5), s21_pow(0, 2.5));
  ck_assert_float_eq(pow(2, 18.1), s21_pow(2, 18.1));
  ck_assert_float_eq(pow(123, -2), s21_pow(123, -2));
  ck_assert_float_eq(pow(123, 2), s21_pow(123, 2));
  ck_assert_float_eq(pow(123, 0), s21_pow(123, 0));
  ck_assert_int_eq(pow(-12.1, -1.1), s21_pow(-12.1, -1.1));
  ck_assert_double_nan(s21_pow(-12.1, -1.1));
  ck_assert_double_nan(s21_pow(-12.1, 1.1));
  ck_assert_ldouble_nan(s21_pow(NAN, NAN));
  ck_assert_ldouble_eq(pow(INFINITY, 1), s21_pow(INFINITY, 1));
  ck_assert_ldouble_eq(pow(-INFINITY, 1), s21_pow(-INFINITY, 1));
  ck_assert_ldouble_eq(pow(INFINITY, INFINITY), s21_pow(INFINITY, INFINITY));
}
END_TEST

START_TEST(ceil_tests) {
  ck_assert_ldouble_eq(ceil(-13.54), s21_ceil(-13.54));
  ck_assert_ldouble_eq(ceil(13.54), s21_ceil(13.54));
  ck_assert_ldouble_eq(ceil(1000), s21_ceil(1000));
  ck_assert_ldouble_eq(ceil(102.0000002), s21_ceil(102.0000002));
  ck_assert_ldouble_eq(ceil(10231313.0000002), s21_ceil(10231313.0000002));
  ck_assert_ldouble_nan(s21_ceil(NAN));
  ck_assert_ldouble_eq(ceil(INFINITY), s21_ceil(INFINITY));
  ck_assert_ldouble_eq(ceil(-INFINITY), s21_ceil(-INFINITY));
}
END_TEST

START_TEST(floor_tests) {
  ck_assert_ldouble_eq(floor(-13.54), s21_floor(-13.54));
  ck_assert_ldouble_eq(floor(13.54), s21_floor(13.54));
  ck_assert_ldouble_eq(floor(-0.54), s21_floor(-0.54));
  ck_assert_ldouble_eq(floor(1000), s21_floor(1000));
  ck_assert_ldouble_eq(floor(102.0000002), s21_floor(102.0000002));
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_eq(floor(INFINITY), s21_floor(INFINITY));
  ck_assert_ldouble_eq(floor(-INFINITY), s21_floor(-INFINITY));
}
END_TEST

START_TEST(exp_tests) {
  ck_assert_float_eq(exp(13.54), s21_exp(13.54));
  ck_assert_float_eq(exp(-0.54), s21_exp(-0.54));
  ck_assert_float_eq(exp(1000), s21_exp(1000));
  ck_assert_float_eq(exp(1), s21_exp(1));
  ck_assert_float_eq(exp(2), s21_exp(2));
  ck_assert_float_eq(exp(0), s21_exp(0));
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_eq(exp(INFINITY), s21_exp(INFINITY));
  ck_assert_ldouble_eq(exp(-INFINITY), s21_exp(-INFINITY));
}
END_TEST

START_TEST(sin_tests) {
  ck_assert_float_eq(sin(-13.54), s21_sin(-13.54));
  ck_assert_float_eq(sin(0.01), s21_sin(0.01));
  ck_assert_float_eq(sin(S21_PI - 0.01), s21_sin(S21_PI - 0.01));
  ck_assert_float_eq(sin(13.54), s21_sin(13.54));
  ck_assert_float_eq(sin(0.0), s21_sin(0.0));
  ck_assert_float_eq(sin(1.0), s21_sin(1.0));
  ck_assert_float_eq(sin(3.14), s21_sin(3.14));
  ck_assert_float_eq(sin(6.28), s21_sin(6.28));
  ck_assert_float_eq(sin(2.2343), s21_sin(2.2343));
  ck_assert_float_eq(sin(0.1234), s21_sin(0.1234));
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_eq(exp(INFINITY), s21_exp(INFINITY));
  ck_assert_ldouble_eq(exp(-INFINITY), s21_exp(-INFINITY));
}
END_TEST

START_TEST(cos_tests) {
  ck_assert_float_eq(cos(-13.54), s21_cos(-13.54));
  ck_assert_float_eq(cos(13.54), s21_cos(13.54));
  ck_assert_float_eq(cos(0.0), s21_cos(0.0));
  ck_assert_float_eq(cos(1.0), s21_cos(1.0));
  ck_assert_float_eq(cos(3.14), s21_cos(3.14));
  ck_assert_float_eq(cos(6.28), s21_cos(6.28));
  ck_assert_float_eq(cos(2.2343), s21_cos(2.2343));
  ck_assert_float_eq(cos(0.1234), s21_cos(0.1234));
  ck_assert_ldouble_nan(s21_cos(NAN));
  ck_assert_ldouble_nan(s21_cos(INFINITY));
  ck_assert_ldouble_nan(s21_cos(-INFINITY));
}
END_TEST

START_TEST(tan_tests) {
  ck_assert_float_eq(tan(-13.54), s21_tan(-13.54));
  ck_assert_float_eq(tan(13.54), s21_tan(13.54));
  ck_assert_float_eq(tan(0), s21_tan(0));
  ck_assert_float_eq(tan(1), s21_tan(1));
  ck_assert_float_eq(tan(3.14), s21_tan(3.14));
  ck_assert_float_eq(tan(6.28), s21_tan(6.28));
  ck_assert_float_eq(tan(2.2343), s21_tan(2.2343));
  ck_assert_float_eq(tan(0.1234), s21_tan(0.1234));
  ck_assert_ldouble_nan(s21_tan(NAN));
  ck_assert_ldouble_nan(s21_tan(INFINITY));
  ck_assert_ldouble_nan(s21_tan(-INFINITY));
}
END_TEST

START_TEST(sqrt_tests) {
  ck_assert_int_eq(sqrt(0.0), s21_sqrt(0.0));
  ck_assert_float_eq(sqrt(1.0), s21_sqrt(1.0));
  ck_assert_float_eq(sqrt(3.14), s21_sqrt(3.14));
  ck_assert_float_eq(sqrt(6.28), s21_sqrt(6.28));
  ck_assert_float_eq(sqrt(2.2343), s21_sqrt(2.2343));
  ck_assert_double_nan(s21_sqrt(-2.2343));
  ck_assert_float_eq(sqrt(0.5), s21_sqrt(0.5));
  ck_assert_ldouble_nan(s21_sqrt(NAN));
  ck_assert_ldouble_eq(sqrt(INFINITY), s21_sqrt(INFINITY));
  ck_assert_ldouble_nan(s21_sqrt(-INFINITY));
}
END_TEST

START_TEST(log_tests) {
  ck_assert_int_eq(log(-13.54), s21_log(-13.54));
  ck_assert_float_eq(log(13.54), s21_log(13.54));
  ck_assert_float_eq(log(0.0), s21_log(0.0));
  ck_assert_int_eq(log(1.0), s21_log(1.0));
  ck_assert_float_eq(log(3.14), s21_log(3.14));
  ck_assert_float_eq(log(6.28), s21_log(6.28));
  ck_assert_float_eq(log(2.2343), s21_log(2.2343));
  ck_assert_float_eq(log(0.1234), s21_log(0.1234));
  ck_assert_float_eq(log(0), s21_log(0));
  ck_assert_int_eq(log(1), s21_log(1));
  ck_assert_float_eq(log(10), s21_log(10));
  ck_assert_ldouble_nan(s21_log(NAN));
  ck_assert_ldouble_eq(log(INFINITY), s21_log(INFINITY));
  ck_assert_ldouble_nan(s21_log(-INFINITY));
}
END_TEST

START_TEST(fact_double_tests) {
  ck_assert_float_eq(1, s21_fact_double(1));
  ck_assert_float_eq(1, s21_fact_double(0));
  ck_assert_float_eq(2, s21_fact_double(2));
  ck_assert_float_eq(120, s21_fact_double(5));
}
END_TEST

START_TEST(asin_tests) {
  ck_assert_int_eq(asin(-13.54), s21_asin(-13.54));
  ck_assert_int_eq(asin(13.54), s21_asin(13.54));
  ck_assert_int_eq(asin(6.28), s21_asin(6.28));

  ck_assert_float_eq(asin(0.1234), s21_asin(0.1234));
  ck_assert_float_eq(asin(0), s21_asin(0));
  ck_assert_float_eq(asin(1), s21_asin(1));
  ck_assert_float_eq(asin(-1), s21_asin(-1));
  ck_assert_float_eq(asin(0.5), s21_asin(0.5));
  ck_assert_float_eq(asin(-0.5), s21_asin(-0.5));
  ck_assert_ldouble_nan(s21_asin(NAN));
  ck_assert_ldouble_nan(s21_asin(INFINITY));
  ck_assert_ldouble_nan(s21_asin(-INFINITY));
}
END_TEST

START_TEST(acos_tests) {
  ck_assert_int_eq(acos(-13.54), s21_acos(-13.54));
  ck_assert_int_eq(acos(13.54), s21_acos(13.54));
  ck_assert_int_eq(acos(2.2343), s21_acos(2.2343));
  ck_assert_float_eq(acos(0.1234), s21_acos(0.1234));
  ck_assert_float_eq(acos(0), s21_acos(0));
  ck_assert_float_eq(acos(1), s21_acos(1));
  ck_assert_float_eq(acos(-1), s21_acos(-1));
  ck_assert_float_eq(acos(0.5), s21_acos(0.5));
  ck_assert_float_eq(acos(-0.5), s21_acos(-0.5));
  ck_assert_ldouble_nan(s21_acos(NAN));
  ck_assert_ldouble_nan(s21_acos(INFINITY));
  ck_assert_ldouble_nan(s21_acos(-INFINITY));
}
END_TEST

START_TEST(atan_tests) {
  ck_assert_int_eq(atan(-13.54), s21_atan(-13.54));
  ck_assert_float_eq(atan(13.54), s21_atan(13.54));
  ck_assert_float_eq(atan(3.14), s21_atan(3.14));
  ck_assert_float_eq(atan(6.28), s21_atan(6.28));
  ck_assert_float_eq(atan(2.2343), s21_atan(2.2343));
  ck_assert_float_eq(atan(0.1234), s21_atan(0.1234));
  ck_assert_float_eq(atan(0), s21_atan(0));
  ck_assert_float_eq(atan(1), s21_atan(1));
  ck_assert_float_eq(atan(-1), s21_atan(-1));
  ck_assert_float_eq(atan(3.5), s21_atan(3.5));
  ck_assert_float_eq(atan(-3.5), s21_atan(-3.5));
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_eq(atan(INFINITY), s21_atan(INFINITY));
  ck_assert_ldouble_eq(atan(-INFINITY), s21_atan(-INFINITY));
}
END_TEST

Suite *s21_math_tests_create() {
  Suite *s21_math = suite_create("s21_math");
  TCase *s21_math_tests = tcase_create("S21_MATH");
  tcase_add_test(s21_math_tests, ceil_tests);
  tcase_add_test(s21_math_tests, floor_tests);
  tcase_add_test(s21_math_tests, exp_tests);
  tcase_add_test(s21_math_tests, sin_tests);
  tcase_add_test(s21_math_tests, cos_tests);
  tcase_add_test(s21_math_tests, tan_tests);
  tcase_add_test(s21_math_tests, sqrt_tests);
  tcase_add_test(s21_math_tests, abs_tests);
  tcase_add_test(s21_math_tests, fabs_tests);
  tcase_add_test(s21_math_tests, fmod_tests);
  tcase_add_test(s21_math_tests, pow_tests);
  tcase_add_test(s21_math_tests, log_tests);
  tcase_add_test(s21_math_tests, asin_tests);
  tcase_add_test(s21_math_tests, acos_tests);
  tcase_add_test(s21_math_tests, atan_tests);
  tcase_add_test(s21_math_tests, fact_double_tests);
  suite_add_tcase(s21_math, s21_math_tests);
  return s21_math;
}

int main() {
  Suite *s21_math = s21_math_tests_create();
  SRunner *s21_math_runner = srunner_create(s21_math);
  int number_failed;
  srunner_run_all(s21_math_runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(s21_math_runner);
  srunner_free(s21_math_runner);

  return number_failed == 0 ? 0 : 1;
}