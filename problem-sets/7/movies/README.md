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

- [x] `1.sql`
- [x] `2.sql`
- [x] `3.sql`
- [x] `4.sql`
- [x] `5.sql`
- [x] `6.sql`
- [x] `7.sql`
- [x] `8.sql`
- [ ] `9.sql` (WIP)
- [ ] `10.sql`
- [ ] `11.sql`
- [ ] `12.sql`
- [ ] `13.sql`

