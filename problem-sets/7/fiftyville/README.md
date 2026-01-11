# Fiftyville

## General Notes

### SQL database schema:

```SQL
CREATE TABLE crime_scene_reports (
    id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    street TEXT,
    description TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE interviews (
    id INTEGER,
    name TEXT,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    transcript TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE atm_transactions (
    id INTEGER,
    account_number INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    atm_location TEXT,
    transaction_type TEXT,
    amount INTEGER,
    PRIMARY KEY(id)
);
CREATE TABLE bank_accounts (
    account_number INTEGER,
    person_id INTEGER,
    creation_year INTEGER,
    FOREIGN KEY(person_id) REFERENCES people(id)
);
CREATE TABLE airports (
    id INTEGER,
    abbreviation TEXT,
    full_name TEXT,
    city TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE flights (
    id INTEGER,
    origin_airport_id INTEGER,
    destination_airport_id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    hour INTEGER,
    minute INTEGER,
    PRIMARY KEY(id),
    FOREIGN KEY(origin_airport_id) REFERENCES airports(id),
    FOREIGN KEY(destination_airport_id) REFERENCES airports(id)
);
CREATE TABLE passengers (
    flight_id INTEGER,
    passport_number INTEGER,
    seat TEXT,
    FOREIGN KEY(flight_id) REFERENCES flights(id)
);
CREATE TABLE phone_calls (
    id INTEGER,
    caller TEXT,
    receiver TEXT,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    duration INTEGER,
    PRIMARY KEY(id)
);
CREATE TABLE people (
    id INTEGER,
    name TEXT,
    phone_number TEXT,
    passport_number INTEGER,
    license_plate TEXT,
    PRIMARY KEY(id)
);
CREATE TABLE bakery_security_logs (
    id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    hour INTEGER,
    minute INTEGER,
    activity TEXT,
    license_plate TEXT,
    PRIMARY KEY(id)
);
```

## Notes:

- 10 SQL tables
- theft event whereabouts
    - date: July 28, 2025
    - place: Humphrey Street
    - time of day: 10:15 AM
    - 3 witnesses
    - before theft:
        - before theft, thief was withdrawing money from an ATM on Leggett Street
    - after theft
        - thief exited the bakery parking lot in a car within 10 minutes of the theft (i.e., from 10:15 AM to 10:25 AM)
        - thief called someone for < 1 minute
        - thief had their accomplice purchase the earliest flight ticket the next day on July 29, 2025
        - thief's flight:
            - was to New York City
- thief profile
    - 1 of 8 passengers on flight 36 that took off on July 29, 2025 towards New York City
        - passenger names:
            - Kenny
            - Sofia
            - Taylor
            - Luca
            - Kelsey
            - Edward
            - Bruce
            - Doris
    - 1 of 4 people on the thief's flight and had their car spotted (by license plate) leaving the bakery on July 28, 2025 from 10:15 AM to 10:25 AM
        - Sofia
        - Luca
        - Kelsey
        - Bruce
- misc
    - calls in `phone_calls` table
        - `duration` column most likely refers to the call perio in seconds

## Todos

- [x] Name of thief?
- [x] City that the thief escaped to?
- [x] Name of thief's accomplice who helped them escape?

