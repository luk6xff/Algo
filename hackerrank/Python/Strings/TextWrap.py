#/********************************************/

#/**Text Wrap*******/

#/********************************************/
import textwrap
S = str(input())
w= int(input())

wrappedTxt= textwrap.wrap(S,w)
print(textwrap.fill(S,w))
