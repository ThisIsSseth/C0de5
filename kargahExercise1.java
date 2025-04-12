import java.util.Scanner;
import java.util.Stack;

public class kargahExercise1 {
    public static void main(String[] args) {
//        int[] number = {0, 1, 8, 9};
//        for (int i : number){
//            System.out.println(number[i]);
//        }
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String paren = sc.nextLine();
        System.out.println((Parentheses(paren)) ? "Alright" : "Sth wrong with the parentheses");
    }

    public static boolean Parentheses(String string) {
        Stack<Character> parenStack = new Stack<>();
        byte counter = 0;

        for (int i = 0; i < string.length(); i++) {
            if (string.charAt(i) == '(')
                parenStack.push('(');
            else if (string.charAt(i) == ')')
                try {
                    parenStack.pop();
                }
            catch (Exception e) {
                    return false;
            }
            }
        return parenStack.empty();
        }
    }
//    public static void StackBeginner(String string) {
//        Stack<Integer> numNUm = new Stack<>();
//        numNUm.push(5);
//        numNUm.push(7);
//        System.out.println(numNUm.peek());
//    }
//}


//a practice of stack