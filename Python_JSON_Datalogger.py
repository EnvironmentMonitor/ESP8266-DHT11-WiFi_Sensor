import urllib2
import datetime
import time
while (True):
# My IP List for ESP hosted sensors, some with specific ports
# adjust for your list of IP adresses
 IpList = ["6","7","12:100","15:81","16"]
 now = datetime.datetime.now()
 timeString = now.strftime("%H:%M:%S %d-%m-%Y")
 f = open("whatever", "a")
 f.write(timeString+",")
 f.write("\r\n")
 f.close()
 for IpL in IpList:
  import json
  reqL="http://192.168.1." + IpL + "/jsread"
  print "Making Request  !"
  req = urllib2.Request(reqL)
  opener = urllib2.build_opener()
  f = opener.open(req)
  json = json.loads(f.read())
  print "Request Done !"
# My list of JSON key's customise for the frame being read
  LiSt = ['temperature','humidity','dewpoint']
  f = open("whatever", "a")
  for items in LiSt:
   f.write(str(json[items]).strip('[]')+",")
  f.write("\r\n")
  f.close()
  print "Save Done!"
 time.sleep(60)
