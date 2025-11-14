# Credit

## General Notes

- PEDAC: Problem
    - inputs:
        - `credit_card_number`: long integer
            - will be entirely numeric
            - has no leading zeroes
    - outputs:
        - none
    - side effects / mutations:
        - prints a string from the set `{ 'AMEX', 'MASTERCARD', 'VISA', 'INVALID' }` that indicates if the given credit card number is a valid type (1 of 3) or an invalid type
    - constraints:
        - see above
    - `credit_card_number` is a valid credit card IFF:
        - it is an AMEX card number OR
        - it is a MASTERCARD card number OR
        - it is a VISA card number AND
        - it is a Luhn number / checksum or passes Luhn's Algorithm
    - an AMEX card number is valid IFF:
        - it is of length 15
        - it has a numeric prefix of `34` or `37`
        - it is a Luhn number
    - a MASTERCARD number is valid IFF:
        - it is of length 16
        - it has a numeric prefix from the set `{ 51, 52, 53, 54, 55}`
        - it is a Luhn number
    - a VISA number is valid IFF:
        - it is of length 13 or 16
        - it has a numeric prefix of 4
        - it is a Luhn number
- PEDAC: Example
    - case 1:
        - `credit_card_number` = 4003600000000014
        - is valid credit card of type VISA'
    - case 2:
        - `credit_card_number` = 6176292929
        - is invalid credit card

## Solution 1

- todo