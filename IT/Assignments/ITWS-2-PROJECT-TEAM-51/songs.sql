

drop table if exists music;
    create table music (
    id integer primary key autoincrement,
    sname text not null,
    album text not null,
    singer text not null,
    slink text not null,
    ilink text not null
    );



insert into music values(1,"Ae watan waale","Raazi","Arjit Singh","01.mp3","raazi");
insert into music values(2,"Dilbaro","Raazi","Harshdeep Kaur","02.mp3","raazi");
insert into music values(3,"Raazi","Raazi","Arjit Singh ","03.mp3","raazi");
insert into music values(4,"Ae Watan female","Raazi","Sunidhi Chauhan","04.mp3","raazi");
insert into music values(5,"Aal izz well","3 idiots","Sonu Nigam","05.mp3","3_idiots");
insert into music values(6,"Behti hawa saa thaa woh","3 idiots","Shaan","06.mp3","3_idiots");
insert into music values(7,"Give me some sunshine","3 idiots","Suraj","07.mp3","3_idiots");
insert into music values(8,"Zoobi doobi","3 idiots","Sonu Nigam","08.mp3","3_idiots");
insert into music values(9,"Aane Chaar Aane","Munna Bhai","Karunya","09.mp3","munna");
insert into music values(10,"Bande mein thaa dum","Munna Bhai","Sonu Nigam","10.mp3","munna");
insert into music values(11,"Pal Pal","munna Bhai","Shreya Goshal","11.mp3","munna");
insert into music values(12,"Subah ho gyi mamu","Munna Bhai","Shaan","12.mp3","munna");
insert into music values(13,"Chote Chote peg","Sonu Ke Titu Ki Sweety","Honey Singh","13.mp3","sonu");
insert into music values(14,"Dil Chori","Sonu Ke Titu Ki Sweety","honey_singh","14.mp3","sonu");
insert into music values(15,"Lakk mera hit","Sonu Ke Titu Ki Sweety","Rochak Kohli","15.mp3","sonu");
insert into music values(16,"Tera Yaar Hoon Main","Sonu Ke Titu Ki Sweety","Arjit Singh","16.mp3","sonu");
insert into music values(17,"Agar Tum Saath Ho","Tamaasha","Arjit Singh","17.mp3","agar_tum");
insert into music values(18,"Dil De Chuke Sanam","misc","Sanu Kumar","18.mp3","dil_de");
insert into music values(19,"Nagaadhe sang dhol","Raam Leela","Shreya Goshal","19.mp3","ram");
insert into music values(20,"Raam Chahe Leela","Raam Leela","Bhoomi Trivedi","20.mp3","ram");
