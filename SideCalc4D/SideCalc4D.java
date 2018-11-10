import java.util.Scanner;
import java.math.BigInteger;

public class SideCalc4D {
	
	@SuppressWarnings("resource")
	public static void main(String [] args) {
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNextInt()) {
			int input = sc.nextInt();
			
			BigInteger dimen1 = BigInteger.ZERO;	
			BigInteger dimen2 = BigInteger.ZERO;
			BigInteger dimen3 = BigInteger.ZERO;
			
			for(int i = 0; i < input; i++) {
				BigInteger incre = BigInteger.valueOf(i+1);
				
				dimen1 = dimen1.add((incre.pow(2)));
				dimen2 = dimen2.add((incre.pow(3)));
				dimen3 = dimen3.add((incre.pow(4)));
			}
			
			BigInteger holder = BigInteger.valueOf(input * (input+1)/2);
			
			BigInteger depth1 = BigInteger.ZERO;
			BigInteger depth2 = BigInteger.ZERO;
			BigInteger depth3 = BigInteger.ZERO;
			
			depth1 = holder.pow(2).subtract(dimen1);			
			depth2 = holder.pow(3).subtract(dimen2);
			depth3 = holder.pow(4).subtract(dimen3);
			
			System.out.println(dimen1.toString() + " "
					+ depth1.toString() + " "
					+ dimen2.toString() + " "
					+ depth2.toString() + " "
					+ dimen3.toString() + " "
					+ depth3.toString());
		}
	}
	
}
