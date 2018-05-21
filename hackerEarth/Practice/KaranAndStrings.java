

import java.io.*;
import java.util.*;

class Algorithm {
    public static void main(String args[] ) throws Exception {
		
        
		Algorithm alg= new Algorithm();
		alg.doAlgorithm();		
		
	}
	
	
	/*class data */
	
	private Scanner scIn;
	private int T;
	
	public Algorithm(){
	    scIn = new Scanner(System.in);
        T=scIn.nextInt();		
		
	}
	
	public void doAlgorithm(){    	
    	while(T-->0){
       		 compute(scIn.next());	
       	}
   	}
   	private void compute(String dataset){
   		
   		StringBuilder strBd = new StringBuilder(dataset.substring(0,1));
   		
   		for(int i=1;i<dataset.length();i++){
   			
   			if(dataset.charAt(i)!=dataset.charAt(i-1)){
   				strBd.append(dataset.charAt(i));
   			}
   		}
   		
   		
    	System.out.println(strBd);
   	}
		

}

