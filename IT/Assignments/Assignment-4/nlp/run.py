"""These are libraries that have been imported for this project"""
from flask import Flask, render_template, url_for, request
# from random import *
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
"""The database is begin stored in /tmp/test.db of the system it is being run on"""
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:////tmp/test.db'

db = SQLAlchemy(app)

"""This is the array used in the experiment"""

array = [ ["(EOS)", "I", "YOU", "HIM", "CAN", "NEAR", "SIT"],
            ["0", "300", "300", "0", "300", "0", "300"],
            ["0","0","0","0","300", "0", "300"],
            ["600", "0","0","0","300","0","0"],
            ["300","0","0","0","0","0","0","0"],
            ["0", "300", "0","0","0","0", "600"],
            ["0","0","300", "300","0","0","0"],
            ["300","0","300","0","0","600","0"]
        ]
"""The class which is being used for the database named ans.
This class is used throughout the database and has a unique ID for each entry"""

class ans(db.Model):
    id = db.Column('id',db.Integer, primary_key=True)
    answer1 = db.Column(db.String(80), unique=False)
    answer2 = db.Column(db.String(80), unique=False)
    answer3 = db.Column(db.Integer, unique=False)

    def __init__(self, answer1, answer2, answer3):
        self.answer1 = answer1
        self.answer2 = answer2
        self.answer3 = answer3

@app.route("/")
@app.route("/Introduction")
def intro():
    """Renders the Introduction page."""
    return render_template('introduction.html')

@app.route("/Theory")
def theory():
    """Renders the Theory page."""
    return render_template('theory.html')

@app.route("/Objective")
def objective():
    """Renders the Objective page."""
    return render_template('objective.html')

@app.route("/Experiment")
def experiment():
    """Renders the Experiment page."""
    return render_template('experiment.html', array = array)

@app.route("/Quizzes" , methods=["GET", "POST"])
def quizzes():
    """Renders the Quizzes page."""
    return render_template('quiz.html')

@app.route("/Procedure")
def procedure():
    """Renders the Procedure page."""
    return render_template('procedure.html')

@app.route("/FurtherReadings")
def furtherreadings():
    """Renders the Further Readings page."""
    return render_template('furtherreadings.html')

@app.route("/see_answers")
def see_answers():
    """Renders the Answers page."""
    return render_template('answers.html')


@app.route("/Quizzes/submit" , methods=["POST"])
def submit():
    """Creates the database entry and commits"""
    answer1 = request.form["answer1"]
    answer2 = request.form["answer2"]
    answer3 = request.form["answer3"]
    db.create_all()
    all=ans(answer1, answer2, answer3)
    db.session.add(all)
    db.session.commit()
    return render_template('submit.html')


if __name__ == '__main__':
    app.run(debug=True)
