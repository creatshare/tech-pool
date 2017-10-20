/*
	比较运算符：
			==, !=,>,>=,<,<=
	特点：
		无论你的操作是简单还是复杂，结果是boolean类型
*/
class OperatorDemo {
	public static void main(String[] args){
		int x = 3;
		int y = 4;
		int z = 3;
		
		System.out.println(x == y);
		System.out.println(x == z);
		
		System.out.println((x+y) == (x=z));
		}
}