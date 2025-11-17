#include <stdio.h>
#include <cs50.h>

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
        printf("INVALID\n");
    }
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
    return res;
}

bool is_amex(long number)
{
    if (count_digits(number) != 15) return false;
    long prefix = first_n_digits(number, 2);
    return (prefix == 34 || prefix == 37);
}

bool is_mastercard(long number)
{
    if (count_digits(number) != 16) return false;
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
    if (number_length != 13 && number_length != 16) return false;
    return first_n_digits(number, 1) == 4;
}