from flask import *
from model import *
app=Flask(__name__)
app.secret_key = 'MKhJHJH798798kjhkjhkjGHh'


@app.route('/')
def homepage():
   if 'username' in session:
      print usrplay()
      return render_template("index.html",srch=False, logged_in = True,  username=session['username'],rows=allsongs(),prow=usrplay(),alusr=allUsr())
   else:
      print "nooooooo"
      return render_template('index.html',srch=False,logged_in= False,username=None,rows=allsongs(),prow=None,alusr=allUsr())


@app.route('/contact')
def h3():
  return render_template('contact.html')


@app.route('/login',methods=['POST'])
def login():
    if request.method=='POST':
          if(authenticate(request)):
                   print "logged in"
          else:
                   print "failed"
          return redirect("/")
@app.route('/logout', methods=['POST', 'GET'])
def logout():
    if 'username' in session:
        name = session.pop('username')
    return redirect("/")

@app.route('/register', methods=['POST', 'GET'])
def register():
	if request.method=='POST':
	      print insertUser(request)
        return redirect("/")

@app.route('/app/feedback', methods=['POST', 'GET'])
def fbred():
        if request.method=='POST':
             fb(request)
        return redirect("/contact")

@app.route('/search', methods=['POST', 'GET'])
def ssong():
        if request.method=='GET':
             if 'username' in session:
                 return render_template("index.html",srch=True ,logged_in = True,  username=session['username'] ,rows=ssearch(request),prow=usrplay(),alusr=allUsr())
             else:
                 return render_template('index.html',srch=True, logged_in= False, username=None ,rows=ssearch(request),prow=usrplay(),alusr=allUsr())


@app.route('/playlist/<pn>')
def playList(pn):
    if 'username' in session:
                 return render_template("playlist.html", logged_in = True,  username=session['username'] ,namep=pn ,prow=usrplay(),rows=play(pn))
    else:
                 return render_template('playlist.html', logged_in= False, username=None ,namep=pn,prow=usrplay(),rows=play(pn))

@app.route('/addPlay/<sss>')
def odo(sss):
 if 'username' in session:

    return render_template("caplay.html", logged_in = True,  username=session['username'] ,vaall=sss ,rows=fetchPl())

@app.route('/crplay',methods=['POST','GET'])
def crpl():
   if request.method=='POST':
        createPlay(request)
        x=request.form['sname']
        y='/addPlay/'+x
        return redirect(y)
@app.route('/adplay',methods=['POST','GET'])
def adpll():
   if request.method=='POST':
        addToPl(request)
        return redirect('/')

@app.route('/user/<pn>')
def xyz(pn):
    return render_template("userspl.html", logged_in = True,users=pn, username=session['username'] ,namep=pn ,row=fetchPname(pn))


if __name__ == '__main__':
   app.run(debug=True,host='0.0.0.0',port=8080,ssl_context=('cert.pem', 'key.pem'))
