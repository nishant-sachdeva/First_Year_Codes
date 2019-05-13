from bs4 import BeautifulSoup
import requests

n = int(sys.argv[1])
path = sys.argv[2]


r=requests.get("https://www.smbc-comics.com/comic/2007-02-03")

soup = BeautifulSoup(r.text)

# textLink=r.data
for name in soup.find_all('div', class_ = "name"):
