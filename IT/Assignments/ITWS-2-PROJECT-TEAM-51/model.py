import sqlite3 as sql
import random
from flask import session
from passlib.hash import sha256_crypt
#message=None
def authenticate(request):
    con = sql.connect("database.db")
    email = request.form['email']
    password = request.form['password']
    sqlQuery = "select password,username,id from users where email = '%s'"%email
    cursor = con.cursor()
    print "sqlQuery= "+ sqlQuery
    cursor.execute(sqlQuery)
    row = cursor.fetchone()
    status = False
    if row:
        status = sha256_crypt.verify(password, row[0])
        if password==row[0]: 
          status=True
        print "password=",row[0]," status=",status
        if status:
           msg = row[1] + " has logged in Successfully."
           session['username'] = row[1]
           session['userid']= row[2]
    else:
        msg = email + " has failed to login."

    return status

def insertUser(request):

    con = sql.connect("database.db")
    username = request.form['username']
    email = request.form['email']
    password = request.form['password']

    #encrypt the password
    password = sha256_crypt.encrypt(password)
    print "password store is ", password
    sqlQuery = "select email from users where (email ='" + email + "')"
    cursor = con.cursor()
    cursor.execute(sqlQuery)
    row = cursor.fetchone()
    if row:
        con.close()
        return "This "+email+" has already been registered."
    else:
                cur = con.cursor()
                cur.execute("insert into users(username,email,password) values (?,?,?);", (username,email,password))
       		con.commit()
        	con.close()
                return email + " has been registered successfully."


def allsongs():
   con=sql.connect("database.db")
   cursor=con.cursor()
   cursor.execute("select * from music")
   row= cursor.fetchall()
   x=  random.sample(row,12)
   print x
   return x




def fb(request):

    con = sql.connect("database.db")
    name = request.form['cName']
    cur = con.cursor()
    cur.execute("select id from users where username=?", (name,))
    idu=c
    con.close()

def ssearch(request):
   con= sql.connect("database.db")
   key=request.values.get("s")
   cur=con.cursor()
   cur.execute("SELECT * FROM music WHERE LOWER(sname) LIKE LOWER('%"+key+"%')")
   row=cur.fetchall()
   return row

def getusrid():
    con = sql.connect("database.db")
    name = session["username"]
    cur = con.cursor()
    cur.execute("select id  from users where username=?", (name,))
    ids=cur.fetchone()
    print ids[0]
    return ids[0]

def usrplay():
   con=sql.connect("database.db")
   cur=con.cursor()
   try :
     
       mx=getusrid()
       if mx:
              cur.execute("Select pname from playname where userid=? ;",(mx,))
              row=cur.fetchall()
              return row
   except:
       return [("No paylist",),]

def play(playname):
   con=sql.connect("database.db")
   cur=con.cursor()
   sqlQuery="Select music.*,users.username,ptype   from playlso join music on music.sname=songname join playname on playname.pname=playlso.pname join users on users.id=playname.userid where playlso.pname='"+str(playname)+"';"

   cur.execute(sqlQuery)
   row=cur.fetchall()
   print row
   return row

def allUsr():
    con = sql.connect("database.db")
    cur = con.cursor()
    cur.execute("select username  from users;")
    ids=cur.fetchall()
    return ids

def fetchPl():
    con = sql.connect("database.db")
    uname=session['username']
    cur = con.cursor()
    cur.execute("select pname from playname where userid='"+str(getusrid())+"' ;")
    ids=cur.fetchall()
    return ids

def createPlay(request):
    pname=request.form['pname']
    ptype=request.form['pp']
    userid=getusrid()
    con=sql.connect("database.db")
    cur=con.cursor()
    sqlQuery="insert into playname(pname,userid,ptype ) values(?,?,?)"
    cur.execute(sqlQuery,(pname,userid,ptype))
    con.commit()
    con.close()


def addToPl(request):
    pname=request.form['pname']
    sname=request.form['sname']
    con=sql.connect("database.db")
    cur=con.cursor()
    sqlQuery="insert into playlso(pname,songname ) values(?,?)"
    cur.execute(sqlQuery,(pname,sname))
    con.commit()
    con.close()

def getusridpp(name):
    con = sql.connect("database.db")
    cur = con.cursor()
    cur.execute("select id  from users where username=?", (name,))
    ids=cur.fetchone()
    print ids[0]
    return ids[0]



def fetchPname(pn):
   con= sql.connect("database.db")
   cur=con.cursor()
   sqlQuery="Select pname from playname where ptype='Public' and userid='"+str(getusridpp(pn))+"';"
   cur.execute(sqlQuery)
   row=cur.fetchall()
   return row

