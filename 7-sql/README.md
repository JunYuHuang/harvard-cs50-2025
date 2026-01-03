# Week 7 Python

## Lecture Material

- web page: https://cs70.harvard.edu/x/weeks/7/
- notes: https://cs70.harvard.edu/x/notes/7/
- slides: https://cdn.cs70.net/7077/fall/lectures/7/lecture7.pdf
- code: https://cdn.cs70.net/7077/fall/lectures/7/src7/
- Problem Set 7: https://cs70.harvard.edu/x/psets/7/
- topics:
    - SQL: Tables; Types; Statements; Constraints; Indexes; Keywords, Functions; Transactions. Race Conditions. SQL Injection Attacks.

## Notes

- at video timestamp 34:01
- CSV file: simple way to store data e.g., `favorites.csv`
- Python `reader()` function is stateful; it remembers where in the file it is a like a cassette tape
- flat file database e.g., CSV files
- relational database e.g., SQL databases
    - has CRUD operations
        - C = CREATE
        - R = READ
        - U = UPDATE
        - D = DELETE
- SQL
    - CRUD operation commands
        - C = CREATE, INSERT
        - R = READ -> SELECT
        - U = UPDATE
        - D = DELETE, DROP
    - SQL commands and syntax
    - `sqlite3`: a SQL database
- `sqlite3` commands:
    ```
    sqlite3 DATABASE_NAME.db
    .mode csv
    .import FILE TABLE
    .quit
    .mode table
    .headers on

    SELECT columns FROM table;
    ```
    - `.`-prefixed commands are `sqlite3` specific
- database: software that stores and allows retrieval of data

## Problem Set 7

- [ ] Complete [Songs](https://cs50.harvard.edu/x/psets/7/songs/)
- [ ] Complete [Movies](https://cs50.harvard.edu/x/psets/7/movies/)
- [ ] Complete [Fiftyville](https://cs50.harvard.edu/x/psets/7/fiftyville)
