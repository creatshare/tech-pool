/*
	99乘法表

*/
import java.util.Scanner;

class FunctionTest5 {
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("请输入n的值：（1~9）");
		int n = sc.nextInt();
		
		printNN(n);
	}
	
	public static void printNN(int n) {
		for(int x=1; x<=n; x++){
			for(int y=1; y<=x; y++){
				System.out.println(y+"*"+x+"="+y*x+"\t");
			}
		}
	}
}
