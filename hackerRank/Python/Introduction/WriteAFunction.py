def is_leap(year):
    leap = False
    
    if year < 1900 or year >100000:
        leap = False
    else:
        if year%4==0: 
            leap = True
        if year%100==0:
            leap =False
            if year%400==0:
                leap =True
    return leap
