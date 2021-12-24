select title, rating from ratings join movies on movies.id = ratings.movie_id
where year = 2010
order by rating DESC, title