-- 10. Names of all directors who have directed a movie that got a rating of at least 9.0
SELECT people.name FROM people
WHERE people.id IN (
    SELECT DISTINCT directors.person_id FROM directors
    WHERE directors.movie_id IN (
        SELECT movies.id FROM movies
        WHERE movies.id IN (
            SELECT ratings.movie_id FROM ratings
            WHERE ratings.rating >= 9.0
        )
    )
);
