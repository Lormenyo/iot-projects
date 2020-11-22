import pymysql

# Open database connection
db = pymysql.connect("localhost","admin","admin","iotlab7" )

# prepare a cursor object using cursor() method
cursor = db.cursor()


def insert_into_db(SensorName, SensorType, CurrentReading, SensorLocation, Name):
    db.ping()
    # Prepare SQL query to INSERT a record into the database.
    sql = "INSERT INTO mosquitto(SensorName ,\
    SensorType, CurrentReading, SensorLocation, Name)\
    VALUES ('%s', '%s', '%f', '%s', '%s' )" % \
    (SensorName, SensorType, CurrentReading, SensorLocation, Name)
    
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