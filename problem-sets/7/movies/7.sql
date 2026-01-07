-- 7. All movies and ratings from 2010, in decreasing order by rating (alphabetical for those with same rating)
SELECT title, rating FROM movies INNER JOIN ratings
ON movies.id = ratings.movie_id
ORDER BY rating DESC, title ASC;