# Finance

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

### `finance.db` SQL database schema

```SQL
CREATE TABLE users (
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, 
    username TEXT NOT NULL,
    hash TEXT NOT NULL, 
    cash NUMERIC NOT NULL DEFAULT 10000.00
);
CREATE TABLE sqlite_sequence(name,seq);
CREATE UNIQUE INDEX username ON users (username);

CREATE TABLE user_transactions(
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    user_id INTEGER NOT NULL,
    action TEXT NOT NULL,
    stock_symbol TEXT NOT NULL,
    shares INTEGER NOT NULL,
    price NUMERIC NOT NULL,
    created_at TEXT NOT NULL DEFAULT current_timestamp,
    FOREIGN KEY (user_id) REFERENCES users(id)
);

CREATE TABLE user_stocks(
    id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
    user_id INTEGER NOT NULL,
    stock_symbol TEXT NOT NULL,
    shares INTEGER NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id)
);
```

## Solution 1: brute force

### Test SQL Queries

```SQL
SELECT stock_symbol AS symbol, shares
FROM user_stocks
WHERE user_id = 1;
```

## Todos

- [x] Complete `/register` routes (GET, POST)
    - [x] show apology if `username` is blank or exists already
    - [x] show apology if either `password` or `confirmation` are empty
    - [x] show apology if `password` doesn't match `confirmation`
    - [x] submit register form data to `POST` `/register` route
    - [x] use hash of `password` for new user creation
    - [x] redirect to `/` after successful user creation
- [x] Complete `/quote` routes (GET, POST)
    - [x] complete stock form and submission logic
- [x] Complete `/buy` routes (GET, POST)
    - [x] create buy stock form
    - [x] add `user_transactions` table to `finance.db` SQL database
    - [x] add stock buy transaction if prerequisites met
        - [x] deduct stock purchase price from user's account in DB
        - [x] add new transaction "buy" purchase to transaction table in DB
- [x] Complete `/index` routes (GET)
    - [x] make it render an HTML table of 4 columns `Symbol`, `Shares`, `Price`, and `TOTAL` minus the last 2 rows that only show the `Cash` and `TOTAL` values
- [x] Complete `/sell` routes (GET, POST)
    - [x] basically the same as the `/buy` routes but in reverse
- [x] Complete `/history` routes (GET)
- [x] Complete 1+ of the following
    - [x] Allow users to change their passwords.
        - [x] add password reset link to `/templates/layout.html`
        - [x] add `/password` route with GET and POST action controllers
        - [x] create `/templates/reset_password.html` page with password form
    - [ ] Allow users to add additional cash to their account.
    - [ ] Allow users to buy more shares or sell shares of stocks they already own via index itself, without having to type stocks’ symbols manually.
    - [ ] Implement some other feature of comparable scope.

