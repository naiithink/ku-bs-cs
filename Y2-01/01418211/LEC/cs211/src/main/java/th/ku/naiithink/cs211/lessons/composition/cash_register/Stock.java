package th.ku.naiithink.cs211.lessons.composition.cash_register;

import java.util.HashMap;
import java.util.Map;

public class Stock {

    private Map<String, Double> items;

    public Stock() {
        this.items =  new HashMap<>();
    }

    public Map<String, Double> getItems() {
        return items;
    }

    public void addItem(String title, double price) {
        items.put(title, price);
    }

    public void removeItem(String title) {
        items.remove(title);
    }
}
