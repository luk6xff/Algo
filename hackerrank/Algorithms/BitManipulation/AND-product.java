import java.io.*;
import java.util.*;

public class Solution {

    
	public static void main(String ards[])
	{
		Scanner scanner=new Scanner(new InputStreamReader(System.in));
		int noOfTestCases=scanner.nextInt();
		for (int i = 0; i < noOfTestCases; i++) {
			long A=scanner.nextLong();
			long B=scanner.nextLong();
			long output=B;
			for (long j = A; j <B; j++) {
				output=output & j;
			}
			System.out.println(output);
		}
	}
}