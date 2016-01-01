 <html lang="en">
 <head>
   <meta charset="utf-8">
   <title>The HTML Script will not execute on the Github Copy to local file for Full View</title>
 </head>
<font color="#000000"><body bgcolor="#a0dFfe"><meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=yes">
	<h2>Environmental Sensor Readings</h2>
	<h2>Using an ESP8266 with 2 DHT11<BR>& 1 DS18B20 Environment Sensors<BR><BR> ♂♀♪♫☼►</h2>
<BR><BR><a href="http://esp8266.com/">Find out how this is done Visit ESP8266.COM Support Forum</a><BR><BR><a href="http://82.5.78.180:82/">The Full Page is displayed Here.....</a><BR><BR>
   <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.5/jquery.min.js"></script>

<div style="float:left;">

<div id="ESPS001" style="float:left;"><a href="https://freeboard.io/board/ISfNF7">Freeboard IO Dashboard</a><BR><a href="http://82.5.78.180:92/jsread">GET JSON Frame</a><BR><a href="http://82.5.78.180:92/diag">Device Information Page</a><BR>Readings from<BR>ESP8266 Sensors </div>
    <div id="container">
  <style type="text/css">
  #container { height: 10%; width: 10%; display: table; }
  #gauge_div { width: 100px; margin: 0 auto; }
ESPS001, th , td {
    border: 1px solid cyan;
    border-collapse: collapse;
    padding: 5px;
}
</style>
Google Gauge Via Thingspeak JSON Frame
      <div id="inner">
        <div id="gauge_div"></div>
      </div>
    </div>
</div>
 <script>
$.ajax({
    // get the data from ESP8266 sensors via CORS Enabled JSON Frame
    // CORS explaination found here...
    //   https://developer.mozilla.org/en-US/docs/Web/HTTP/Access_control_CORS

	 type: "GET",
	 url: "http://82.5.78.180:92/jsread",
	 async: false,
	 beforeSend: function(x) {
	  if(x && x.overrideMimeType) {
	   x.overrideMimeType("application/j-son;charset=UTF-8");
	  }
 },
// Now parse the JSON frame for valid "Key:Value" pairs, as many as you have formed in your sketch the list does not have a size
// Repeated keys will be omitted...
 dataType: "json",
 success: function(data){
	  var items = [];

	  $.each(data, function(key, val) {
	    items.push("<tr><td> "+ key +" </td><td> " + val + " </td></tr> ");
	  });
	
	  $('.my-new-list').remove();	


	  $('<ul/>', {
	    'class': 'my-new-list',
	    html: items.join('')
// Now place the parsed data into the div for display, or do something with the data in the ESP Sketch...
	  }).appendTo('#ESPS001');
 }
});

   </script>
  <script type='text/javascript' src='https://ajax.googleapis.com/ajax/libs/jquery/1.9.1/jquery.min.js'></script>
<script type='text/javascript' src='https://www.google.com/jsapi'></script>
<script type='text/javascript'>

  // set your channel id here
  var channel_id = 75183;
  // set your channel's read api key here if necessary
  var api_key = '';
  // maximum value for the gauge
  var max_gauge_value = 50;
  // name of the gauge
  var gauge_name = 'DS18-Temp';

  // global variables
  var chart, charts, data;

  // load the google gauge visualization
  google.load('visualization', '1', {packages:['gauge']});
  google.setOnLoadCallback(initChart);

  // display the data
  function displayData(point) {
    data.setValue(0, 0, gauge_name);
    data.setValue(0, 1, point);
    chart.draw(data, options);
  }

  // load the data
  function loadData() {
    // variable for the data point
    var p;

    // get the data from thingspeak in the form of a rather large JSON Frame
    // containing lots of useful data interaction for the ESP8266 sketch

    $.getJSON('https://api.thingspeak.com/channels/' + channel_id + '/feed/last.json?api_key=' + api_key, function(data) {

      // get the data point from within the Thingspeak JSON Frame
      p = data.field5;

      // if there is a data point display it
      if (p) {
       // p = Math.round((p / max_gauge_value) * 100);
        displayData(p);
      }

    });
  }

  // initialize the chart & Request data after the Sensor data list is populated
  function initChart() {

    data = new google.visualization.DataTable();
    data.addColumn('string', 'Label');
    data.addColumn('number', 'Value');
    data.addRows(1);

    chart = new google.visualization.Gauge(document.getElementById('gauge_div'));
    options = {width: 300, height: 300, min: 0, max: 50, redFrom: 32, redTo: 50, yellowFrom:0, yellowTo: 17, minorTicks: 10};

    loadData();

    // load new data every 15 seconds
    setInterval('loadData()', 15000);
  }
    // Thingspeak Matlab Frame, this is directly pasted from the html provided by the Thingspeak Page....
</script>
<BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR>
Thingspeak Data Visualisation via Matlab Chart

<div style="float:none;"><iframe width="450" height="375" style="border: 1px solid #cccccc;" src="http://api.thingspeak.com/apps/matlab_visualizations/41029" ></iframe>

<BR>environmental.monitor.log@gmail.com<BR><FONT SIZE=-2>ESP8266 With Various Sensors<BR><FONT SIZE=-2>Compiled Using ver. 2.0.0-rc2, built December, 2015<BR></div>
</body>
</html>
