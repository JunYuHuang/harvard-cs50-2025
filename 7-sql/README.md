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

- at video timestamp: completed
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
    ```SQL
    sqlite3 DATABASE_NAME.db
    .mode csv
    .import FILE TABLE
    .quit
    .mode table
    .headers on

    SELECT columns FROM table;

    AVG
    COUNT
    DISTINCT
    LOWER
    MAX
    MIN
    UPPER
    ...

    GROUP BY
    LIKE
    LIMIT
    ORDER BY
    WHERE
    ...

    INSERT INTO table (column, ...) VALUES(values, ...)

    NULL

    DELETE FROM table WHERE condition;

    UPDATE table SET column = value WHERE condition;

    BLOB
    INTEGER
    NUMERIC
    REAL
    TEXT

    NOT NULL
    UNIQUE

    PRIMARY KEY
    FOREIGN KEY

    JOIN
    ```
    - `.`-prefixed commands are `sqlite3` specific
- more example `sqlite3` SQL commands:
    ```SQL
    SELECT title FROM shows, stars, people
    WHERE shows.id = stars.show_id
    AND people.id = stars.person_id
    AND name = 'Steve Carrell';

    .timer on

    CREATE INDEX name ON table (column, ...);

    BEGIN TRANSACTION
    COMMIT
    ROLLBACK
    ```

- database: software that stores and allows retrieval of data
- IMDb
- normalize data to reduce redundancy
- one-to-one
- primary key vs foreign key
- one-to-many
- many-to-many
- indexes
    - uses B-Tree data structure under the hood
- SQL injection attacks
    - fix: never trust user input e.g., use a trusted library for running SQL commands
- race conditions
    - fix: use database lock e.g. with transactions

## Problem Set 7

- [x] Complete [Songs](https://cs50.harvard.edu/x/psets/7/songs/)
- [x] Complete [Movies](https://cs50.harvard.edu/x/psets/7/movies/)
- [ ] Complete [Fiftyville](https://cs50.harvard.edu/x/psets/7/fiftyville)
