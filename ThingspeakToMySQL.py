import urllib
import MySQLdb

# This is a live feed from Thingspeak....
# but the database details will need to be altered to your own..Setup MySQL...
# user "temperature1" (No Password) database name "sensor1" table name "senSorData"
# Table contains a record number incremented automatically along with time stamp
# with the data being written to "Location Temperature Humidity" records.......
db = MySQLdb.connect(host="localhost", user="temperature1",passwd="", db="sensor1")
cur = db.cursor()
txt1 = urllib.urlopen("https://thingspeak.com/channels/75705/fields/1/last.txt").read()
txt2 = urllib.urlopen("https://thingspeak.com/channels/75705/fields/2/last.txt").read()
Tem = float(txt1)
Hum = float(txt2)
LoCation = "Bathroom"
sql = ("""INSERT INTO senSorData (Location,Temperature,Humidity) VALUES (%s,%s,%s)""",(LoCation,Tem,Hum))
try:
        # Execute the SQL command
        cur.execute(*sql)
        # Commit your changes in the database
        db.commit()
except:
        # Rollback in case there is any error
        db.rollback()
        print "Failed writing to database"
cur.close()
db.close()
