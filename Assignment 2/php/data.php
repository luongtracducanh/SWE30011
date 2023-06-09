<?php
// setting header to json
header('Content-Type: application/json');

// database
define('DB_HOST', 'localhost');
define('DB_USERNAME', 'root');
define('DB_PASSWORD', 'ducanh2003');
define('DB_NAME', 'IOT');

// get connection
$mysqli = new mysqli(DB_HOST, DB_USERNAME, DB_PASSWORD, DB_NAME);

if(!$mysqli){
  die("Connection failed: " . $mysqli->error);
}

// query to get data from the table
$query = sprintf("SELECT ID, Temperature, Humidity FROM newtable");
$query2 = sprintf("SELECT MAX(Temperature) AS maxTemp FROM newtable");
$query3 = sprintf("SELECT MIN(Temperature) AS minTemp FROM newtable");
$query4 = sprintf("SELECT MAX(Humidity) AS maxHumid FROM newtable");
$query5 = sprintf("SELECT MIN(Humidity) AS minHumid FROM newtable");
$query6 = sprintf("SELECT CAST(AVG(Temperature) AS DECIMAL(10, 2)) AS avgTemp FROM newtable");
$query7 = sprintf("SELECT CAST(AVG(Humidity) AS DECIMAL(10,2)) AS avgHumid FROM newtable");

// execute query
$result = $mysqli->query($query);
$result2 = $mysqli->query($query2);
$result3 = $mysqli->query($query3);
$result4 = $mysqli->query($query4);
$result5 = $mysqli->query($query5);
$result6 = $mysqli->query($query6);
$result7 = $mysqli->query($query7);

// loop through the returned data
foreach ($result as $row) {
  $data[] = $row;
}

foreach ($result2 as $row2) {
  $data2 = $row2;
}

foreach ($result3 as $row3) {
  $data3 = $row3;
}

foreach ($result4 as $row4) {
  $data4 = $row4;
}

foreach ($result5 as $row5) {
  $data5 = $row5;
}

foreach ($result6 as $row6) {
  $data6 = $row6;
}

foreach ($result7 as $row7) {
  $data7 = $row7;
}

// free memory associated with result
$result->close();

// close connection
$mysqli->close();

// print the data
print("[");
print json_encode($data);
print(",");
print json_encode($data2);
print(",");
print json_encode($data3);
print(",");
print json_encode($data4);
print(",");
print json_encode($data5);
print(",");
print json_encode($data6);
print(",");
print json_encode($data7);
print("]");
?>