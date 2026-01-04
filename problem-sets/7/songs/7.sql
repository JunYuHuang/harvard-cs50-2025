SELECT AVG(energy) from SONGS
WHERE artist_id = (
    SELECT id FROM artists
    WHERE name = 'Drake'
);