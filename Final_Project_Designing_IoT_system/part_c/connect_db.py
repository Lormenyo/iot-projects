import pymysql

# Open database connection
db = pymysql.connect("localhost","root","","final" )

# prepare a cursor object using cursor() method
cursor = db.cursor()


def insert_into_db(temp1, temp2, ldr, heater, humidity1, humidity2, pump):
    db.ping()
    # print(f"led1 {CurrentReading} dtype {type(CurrentReading)}")
    # Prepare SQL query to INSERT a record into the database.
    sql = "INSERT INTO subscriber(temp1 , temp2, ldr, heater, humidity1, humidity2, pump)\
    VALUES ('%f', '%f', '%f', '%s', '%f', '%f', '%s')" % \
    (temp1, temp2, ldr, heater, humidity1, humidity2, pump)
    
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