
drop table if exists playname;
    create table playname (
    id integer primary key autoincrement,
    pname text not null,
    userid integer not null,
    ptype text not null,
    FOREIGN KEY(userid) REFERENCES users(id) 
    );

drop table if exists playlso;
    create table playlso (
    id integer primary key autoincrement,
    pname text not null,
    songname integer not null,
    FOREIGN KEY(songname) REFERENCES music(sname)  
    );
