-- 12. Titles of all of movies in which both Jennifer Lawrence and Bradley Cooper starred
SELECT movies.title FROM movies
WHERE movies.id IN (
    SELECT DISTINCT stars.movie_id FROM stars
    WHERE stars.person_id IN (
        SELECT people.id FROM people
        WHERE people.name IN (
            'Bradley Cooper', 'Jennifer Lawrence'
        )
    )
);

-- ^wrong
SELECT COUNT(*) FROM movies
WHERE movies.id IN (
    SELECT DISTINCT stars.movie_id FROM stars
    WHERE stars.person_id IN (
        SELECT people.id FROM people
        WHERE people.name IN (
            'Bradley Cooper', 'Jennifer Lawrence'
        )
    )
);