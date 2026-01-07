-- 4. Number of movies with a 10.0 rating
SELECT COUNT(*)
FROM movies INNER JOIN ratings
ON movies.id = ratings.movie_id
AND rating = 10.0;