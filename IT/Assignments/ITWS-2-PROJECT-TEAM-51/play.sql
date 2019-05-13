drop table if exists playl;
    create table playl (
    id integer primary key autoincrement,
    pname text not null,
    userid integer not null,
    songid integer not null,
    ptype text not null,
    FOREIGN KEY(userid) REFERENCES users(id),
    FOREIGN KEY(songid) REFERENCES music(id)  
    );
