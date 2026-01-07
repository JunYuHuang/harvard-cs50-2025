-- 9. Names of all people who starred in a movie released in 2004, ordered by birth year
SELECT name FROM people
INNER JOIN stars on people.id = stars.person_id
INNER JOIN movies on stars.movie_id = movies.id
WHERE year = 2004
ORDER BY birth ASC;

-- TODO: it hangs -> fix it