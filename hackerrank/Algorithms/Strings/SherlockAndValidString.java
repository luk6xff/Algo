/********************************************/
/**Sherlock and Valid String*******/
/********************************************/ 
import java.io.*;
import java.util.*;
import java.lang.Character.*;

class Solution {

    static void solution(String str) {
        if(str==null||str.length()==0)
            return;
        Map<Character,Integer> hMap = new HashMap<Character,Integer>();
        for (int i = 0; i < str.length(); i++){
            char c = str.charAt(i); 
            if(!hMap.containsKey(Character.valueOf(c)))
                hMap.put(Character.valueOf(c), 1);
            else{
               Integer val= hMap.get(Character.valueOf(c)); 
               val+=1;
               hMap.put(Character.valueOf(c), val);
            }
        }
        ArrayList<Integer> values = new ArrayList<Integer>(); 
        Iterator<Character> keySetIterator = hMap.keySet().iterator(); 
        while(keySetIterator.hasNext()){ 
            Character key = keySetIterator.next(); 
            values.add(hMap.get(key));
            //System.out.println("key: " + key + " value: " + hMap.get(key));             
        }
        Collections.sort(values,Collections.reverseOrder());
        String resp= "NO";
        if(values.size()==1||(values.get(0)-values.get(values.size()-1))==0){
          resp="YES";  
        }
        else if(values.get(0)-values.get(values.size()-1)>0){
            if(values.get(0).equals(values.get(values.size()-2)))
                resp="YES";
            else if(values.get(1).equals(values.get(values.size()-1)))
                resp="YES";
            else
                resp="NO";
        }

        else
            resp="YES";  
        
        System.out.println(resp);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str;
        str= in.next();
        //System.out.println(str);
        solution(str);     
    }
}