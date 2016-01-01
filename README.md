 <html lang="en">
 <head>
   <meta charset="utf-8">
   <title>ESP8266-Environment-Monitor</title>
 </head>
<font color="#000000"><body bgcolor="#a0dFfe"><meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=yes">
	<h2>Environmental Sensor Readings</h2>
	<h2>Using 5 ESP8266's with Various Sensors<BR><BR> ♂♀♪♫☼►</h2>
<BR><BR><a href="http://esp8266.com/">Find out how this is done Visit ESP8266.COM Support Forum</a><BR><BR><BR>
   <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.5/jquery.min.js"></script>

<div style="float:left;">
<div id="ESPS001" style="float:left;"><a href="http://82.5.78.180:83/diag">Device Information Page</a><BR><a href="https://freeboard.io/board/dRP7R6">Freeboard IO Dashboard</a><BR><a href="http://82.5.78.180:83/jsread">GET JSON Frame</a><BR>Sensors from<BR>ESP8266 Number 1 </div>
<div id="ESPS002" style="float:left;"><a href="http://82.5.78.180:92/diag">Device Information Page</a><BR><a href="https://freeboard.io/board/ISfNF7">Freeboard IO Dashboard</a><BR><a href="http://82.5.78.180:92/jsread">GET JSON Frame</a><BR>Sensors from<BR>ESP8266 Number 2 </div> 
<div id="ESPS003" style="float:left;"><a href="http://82.5.78.180:93/diag">Device Information Page</a><BR><a href="https://freeboard.io/board/QojxS6">Freeboard IO Dashboard</a><BR><a href="http://82.5.78.180:93/jsread">GET JSON Frame</a><BR>Sensors from<BR>ESP8266 Number 3 </div>
<div id="ESPS004" style="float:left;"><a href="http://82.5.78.180:81/diag">Device Information Page</a><BR><a href="https://freeboard.io/board/6GyRV6">Freeboard IO Dashboard</a><BR><a href="http://82.5.78.180:81/jsread">GET JSON Frame</a><BR>Sensors from<BR>ESP8266 Number 4 </div>
<div id="ESPS005" style="float:left;"><a href="http://82.5.78.180/diag">Device Information Page</a><BR><a href="https://freeboard.io/board/qTP6R6">Freeboard IO Dashboard</a><BR><a href="http://82.5.78.180/jsread">GET JSON Frame</a><BR>Sensors from<BR>ESP8266 Number 5 </div>
    <div id="container">
  <style type="text/css">
  #container { height: 10%; width: 10%; display: table; }
  #gauge_div { width: 100px; margin: 0 auto; }
ESPS001, th , td {
    border: 1px solid purple;
    border-collapse: collapse;
    padding: 5px;
}
</style>
      <div id="inner">
        <div id="gauge_div"></div>
      </div>
    </div>
</div>
 <script>
$.ajax({
	 type: "GET",
	 url: "http://82.5.78.180:83/jsread",
	 async: false,
	 beforeSend: function(x) {
	  if(x && x.overrideMimeType) {
	   x.overrideMimeType("application/j-son;charset=UTF-8");
	  }
 },
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
	  }).appendTo('#ESPS001');
 }
});

   </script>
<script>
$.ajax({
	 type: "GET",
	 url: "http://82.5.78.180:93/jsread",
	 async: false,
	 beforeSend: function(x) {
	  if(x && x.overrideMimeType) {
	   x.overrideMimeType("application/j-son;charset=UTF-8");
	  }
 },
 dataType: "json",
 success: function(data){
	  var items = [];

	  $.each(data, function(key, val) {
	    items.push("<tr><td> "+ key +" </td><td> " + val + " </td></tr> ");
	  });
	
	 // $('.my-new-list').remove();	


	  $('<ul/>', {
	    'class': 'my-new-list',
	    html: items.join('')
	  }).appendTo('#ESPS002');
 }
});
   </script>
<script>
$.ajax({
	 type: "GET",
	 url: "http://82.5.78.180:92/jsread",
	 async: false,
	 beforeSend: function(x) {
	  if(x && x.overrideMimeType) {
	   x.overrideMimeType("application/j-son;charset=UTF-8");
	  }
 },
 dataType: "json",
 success: function(data){
	  var items = [];

	  $.each(data, function(key, val) {
	    items.push("<tr><td> "+ key +" </td><td> " + val + " </td></tr> ");
	  });
	
	 // $('.my-new-list').remove();	


	  $('<ul/>', {
	    'class': 'my-new-list',
	    html: items.join('')
	  }).appendTo('#ESPS003');
 }
});
   </script>
<script>
$.ajax({
	 type: "GET",
	 url: "http://82.5.78.180:81/jsread",
	 async: false,
	 beforeSend: function(x) {
	  if(x && x.overrideMimeType) {
	   x.overrideMimeType("application/j-son;charset=UTF-8");
	  }
 },
 dataType: "json",
 success: function(data){
	  var items = [];

	  $.each(data, function(key, val) {
	    items.push("<tr><td> "+ key +" </td><td> " + val + " </td></tr> ");
	  });
	
	 // $('.my-new-list').remove();	


	  $('<ul/>', {
	    'class': 'my-new-list',
	    html: items.join('')
	  }).appendTo('#ESPS004');
 }
});
   </script>
<script>
$.ajax({
	 type: "GET",
	 url: "http://82.5.78.180/jsread",
	 async: false,
	 beforeSend: function(x) {
	  if(x && x.overrideMimeType) {
	   x.overrideMimeType("application/j-son;charset=UTF-8");
	  }
 },
 dataType: "json",
 success: function(data){
	  var items = [];

	  $.each(data, function(key, val) {
	    items.push("<tr><td> "+ key +" </td><td> " + val + " </td></tr> ");
	  });
	
	 // $('.my-new-list').remove();	


	  $('<ul/>', {
	    'class': 'my-new-list',
	    html: items.join('')
	  }).appendTo('#ESPS005');
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
  var gauge_name = 'Int-Temp';

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

    // get the data from thingspeak
    $.getJSON('https://api.thingspeak.com/channels/' + channel_id + '/feed/last.json?api_key=' + api_key, function(data) {

      // get the data point
      p = data.field1;

      // if there is a data point display it
      if (p) {
       // p = Math.round((p / max_gauge_value) * 100);
        displayData(p);
      }

    });
  }

  // initialize the chart
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

</script>
<BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><div style="float:none;"><iframe width="450" height="375" style="border: 1px solid #cccccc;" src="http://api.thingspeak.com/apps/matlab_visualizations/41029" ></iframe><IMG SRC="https://raw.githubusercontent.com/genguskahn/ESP8266-For-DUMMIES/master/SoC/DimmerDocs/organicw.gif" WIDTH="450" HEIGHT="375" BORDER="1">
<BR>environmental.monitor.log@gmail.com<BR><FONT SIZE=-2>ESP8266 With Various Sensors<BR><FONT SIZE=-2>Compiled Using ver. 2.0.0-rc2, built December, 2015<BR></div>
</body>
</html>  
