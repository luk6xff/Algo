//https://www.hackerrank.com/challenges/matrix-rotation-algo

import java.io.*;
import java.util.*;
import java.lang.*;

public class Solution {
    public static class MatrixConverter
    {
        public MatrixConverter(Scanner sc)
        {
            this.sc= sc;
        }

        public void inputMatrix(int m, int n)
        {
            this.m=m;
            this.n=n;
            numberOfMatrixes = Math.min(m,n)/2; 
            numOfRotations=sc.nextInt();
            matrix = new int[m][n];
            for(int im =0;im<m; ++im)
            {
                for(int in =0; in<n; ++in)
                {
                    matrix[im][in]=sc.nextInt();
                }    
            }
        }
            
        public void printMatrix()
        {
            for(int i =0;i<m; ++i){
                StringBuilder sb = new StringBuilder();
                for(int j =0; j<n; ++j){
                    sb.append(String.valueOf(matrix[i][j])+" ");                   
                }
                System.out.println(sb.toString());
            }    
        }
        
        public void convertMatrix()
        {
            for(int mIdx =0; mIdx<numberOfMatrixes; ++mIdx){
                int x0=m-m+mIdx; 
                int y0=n-n+mIdx;
                int x1=m-mIdx-1; 
                int y1=n-mIdx-1;
                int numOfElements= 2*(m-2*mIdx)+2*((n-2*mIdx)-2);
                
                int[] tempArr = new int[numOfElements];
                int tempArrIdx =0;
                
                for(int i=y0; i<=y1; ++i){
                    tempArr[tempArrIdx++]=matrix[x0][i];
                }                                
                for(int i=x0+1; i<=x1-1; ++i){
                    tempArr[tempArrIdx++]=matrix[i][y1];    
                }
                
                for(int i=y1; i>=y0; --i){
                    tempArr[tempArrIdx++]=matrix[x1][i];                    
                }                                

                for(int i=x1-1; i>=x0+1; --i){
                    tempArr[tempArrIdx++]=matrix[i][y0];        
                }
                
                //DEBUG
                StringBuilder sb = new StringBuilder();
                for(int j =0; j<numOfElements; ++j)
                {
                    sb.append(String.valueOf(tempArr[j])+" ");                   
                }
                //System.out.println(sb.toString());
                
                rotateArrayInLeftDirection(numOfRotations, tempArr);
                
                //DEBUG
                StringBuilder sbc = new StringBuilder();
                for(int j =0; j<numOfElements; ++j)
                {
                    sbc.append(String.valueOf(tempArr[j])+" ");                   
                }
                //System.out.println(sbc.toString());
                
                //convert to matrix again
                tempArrIdx =0;
                for(int i=y0; i<=y1; ++i){
                    matrix[x0][i]=tempArr[tempArrIdx++];
                }                                
                for(int i=x0+1; i<=x1-1; ++i){
                    matrix[i][y1]=tempArr[tempArrIdx++];
                }               
                for(int i=y1; i>=y0; --i){
                    matrix[x1][i]=tempArr[tempArrIdx++];
                }                                
                for(int i=x1-1; i>=x0+1; --i){
                    matrix[i][y0]=tempArr[tempArrIdx++];
                }
            }
                        
        }
        
        
        private void rotateArrayInLeftDirection(int numOfRotations, int[] arr)
        {
            if (arr == null || arr.length==0) {
		      throw new IllegalArgumentException("Arr cannot be empty!");
            }
            
            int len= arr.length;
            numOfRotations =numOfRotations%len;
            if(numOfRotations==len)
                return;
            int[] tempArr= new int[len];
            
            for(int i=len-1; i>=0;--i){
                int idxArr= i-len+numOfRotations;
                if(idxArr>=0)
                    tempArr[i]=arr[idxArr];
                else
                    tempArr[i]=arr[i+numOfRotations];
            }
            //DEBUG
            StringBuilder sb = new StringBuilder();
            for(int j =0; j<len; ++j)
            {
                sb.append(String.valueOf(tempArr[j])+" ");                   
            }
            //System.out.println(sb.toString());
            System.arraycopy( tempArr, 0, arr, 0, len);
        }

        
        private Scanner sc;
        private int numOfRotations;
        private int numberOfMatrixes;
        private int[][] matrix;
        private int m;
        private int n;
    }
    
    
    public static void main(String[] args) {

        Scanner sc= new Scanner(System.in);
        MatrixConverter mtxConv= new  MatrixConverter(sc);
        mtxConv.inputMatrix(sc.nextInt(),sc.nextInt());
        mtxConv.convertMatrix();
        mtxConv.printMatrix();
    }
}