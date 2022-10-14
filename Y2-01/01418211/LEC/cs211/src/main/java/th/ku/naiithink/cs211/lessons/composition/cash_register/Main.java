package th.ku.naiithink.cs211.lessons.composition.cash_register;

public class Main {

    public static void main(String[] args) {
        Stock stock = new Stock();

        stock.addItem("Headphones", 11_999);
        stock.addItem("Keyboard", 6_900);
        stock.addItem("Mouse", 12_000);
        stock.addItem("Monitor", 4_100);
        stock.addItem("Mac mini", 22_900);
        stock.addItem("Microsoft Surface Go", 24_390);

        Register register = new Register("NAIITHINK's Store", stock.getItems());

        register.checkBill();
    }
}
