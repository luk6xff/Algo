
#/********************************************/

#/**The Minion Game*******/

#/********************************************/
def isVovel(letter):
    if (letter=='A' or letter=='E' or letter=='I' or letter=='O' or letter=='U'):
        return True
    return False

def countAllResult(word):
    sumK=0
    sumS=0
    for i in range(len(word)):
        if (isVovel(word[i])):
            sumK=sumK+len(word)-i
        else:
            sumS=sumS+len(word)-i
    if(sumS>sumK):
        print("Stuart "+str(sumS))
    elif(sumS<sumK):
        print("Kevin "+str(sumK))
    else:
        print("Draw")
      
word =input()
countAllResult(word)
