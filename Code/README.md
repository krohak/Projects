# Code

## HKU

A script for [lazy] students from HKU to enroll in the pre-selected courses (from the temporary course list) during the add/drop period. Since I didn't have access to the internet during the latest add/drop period, I wrote this code and scheduled it to run on a server.

Takes 'HKU Portal UID' and 'Password' as the command line arguments.

## NIFTY

A web scraping program to plot the growth of [LTP](http://budgeting.thenest.com/ltp-stock-market-26186.html) (Last Trade Price) over time for given [Strike Prices](http://www.investopedia.com/terms/s/strikeprice.asp) of [NIFTY](https://en.wikipedia.org/wiki/NIFTY_50) on The National Stock Exchange of India's [website](https://www.nseindia.com/).

[<img src="https://raw.githubusercontent.com/krohak/Projects/master/Code/NIFTY/ltpgrowth.JPG" width="800px">](https://raw.githubusercontent.com/krohak/Projects/master/Code/NIFTY/ltpgrowth.JPG)

It takes data (Strike Price and its Expiry) from two Excel sheets ([CALL.xlsx](https://github.com/krohak/Projects/blob/master/Code/NIFTY/CALL.xlsx) and [PUT.xlsx](https://github.com/krohak/Projects/blob/master/Code/NIFTY/PUT.xlsx)), finds the corresponding [table](https://www.nseindia.com/live_market/dynaContent/live_watch/option_chain/optionKeys.jsp?symbolCode=-10003&symbol=NIFTY&symbol=NIFTY&instrument=-&date=-&segmentLink=17&symbolCount=2&segmentLink=17) on the website and appends the multiple LTPs and the present day's NIFTY value in those excel sheets. Lastly, it outputs two graphs inside [CALLchart.xlsx](https://github.com/krohak/Projects/blob/master/Code/NIFTY/CALLchart.xlsx) and [PUTchart.xlsx](https://github.com/krohak/Projects/blob/master/Code/NIFTY/PUTchart.xlsx) which outlines the growth of LTPs of the various Strike Prices over time.

Uses [BeautifulSoup](https://www.crummy.com/software/BeautifulSoup/) and [Openpyxl](https://openpyxl.readthedocs.io/en/default/).
