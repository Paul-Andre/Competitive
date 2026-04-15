//package codeforces.c2217;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int t = scan.nextInt();
		for (int ttt=0; ttt<t; ttt++) {
			int n, k;
			n = scan.nextInt();
			k = scan.nextInt();
//			System.out.println(n+","+k);
			List<Integer> A = new ArrayList<>();
			for (int kkk=0; kkk<n; kkk++) {
				A.add(scan.nextInt());
			}
			int sum = 0;
			for (Integer i: A) {
				sum+=i;
			}
			int sum2 = k*n;
			if (sum%2==1 || sum2%2==0) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
//			System.out.println("Finsihed one loop");
		}
//		System.out.println("Finished");
	}

}
