import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int N= sc.nextInt();
        int M=sc.nextInt();
        
        long[] crushArr= new long[N+1];
        for(int i=0; i<M; i++)
        {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int k = sc.nextInt();
            crushArr[a-1]+=k;
            crushArr[b]-=k;
        }
        
        long sum=0;
        long maxSum=0;
        for(int i=0; i<N; i++)
        {
            sum+=crushArr[i];
            if(maxSum<sum)
               maxSum=sum;
        }
        System.out.println(maxSum);        
    }
}