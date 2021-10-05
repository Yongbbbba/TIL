#  점프투자바 연습 문제

## 구구단

```java
package jump2java;

import java.util.Scanner;

public class GuGu {
	
	public GuGu(int dan) {
		for (int i=1; i<=9; i++) {
			System.out.printf("%d x %d = %d\n", dan, i, dan * i);
		}
		System.out.println();
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int dan = sc.nextInt();
		
		GuGu printGuGu = new GuGu(dan);
	}
}

```



## Multiples of 3 and 5

```java
package jump2java;

public class multiplesof3and5 {

	public static void main(String[] args) {
		final int problem = 1000;
		int answer = 0;
		for (int i=1;i<1000; i++) {
			if (i % 3 == 0 || i % 5 == 0) {
				answer += i;
			}
		}
		
		System.out.println(answer);
	}

}
```

