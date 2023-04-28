# to access MySQL db in terminal: mysql -u root -h localhost IOT -p

import MySQLdb
import serial

# establish serial connection between Arduino and RPi using the 9600 port
ser = serial.Serial('/dev/ttyS1', 9600, timeout=1)  # configure the port if needed

# connect to MySQL database
dbConn = MySQLdb.connect("localhost", "root", "ducanh2003", "IOT") or die("Could not connect to the database")
print(dbConn)

# loop the program, exit using Ctrl + C
while True:
    # get input from Arduino's sensor
    data = ser.readline().decode('utf-8').rstrip()

    # an exception in case the temperature change and return an empty string
    try:
        if (data):
            temp = data.split(',')
            temperature = float(temp[0])
            humidity = float(temp[1])
            data = (temperature, humidity)  # tuple to for the sql INSERT statement

            cursor = dbConn.cursor()
            # insert the data into our table
            cursor.execute("INSERT INTO newtable (Temperature, Humidity) values (%s, %s)" % (data))
            dbConn.commit()

            # print the details of the table in real time
            cursor.execute("SELECT * FROM newtable ORDER BY ID DESC limit 1")
            result = cursor.fetchall()
            for row in result:
                print(row)

            # get value from button
            cursor.execute("SELECT Value FROM button ORDER BY ID DESC limit 1")
            result2 = cursor.fetchone()
            # if the table is empty then the query will return none
            try:
                for row2 in result2:
                    print(row2)
                    ser.write(f"{row2}\n".encode())
            # continue the program is query return none
            except TypeError:
                print("Table is empty.")

            cursor.close()


    # when encounter an empty string, the conversion from string to float will return an error
    # we need to exclude this from our program
    except ValueError:
        print(f'Error inserting "{data}" to database.')
