# Birthdays

## General Notes

- PEDAC: Problem 
    - inputs:
        - a
    - outputs:
        - none
    - side effects / mutations:
        - a
    - constraints / rules:
        - a
- PEDAC: Examples
    - skipped

### `birthdays.db` SQL database schema

```SQL
CREATE TABLE birthdays (
    id INTEGER,
    name TEXT,
    month INTEGER,
    day INTEGER,
    PRIMARY KEY(id)
);
```

## Solution 1: brute force

- a

## Tests

- [x] Implement GET `/` route that displays a page with a table showing all the people with their birthdays from the `birthday.db` database
- [x] Implement POST `/` route that
    - [x] displays a form for adding a new birthday to the database
    - [x] updates the database with the new record
    - [x] re-renders the index page
