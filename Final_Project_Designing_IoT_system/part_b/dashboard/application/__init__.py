from flask import Flask
from flask_sqlalchemy import SQLAlchemy
import os



app = Flask(__name__)
# app.config["SQLALCHEMY_DATABASE_URI"] = 'mysql://root@localhost/final'

app.debug = True
app.secret_key = "ghUl57dbfndhksfh9hh" # generates secret key for app


db = SQLAlchemy(app)