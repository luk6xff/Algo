#!/usr/bin/python

from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):
    def handle_comment(self, data):
        if '\n' in data:
            print(">>> Multi-line Comment\n"+ data)
        else:
            print(">>> Single-line Comment\n"+ data)
        
            
    def handle_data(self, data):
        if not '\n' in data:
            print(">>> Data\n"+ data)  
  
    
html = ""       
for i in range(int(input())):
    html += input().rstrip()
    html += '\n'
    
parser = MyHTMLParser()
parser.feed(html)
parser.close()
