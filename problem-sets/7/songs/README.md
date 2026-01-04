# Songs

## General Notes

- `songs.db` SQL DB schema:
    ```SQL
    CREATE TABLE songs (
        id INTEGER,
        name TEXT,
        artist_id INTEGER,
        danceability REAL,
        energy REAL,
        key INTEGER,
        loudness REAL,
        speechiness REAL,
        valence REAL,
        tempo REAL,
        duration_ms INTEGER
    );
    CREATE TABLE artists (
        id INTEGER,
        name TEXT
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
