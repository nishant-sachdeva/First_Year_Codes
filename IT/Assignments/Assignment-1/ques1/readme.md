Aim:
To create a document and supporting commands to store songs/music that you listen to, so
that you can look back on them when you're bored and trying to find out songs that you've liked
in the past. Kind of like a song diary.
Requirements:
- Create a storage document, which holds all the details that you add. Simplest form would be
some kind of delimited document, but feel free to use multiple documents or even a database to
store the information.
- Create commands(name them whatever you want):
- Add entry:
- Takes n arguments (your wish as to what data you want to keep).
- At least 1 (or more) mandatory argument
- At least 1 (or more) non-essential arguments
- Suggestion: Song name, artist name, genre, youtube link ...etc
- Should check to ensure no duplicate
- Suggestion: Keep an id parameter, would be helpful in identification for editing
- Use redirection (<, >) to add to the file.
- Edit entry
- Allows updating the fields of a certain song entry. (ex. fixing spelling mistakes, adding in
new youtube link).
- Suggestion: Could be implemented as a Delete + Add
- Delete entry
- Remove a song entry from your document.
- Deletion should be achieved in a single command. (See: sed)- View all entries
- Put a "nice view" to all the songs you have. (Create a table-like view?)
- View select entries
- View all the songs satisfying a certain requirement. (ex. all songs of 1 artist, all songs of
same genre)
BONUS:
- Allow for the user to add in custom fields
Submission:
- Script to setup the whole system on someone's system. Assume no sudo permissions (For
your own use, you may want to move some of your scripts to /usr/local/bin so that they are
accessible throughout your system, or add them to your path)
- Scripts for each of the commands(add, edit, view all, view select, and any additional
commands you've included)

///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
So, here's what I have in mind:


1 = SONG_NAME = ARTIST_NAME = GENRE = LINK = LAST_MODIFIED
This is the pattern in which the input is expected. If the user enters wrong stuff, it's upto them
whatever wrong results come their way.

The links that are entered for the songs will not be checked for correctness. It's upto the user to verify before
entering their links.

The delimiter used is the "=" sign. Since there might be spaces in the song name and the artist's name etc.  the user is required to enter the songs using the given sign as delimiter. The songs will be stored using the same delimiter in the songs list file.

As far as the list file goes, the first coloumn is reserved for the headings. The user may delete the  other
entries but is forbidden to do so for the first. Altho the user may still delete the first one,  it is upto the user to live with the damage it causes.

The user need not enter any id for the song name. The program will assign that. However the id is required when deleting or editing the entries.

While deleting the file, only enter the id
While editing the file, only enter the prev id and the new entry:
    the format for editing arguments is :
        ID song=artist=genre=link 

The user need not enter the last modifed  either. The program has ways to deal with that.

As far as view_select goes, the user should enter the string to search for in the arguments.
The search results will be provided.

HAVE A NICE EXPERIENCE :)