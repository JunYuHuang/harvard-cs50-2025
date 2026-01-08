-- 11. Titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated
SELECT movies.title FROM movies
INNER JOIN ratings ON ratings.movie_id = movies.id
WHERE movies.id IN (
    SELECT stars.movie_id FROM stars
    WHERE stars.person_id = (
        SELECT people.id FROM people
        WHERE people.name = 'Chadwick Boseman'
    )
)
ORDER BY ratings.rating DESC;

-- check
SELECT COUNT(*) FROM movies
INNER JOIN ratings ON ratings.movie_id = movies.id
WHERE movies.id IN (
    SELECT stars.movie_id FROM stars
    WHERE stars.person_id = (
        SELECT people.id FROM people
        WHERE people.name = 'Chadwick Boseman'
    )
)
ORDER BY ratings.rating DESC;