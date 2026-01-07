-- 8. Names of people who starred in Toy Story
SELECT name FROM people
INNER JOIN stars on people.id = stars.person_id
WHERE movie_id = (SELECT id FROM movies WHERE title = 'Toy Story');