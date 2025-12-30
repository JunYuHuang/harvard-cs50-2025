from cs50 import get_int

def main():
    number = 0
    while number < 1:
        number = get_int("Number: ")
    
    if not is_luhn_checksum(number):
        print("INVALID")
    elif is_amex(number):
        print("AMEX")
    elif is_mastercard(number):
        print("MASTERCARD")
    elif is_visa(number):
        print("VISA")
    else:
        print("INVALID")
    
def is_luhn_checksum(number):
    is_other_digit = False
    checksum = 0

    while number != 0:
        digit = number % 10

        if is_other_digit:
            product_sum = sum_of_digits(2 * digit)
            checksum += product_sum
        else:
            checksum += digit
        is_other_digit = not is_other_digit
        number //= 10

    return checksum % 10 == 0

def sum_of_digits(number):
    res = 0
    while number != 0:
        res += number % 10
        number //= 10
    return res

def count_digits(number):
    res = 1
    while number > 9:
        number //= 10
        res += 1
    return res

def first_n_digits(number, n):
    if n < 1:
        return -1
    if number < 10:
        return number
    
    i = count_digits(number) - 1
    multiplier = 1
    res = 0

    while number != 0:
        if i < n:
            digit = number % 10
            digit *= multiplier
            res += digit
            multiplier *= 10
        number //= 10
        i -= 1
    return res

def is_amex(number):
    if count_digits(number) != 15:
        return False
    prefix = first_n_digits(number, 2)
    return prefix == 34 or prefix == 37

def is_mastercard(number):
    if count_digits(number) != 16:
        return False
    prefix = first_n_digits(number, 2)
    return (
        prefix == 51 or
        prefix == 52 or
        prefix == 53 or
        prefix == 54 or
        prefix == 55
    )

def is_visa(number):
    number_length = count_digits(number)
    if number_length != 13 and number_length != 16:
        return False
    return first_n_digits(number, 1) == 4

main()