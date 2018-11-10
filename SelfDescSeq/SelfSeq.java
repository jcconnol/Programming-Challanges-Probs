//John Connolly
//2/13/18
//Self Describing Sequence Uva challenge

import java.util.Scanner;
import java.math.BigInteger;
import java.util.Vector;

public class SelfSeq {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger sequen[] = new BigInteger[700000];
		BigInteger highest = new BigInteger("2000000000");
		
		sequen[0] = new BigInteger("1");
		sequen[1] = new BigInteger("2");
		sequen[2] = new BigInteger("4");
		
		int i;
		for(i = 1; sequen[ sequen[i].subtract(BigInteger.valueOf(1)).intValue() ].compareTo(highest) < 0; i++) {
			
			for(int j = sequen[i].intValue(); j < sequen[i+1].intValue(); j++) {
				BigInteger add = sequen[j - 1].add(BigInteger.valueOf(i).add(BigInteger.valueOf(1)));
				sequen[j] = add;
			}
		}
		
		//for(int j = 0; j < 15; j++)
		//	System.out.println(sequen[j].toString());
		
		
		while(sc.hasNextLine()) {
			String input = sc.nextLine();
			BigInteger input_num = new BigInteger(input);
			
			if(input_num.equals(BigInteger.valueOf(0))) {
				break;
			}
			
			int n = 0;
			
			while(input_num.compareTo(sequen[n+1]) >= 0) {
				if(input_num.compareTo(sequen[n]) < 0) {
					break;
				}
				n++;
			}
			
			System.out.println(n+1);
		}
		
		sc.close();
	}
}
