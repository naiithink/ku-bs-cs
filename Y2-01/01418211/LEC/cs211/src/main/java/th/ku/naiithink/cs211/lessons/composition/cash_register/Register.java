package th.ku.naiithink.cs211.lessons.composition.cash_register;

import java.io.Console;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

public class Register {

    private final String STORE_NAME;

    private Console console;

    private Map<String, Double> stock;

    public Register(String storeName, Map<String, Double> stock) {
        this.STORE_NAME = storeName;
        this.console = System.console();
        this.stock = stock;
    }

    private void printStock() {
        System.out.println("""
            Available items:
            ----------------------------------------""");

        for (Entry<String, Double> entry : stock.entrySet())
            System.out.format("%-30s%10.2f\n", entry.getKey(), entry.getValue());

        System.out.println("----------------------------------------");
    }

    public void checkBill() {
        Map<String, Integer> bag = new HashMap<>();

        double total = 0.0;
        String input1 = ""; 
        String input2 = "";

        printStock();

        while (true) {
            input1 = console.readLine("%s", "Item: ");

            if (stock.containsKey(input1) == false) {
                System.out.println("Sorry, item does not exist.");
                continue;
            }

            input2 = console.readLine("%s", "Amount: ");

            bag.put(input1, Integer.parseInt(input2));
            total += stock.get(input1) * Integer.parseInt(input2);

            if (console.readLine("%s", "Check out? [y/N]: ").toLowerCase().equals("y"))
                break;
        }

        System.out.println("========================================\nINVOICE\n----------------------------------------");
        System.out.println(STORE_NAME + "\n");
        System.out.format("%-30s\t%8s\t%4s\t%8s\n", "Description", "Price", "Qty", "Subtotal");

        for (String item : bag.keySet())
            System.out.format("%-30s\t%8.2f\t%4d\t%8.2f\n", item, stock.get(item), bag.get(item), stock.get(item) * bag.get(item));

        System.out.format("\nTOTAL TO PAY: ฿%.2f\n========================================\n", total);
    }
}
