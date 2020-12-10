import pymysql

# Open database connection
# db = pymysql.connect("localhost","root","","final" )

# Cloud database
db = pymysql.connect(host='us-cdbr-east-02.cleardb.com',
                    user='b8370eb7574a56',
                    password='2af696d9',
                    db='heroku_c49b5b35ce17b71'
                    )

# prepare a cursor object using cursor() method
cursor = db.cursor()


def insert_into_db(led1, led2, servo, temp, humidity, ldr):
    db.ping()
    # print(f"led1 {CurrentReading} dtype {type(CurrentReading)}")
    # Prepare SQL query to INSERT a record into the database.
    sql = "INSERT INTO mysensors(Led1 , Led2, ServoMotor, temperature, humidity, ldr)\
    VALUES ('%s', '%s', '%s', '%f', '%f', '%f')" % \
    (led1, led2, servo, temp, humidity, ldr)
    
    try:
        
        # Execute the SQL command
        cursor.execute(sql)
        print("query executed")
        # Commit your changes in the database
       
        db.commit()
    except:
        # Rollback in case there is any error
        db.rollback()
        print("query not executed")

# disconnect from server
db.close()