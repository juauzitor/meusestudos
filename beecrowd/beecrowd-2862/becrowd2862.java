import java.util.Scanner;

public class becrowd2862 {
    public static void main(String[] args) {
        int n, p;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            p = sc.nextInt();
            if (p > 8000) {
                System.out.println("Mais de 8000!");
            } else {
                System.out.println("Inseto!");
            }
        }
    }
}
