# Movies

## General Notes

### SQL database schema:

```SQL
CREATE TABLE directors (
    movie_id INTEGER NOT NULL,
    person_id INTEGER NOT NULL,
    FOREIGN KEY(movie_id) REFERENCES movies(id),
    FOREIGN KEY(person_id) REFERENCES people(id)
);
CREATE TABLE movies (
    id INTEGER,
    title TEXT NOT NULL,
    year NUMERIC,
    PRIMARY KEY(id)
);
CREATE TABLE people (
    id INTEGER,
    name TEXT NOT NULL,
    birth NUMERIC,
    PRIMARY KEY(id)
);
CREATE TABLE ratings (
    movie_id INTEGER NOT NULL UNIQUE,
    rating REAL NOT NULL,
    votes INTEGER NOT NULL,
    FOREIGN KEY(movie_id) REFERENCES movies(id)
);
CREATE TABLE stars (
    movie_id INTEGER NOT NULL,
    person_id INTEGER NOT NULL,
    FOREIGN KEY(movie_id) REFERENCES movies(id),
    FOREIGN KEY(person_id) REFERENCES people(id)
);
```

## Todos

- [x] `1.sql` (ok)
- [x] `2.sql` (ok)
- [x] `3.sql` (ok)
- [x] `4.sql` (ok)
- [x] `5.sql` (ok)
- [x] `6.sql` (ok)
- [x] `7.sql` (ok)
- [x] `8.sql` (ok)
- [x] `9.sql` (ok)
- [x] `10.sql` (ok)
- [x] `11.sql` (ok)
- [x] `12.sql` (ok)
- [ ] `13.sql`

