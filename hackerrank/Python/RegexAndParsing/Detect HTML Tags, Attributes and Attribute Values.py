#!/usr/bin/python
import sys
import re
from html.parser import HTMLParser
if sys.version_info[0]<3: input =raw_input


class MyHTMLParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        print(tag)
        for attr in attrs:
            print("-> %s > %s"%(attr[0],attr[1]) )

html=''
for _ in range(int(input())):
    html+=input()
parser = MyHTMLParser()
parser.feed(html)
