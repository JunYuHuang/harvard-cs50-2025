#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

bool is_luhn_checksum(long number);
long sum_of_digits(long number);
long count_digits(long number);
long first_n_digits(long number, int n);
bool is_amex(long number);
bool is_mastercard(long number);
bool is_visa(long number);

int main(void)
{
    long credit_card_number;
    do
    {
        credit_card_number = get_long("Number: ");
    }
    while (credit_card_number < 1);

    if (!is_luhn_checksum(credit_card_number))
    {
        printf("Fails Luhn's Algorithm Checksum\n");
        printf("INVALID\n");
    }
    else if (is_amex(credit_card_number))
    {
        printf("AMEX\n");
    }
    else if (is_mastercard(credit_card_number))
    {
        printf("MASTERCARD\n");
    }
    else if (is_visa(credit_card_number))
    {
        printf("VISA\n");
    }
    else
    {
        printf("Passes Luhn's Algorithm Checksum and is not an AMEX, MASTERCARD, or VISA card\n");
        printf("INVALID\n");
    }

    // // Using test number `4003600000000014`:
    // long test_number = 4003600000000014;
    // printf("Using long test number for function tests: %li\n", test_number);

    // // Test function `is_luhn_checkum()`:
    // bool is_luhn_checksum_result = is_luhn_checksum(test_number);
    // printf(
    //     "%li is a Luhn checksum? (1 = true, 0 = false): %d\n",
    //     test_number,
    //     is_luhn_checksum_result
    // );

    // // Test function `sum_of_digits()`:
    // long sum_of_digits_result = sum_of_digits(test_number);
    // int sum_of_digits_expected = 18;
    // printf(
    //     "Sum of digits of %li is %i? (1 = true, 0 = false): %d\n",
    //     test_number,
    //     sum_of_digits_expected,
    //     sum_of_digits_result == sum_of_digits_expected
    // );

    // // Test function `count_digits()`:
    // long count_digits_result = count_digits(test_number);
    // int count_digits_expected = 16;
    // printf(
    //     "Count of digits in %li is %i? (1 = true, 0 = false): %d\n",
    //     test_number,
    //     count_digits_expected,
    //     count_digits_result == count_digits_expected
    // );

    // // Test function `first_n_digits()`:
    // long first_n_digits_result = first_n_digits(test_number, 2);
    // int first_n_digits_expected = 40;
    // printf(
    //     "First %i digit(s) in %li is %i? (1 = true, 0 = false): %d\n",
    //     2,
    //     test_number,
    //     first_n_digits_expected,
    //     first_n_digits_result == first_n_digits_expected
    // );

    // // Test function `is_amex()`:
    // test_number = 378282246310005;
    // bool is_amex_result = is_amex(test_number);
    // bool is_amex_expected = true;
    // printf(
    //     "%li is an AMEX number? (1 = true, 0 = false): %d\n",
    //     test_number,
    //     is_amex_result == is_amex_expected
    // );

    // // Test function `is_mastercard()`:
    // test_number = 5555555555554444;
    // bool is_mastercard_result = is_mastercard(test_number);
    // bool is_mastercard_expected = true;
    // printf(
    //     "%li is a MASTERCARD number? (1 = true, 0 = false): %d\n",
    //     test_number,
    //     is_mastercard_result == is_mastercard_expected
    // );

    // // Test function `is_visa()`:
    // test_number = 4003600000000014;
    // bool is_visa_result = is_visa(test_number);
    // bool is_visa_expected = true;
    // printf(
    //     "%li is a VISA number? (1 = true, 0 = false): %d\n",
    //     test_number,
    //     is_visa_result == is_visa_expected
    // );
}

bool is_luhn_checksum(long number)
{
    bool is_other_digit = false;
    long checksum = 0;
    while (number != 0)
    {
        long digit = number % 10;
        if (is_other_digit)
        {
            long product_sum = sum_of_digits(2 * digit);
            checksum += product_sum;
        }
        else
        {
            checksum += digit;
        }
        is_other_digit = !is_other_digit;
        number /= 10;
    }

    return checksum % 10 == 0;
}

long sum_of_digits(long number)
{
    long res = 0;
    while (number != 0)
    {
        res += number % 10;
        number /= 10;
    }
    // printf("Sum of digits of %li is %li\n", number, res);
    return res;
}

long count_digits(long number)
{
    long res = 1;
    while (number > 9)
    {
        number /= 10;
        res++;
    }
    // printf("%li has %li digit(s)\n", number, res);
    return res;
}

long first_n_digits(long number, int n)
{
    if (n < 1) return -1;
    if (number < 10) return number;
    int i = count_digits(number) - 1;
    int multiplier = 1;
    long res = 0;
    while (number != 0)
    {
        if (i < n)
        {
            int digit = number % 10;
            digit *= multiplier;
            res += digit;
            multiplier *= 10;
        }
        number /= 10;
        i--;
    }
    // printf("First %i digit(s) of %li is %li\n", n, number, res);
    return res;
}

bool is_amex(long number)
{
    if (count_digits(number) != 15) return false;
    
    printf("%li is of length 15\n", number);
    long prefix = first_n_digits(number, 2);
    return (prefix == 34 || prefix == 37);
}

bool is_mastercard(long number)
{
    if (count_digits(number) != 16) return false;
    
    printf("%li is of length 16\n", number);
    long prefix = first_n_digits(number, 2);
    return (
        prefix == 51 ||
        prefix == 52 ||
        prefix == 53 ||
        prefix == 54 ||
        prefix == 55
    );
}

bool is_visa(long number)
{
    long number_length = count_digits(number);
    printf("%li is of length %li\n", number, number_length);

    if (number_length != 13 && number_length != 16) return false;

    printf("%li is of length 13 or 16\n", number);
    return first_n_digits(number, 1) == 4;
}