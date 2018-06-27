import urllib.request
import sys
import requests

for line in sys.stdin:
    line = line.strip()
    url = "http://services.odata.org/Northwind/Northwind.svc/Products/$count?$filter=" +line
    #print(url)
    r = requests.get(url)
    print(r.text)
