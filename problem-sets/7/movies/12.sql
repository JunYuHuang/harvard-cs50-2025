-- 12. Titles of all of movies in which both Jennifer Lawrence and Bradley Cooper starred
/*
- Your query should output a table with a single column for the title of each movie.
- You may assume that there is only one person in the database with the name Bradley Cooper.
- You may assume that there is only one person in the database with the name Jennifer Lawrence.
*/
SELECT movies.title FROM movies
WHERE movies.id IN (
    SELECT stars.movie_id FROM stars
    WHERE stars.person_id = (
        SELECT people.id FROM people
        WHERE people.name = 'Bradley Cooper'
    )
) AND movies.id IN (
    SELECT stars.movie_id FROM stars
    WHERE stars.person_id = (
        SELECT people.id FROM people
        WHERE people.name = 'Jennifer Lawrence'
    )
);
