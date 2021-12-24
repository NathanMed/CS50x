select name from directors join people on directors.person_id = people.id join movies on directors.movie_id= movies.id join ratings on movies.id = ratings.movie_id
where rating >= 9