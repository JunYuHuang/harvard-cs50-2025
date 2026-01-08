-- 9. Names of all people who starred in a movie released in 2004, ordered by birth year
SELECT people.name FROM people
WHERE people.id IN (
    SELECT DISTINCT stars.person_id FROM stars
    WHERE stars.movie_id IN (
        SELECT movies.id FROM movies
        WHERE movies.year = 2004
    )
)
ORDER BY people.birth;

-- check
SELECT COUNT(people.name) FROM people
WHERE people.id IN (
    SELECT DISTINCT stars.person_id FROM stars
    WHERE stars.movie_id IN (
        SELECT movies.id FROM movies
        WHERE movies.year = 2004
    )
)
ORDER BY people.birth;