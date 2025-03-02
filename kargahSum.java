import java.util.Scanner;

public class kargahSum {
    public static void main(String[] args) {

        oddEven();
    }
    public static void oddEven(){
        System.out.println("Enter any number: ");
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        int sum;
        if ( number % 2 == 0) {
            sum = number;
        }
        else {
            sum = number - 1;
        }
        for (int i = 2; i < number; i+= 2) {
            sum += i;
        }
        System.out.println(sum);
        sc.close();
    }
}


