-- 11. Titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated
/*
- Your query should output a table with a single column for the title of each movie.
- You may assume that there is only one person in the database with the name Chadwick Boseman.
*/
SELECT movies.title FROM movies
INNER JOIN ratings ON ratings.movie_id = movies.id
WHERE movies.id IN (
    SELECT stars.movie_id FROM stars
    WHERE stars.person_id = (
        SELECT people.id FROM people
        WHERE people.name = 'Chadwick Boseman'
    )
)
ORDER BY ratings.rating DESC
LIMIT 5;