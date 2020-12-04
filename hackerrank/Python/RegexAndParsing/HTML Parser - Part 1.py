#!/usr/bin/python
import sys
import re
from html.parser import HTMLParser
if sys.version_info[0]<3: input =raw_input


class MyHTMLParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        print("Start :", tag)
        #print(attrs)
        for attr in attrs:
            print("-> %s > %s"%(attr[0],attr[1]) )
    def handle_endtag(self, tag):
        print("End   :", tag)
    def handle_startendtag(self, tag, attrs):
        print("Empty :", tag)
        for attr in attrs:
            print("-> %s > %s"%(attr[0],attr[1]) )
file=''
for _ in range(int(input())):
    file+=input()
parser = MyHTMLParser()
parser.feed(file)