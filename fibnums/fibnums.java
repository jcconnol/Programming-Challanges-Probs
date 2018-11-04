//John Connolly
//2/13/18
//Fibonacci numbers Uva challenge

import java.util.Scanner;
import java.math.BigInteger;
import java.util.Vector;

public class Fibnums {
      public static void main(String[] args){
              Scanner sc = new Scanner(System.in);
              while(sc.hasNextLine()){
                      String[] input = new String[2];
                      input = sc.nextLine().split(" ");
                      if(input[0].equals("0") && input[1].equals("0")){
                          System.exit(0);
                      }

                      BigInteger first = new BigInteger(input[0]);
                      BigInteger second = new BigInteger(input[1]);

                      Vector<BigInteger> fibonacci = new Vector<BigInteger>(10, 2);
                      BigInteger ones = new BigInteger("1");
                      fibonacci.add(ones);
                      fibonacci.addElement(ones);

                      while(fibonacci.lastElement().compareTo(second) < 0){
                              BigInteger last_elem = fibonacci.lastElement();
                              BigInteger second_last = fibonacci.elementAt(fibonacci.size()-2);
                              fibonacci.addElement(last_elem.add(second_last));
                              //System.out.println(fibonacci.lastElement());
                      }
                      
                      int count = 0;
                      for(int i = 0; fibonacci.get(i).compareTo(second) <= 0; i++){
                              if(fibonacci.get(i).compareTo(first) >= 0)
                                      count++;
                              //fibonacci.addElement(fibonacci.lastElement().add( fibonacci.elementAt(fibonacci.size()-1) ));
                      }
                      System.out.println(count);
              }//while true end
              sc.close();
      } //ends main
}//ends fib class

