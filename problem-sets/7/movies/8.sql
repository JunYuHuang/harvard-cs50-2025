-- 8. Names of people who starred in Toy Story
SELECT people.name FROM people
INNER JOIN stars on people.id = stars.person_id
WHERE stars.movie_id = (
    SELECT movies.id FROM movies
    WHERE movies.title = 'Toy Story'
);