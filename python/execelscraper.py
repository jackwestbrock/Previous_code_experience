import urllib.request as url
from bs4 import BeautifulSoup 
from openpyxl import Workbook

import ssl
ssl._create_default_https_context = ssl._create_unverified_context

#https://www.w3schools.com/html/html_elements.asp

root = 'https://www.nfl.com/stats/player-stats/category/field-goals/2021/post/all/kickingfgmade/desc'
html = url.urlopen(root)

bs = BeautifulSoup(html,'html.parser')
#print(bs.prettify())

sheet_data = []

for table in bs.find_all('table'):
    for tr in table.find_all('tr'):
        row = []
        for th in tr.find_all('th'):
            row.append(th.getText())
        for td in tr.find_all('td'):
            row.append(td.getText())
        sheet_data.append(row)
     
#print(sheet_data)

book = Workbook()
sheet = book.active

for i in sheet_data:
    sheet.append(i)

book.save('w3_info.xlsx')