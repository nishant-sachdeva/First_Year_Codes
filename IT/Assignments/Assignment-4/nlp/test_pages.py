import urllib,json
import unittest
from flask import Flask, render_template, flash, redirect, url_for, session, request, logging, jsonify
from flask_testing import LiveServerTestCase
from flask_sqlalchemy import SQLAlchemy

class MyTest(LiveServerTestCase):

    SERVER="http://127.0.0.1:5000"

    def create_app(self):
        app = Flask(__name__)
        app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:////tmp/test.db'
        app.config['TESTING'] = True
        app.config['LIVESERVER_PORT'] = 0
        app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
        db = SQLAlchemy(app)

        array = [ ["(EOS)", "I", "YOU", "HIM", "CAN", "NEAR", "SIT"],
                    ["0", "300", "300", "0", "300", "0", "300"],
                    ["0","0","0","0","300", "0", "300"],
                    ["600", "0","0","0","300","0","0"],
                    ["300","0","0","0","0","0","0","0"],
                    ["0", "300", "0","0","0","0", "600"],
                    ["0","0","300", "300","0","0","0"],
                    ["300","0","300","0","0","600","0"]
                ]

        class ans(db.Model):
            id = db.Column('id',db.Integer, primary_key=True)
            answer1 = db.Column(db.String(80), unique=False)
            answer2 = db.Column(db.String(80), unique=False)
            answer3 = db.Column(db.Integer, unique=False)

            def __init__(self, answer1, answer2, answer3):
                self.answer1=answer1
                self.answer2=answer2
                self.answer3=answer3

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

        return app

    def test_webpage(self):
        urls=["/","/Introduction","/Theory","/Objective","/Quizzes","/Procedure","/FurtherReadings","/Experiment"]
        for i in range(8):
                response = urllib.request.urlopen(self.SERVER+urls[i])
                print(response.code)
                self.assertEqual(response.code, 200)
                assert "" != response.read()

if __name__ == '__main__':

    unittest.main()
