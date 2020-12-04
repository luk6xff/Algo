//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"
Complex operator +(const Complex& c1, const Complex& c2){
    
    Complex newOne;
    newOne.a = c1.a +c2.a;
    newOne.b = c1.b +c2.b;
    
    return newOne;
}

Complex operator <<(const Complex& c1, const Complex& c2){
    
    Complex newOne;
    newOne.a = c1.a +c2.a;
    newOne.b = c1.b +c2.b;
    
    return newOne;
}

ostream& operator<<(ostream& os, const Complex& c)
{
    
    os<<c.a<<"+i"<<c.b<<endl;
    return os;
    
}
