import java.util.Scanner;

public class SimpleCalculator {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String option;
        
        do {
            System.out.println("Select operation:");
            System.out.println("1. Addition");
            System.out.println("2. Subtraction");
            System.out.println("3. Multiplication");
            System.out.println("4. Division");
            System.out.println("5. Exit");
            System.out.print("Enter your choice (1-5): ");
            option = scanner.nextLine();
            
            switch (option) {
                case "1":
                    performOperation(scanner, "addition");
                    break;
                case "2":
                    performOperation(scanner, "subtraction");
                    break;
                case "3":
                    performOperation(scanner, "multiplication");
                    break;
                case "4":
                    performOperation(scanner, "division");
                    break;
                case "5":
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid option, please try again.");
            }
            
        } while (!option.equals("5"));
        
        scanner.close();
    }

    private static void performOperation(Scanner scanner, String operation) {
        System.out.print("Enter the first number: ");
        double num1 = scanner.nextDouble();
        System.out.print("Enter the second number: ");
        double num2 = scanner.nextDouble();
        scanner.nextLine();  // Consume newline

        switch (operation) {
            case "addition":
                System.out.println("Result: " + (num1 + num2));
                break;
            case "subtraction":
                System.out.println("Result: " + (num1 - num2));
                break;
            case "multiplication":
                System.out.println("Result: " + (num1 * num2));
                break;
            case "division":
                if (num2 != 0) {
                    System.out.println("Result: " + (num1 / num2));
                } else {
                    System.out.println("Error: Division by zero is not allowed.");
                }
                break;
        }
    }
}
