(TA to contact regarding doubts in the question: Mohit)
Instructions
- Read the question carefully
- Use the file ‘movies_input’ as an input for testing your script
Problem Statement :
Samyak and Archit are very good friends. Archit is a total movie freak. He has lots of movies in
his laptop. Samyak, gave him a list of movies and their IMDB ratings. He was very delighted and
wanted to sort all the movies he has as per their IMDB ratings & put them in different folders.
Your job is to help Archit.
Input format :
Command will be of the form :
bash <your_script.sh> <movies_rating_file_path> <all_movies_folder_path>
<movies_rating_file_path>: Path to the movies_input file
<all_movies_folder_path>: Path to the directory which would contain movie files
Eg :​ bash ./script.sh /home/Archit/Samyak_movies_rating.txt ./media/All_Movies/
Ratings file format :
Format of input <movies_rating_file_path> :
<movie_name>:<imdb_rating>
For ex -
Simmba:6.6
Andhadhun:8.8
Stree:7.2
Sanju:7.6
Padman:8.4
Zero:6.1......
Note​ - ​ There is no spacing between the movie name, colon and the imdb rating.
Your script should do this-
1). Create 4 folders at <all_movies_folder_path> : Bad, Average, Good, Awesome.
2). For all the movies present in <all_movies_folder_path>, find their imdb ratings from
<movies_rating_file_path> (i.e. Using file ‘movies_input’). Now create empty movie files in any
one of the 4 folders according to the following rule:
If the rating < 5 : Bad
If rating is >=5 and <8 : Average
If rating >= 8 and <9 : Good
If rating >= 9 : Awesome
After running the script, the movie files should be present in their respective folders as per their
rating.
Submission format-
You will have to submit one bash script file by name <Roll_no>.sh containing the bash script .
Assumptions-
-
-
Name the empty movie files as <movie_name>.mp4
The name of the movies will be a single word.


The question statement seems straightforward and explains what to expect.

HAVE A NICE TIME :)


