# from application.models import getData
from flask import render_template
from sqlalchemy import create_engine
from sqlalchemy.ext.automap import automap_base
from sqlalchemy.orm import Session
import pymysql
pymysql.install_as_MySQLdb()
from application import app


CONN_STR = 'mysql://root@localhost/final'
engine = create_engine(CONN_STR, echo=True)


Base = automap_base()
Base.prepare(engine, reflect=True)

Sensors = Base.classes.mysensors
session = Session(engine)

result = session.query(Sensors).all()

def getData(res):
    return {
        "id": res.DataID,
        "led1": res.Led1,
        "led2": res.Led2,
        "servo": res.ServoMotor,
        "temperature": res.temperature,
        "humidity": res.humidity,
        "ldr": res.ldr,
        "time": res.TimeRead
    }


@app.route('/')
def index():
    
    data = [getData(data) for data in result]
    return render_template('dashboard.html', data=data)