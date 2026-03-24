# Struktur-Data-Mini-Project

This programs runs a music playlist queue using a Doubly Linked List (Deque).
Users can add songs, queue songs to play next, move forward, move backward,
and display the current playlist.

Queued songs will be removed automatically after they are played once.

### COMMANDS

ADD [song] :
Add song to the end of playlist

QUEUE [song] :
Add temporary song after current (removed after played once) 

NEXT :
Move to next song and prints it

BACK :
Move to previous song and prints it

LIST :
Display songs from current to end of playlist

REMOVE [song] :
Remove a song from playlist

EXIT :
Terminate the program

### Example

## Input:
["ADD A","ADD B","ADD C","QUEUE D","LIST","NEXT","NEXT","BACK","REMOVE B","LIST","EXIT"]

## Output:
[null,null,null,null,"A, D, B, C","D","B","A",null,"A, C"]
