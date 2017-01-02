from bs4 import BeautifulSoup
from httplib2 import Http
import re
from time import strftime
import csv

date = strftime("%d-%b-%Y")

#expiry = "30MAR2017"

def find_site(expiry):

	(resp_headers, content) = Http().request(("https://www.nseindia.com/live_market/dynaContent/live_watch/option_chain/optionKeys.jsp?segmentLink=17&instrument=OPTIDX&symbol=NIFTY&date="+ expiry),"GET", headers={'Accept':'*/*','Accept-Encoding':'gzip, deflate, sdch','Accept-Language':'en-US,en;q=0.8,en-GB;q=0.6','Cache-Control':'max-age=0','Connection':'keep-alive','Host':'www.nseindia.com','If-Modified-Since':'Thu,03 Apr 2014 11:27:44 GMT','If-None-Match':'"13309-533d45b0"','Referer':'https://www.nseindia.com/live_market/dynaContent/live_watch/option_chain/optionKeys.jsp?symbolCode=-10006&symbol=NIFTY&symbol=NIFTY&instrument=-&date=-&segmentLink=17&symbolCount=2&segmentLink=17','User-Agent':'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/49.0.2623.87 Safari/537.36'})

	soup = BeautifulSoup(content, "html.parser")

	nifty = soup.find('b',string=re.compile("NIFTY"))
	nifty = nifty.text


	section = soup.find('table', id = 'octable')	#find data table
	return section,nifty


def find_LTP(x, y,section):

	for tr in section.find_all('tr'):   #each row

		tds = tr.find_all(href=re.compile(".*=" + x + "\..*" + y))              #data cell

		tds = [ele.text for ele in tds]


		if tds != []:
			tds = tds[0].split()	#remove extra space before data
			#print(tds[0])
			return tds[0]




"""
function to open a .csv file, get the strike prices from it,
retireve LTPs from nseindia.com and store them in the same file
"""

def CSV_read_write(csvin,c):

	with open(csvin, 'r') as csvfile:

		reader = csv.DictReader(csvfile)
		data = []			#to store strike prices
		for row in reader:
			data.append(row["Strike Price"])
		print(data)

	with open(csvin, 'r') as csvfile:

		reader = csv.DictReader(csvfile)
		exp = []			#store expiry dates
		for row in reader:
			exp.append(row["Expiry"])
		print(exp)

		ltp= []
		"""
		for sp in data:
			ltp.append(find_LTP(sp,c,section))	#store ltps
		"""
		i = 0
		while i != len(data):
			(section,nifty) = find_site(exp[i])
			ltp.append(find_LTP(data[i],c,section))
			i+=1

		reader = csv.reader(csvfile)			#read rows and append ltp
		all = []
		csvfile.seek(0)
		row = next(reader)
		row.append(date + ", " + nifty) 				#NIFTY: {0}".format(nifty))
		row0 = row
		#print(row)
		all.append(row)

		i = 0
		for row in reader:
			row.append(ltp[i])
			all.append(row)
			i+=1                  #for item in r, item.append



		#write to file
	with open(csvin,'w') as csvoutput:

		writer = csv.writer(csvoutput)
		writer.writerows(all)


#(section,nifty) = find_site(expiry)
CSV_read_write("CE.csv","CE")
CSV_read_write("PE.csv","PE")
