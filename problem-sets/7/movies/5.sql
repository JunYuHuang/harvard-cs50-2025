-- 5. Titles and years of all Harry Potter movies, in chronological order (title beginning with "Harry Potter and the ...")
SELECT movies.title, movies.year FROM movies
WHERE movies.title LIKE 'Harry Potter and the %'
ORDER BY movies.year ASC;
