import pymysql

# Open database connection
db = pymysql.connect("localhost","root","","final" )

# prepare a cursor object using cursor() method
cursor = db.cursor()


def insert_into_db(DeviceName, DeviceType, CurrentReading):
    db.ping()
    # Prepare SQL query to INSERT a record into the database.
    sql = "INSERT INTO subscriber(DeviceName , DeviceType, CurrentReading)\
    VALUES ('%s', '%s', '%f')" % \
    (DeviceName, DeviceType, CurrentReading)
    
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