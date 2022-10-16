package th.ku.naiithink.cs211.lessons.strategy.pos;

import java.util.ArrayList;
import java.util.List;

public class Store {

    private List<Product> products;

    public Store() {
        products = new ArrayList<>();
    }

    public void addProduct(String name, double price, int quantity) {
        products.add(new Product(name, price, quantity));
    }

    public int countProduct(final CountingStrategy<Product> counter) {
        return counter.count(products);
    }

    // // นับจํานวนสินค้าทั้งหมด ทั้งมีในสต็อคหรือหมดสต็อคแล้ว
    // public int countAllProduct() {
    //     int count = 0;
    //     for (Product prod : products) {
    //         count += 1;
    //     }
    //     return count;
    // }

    // // นับจํานวนสินค้าทั้งหมดที่มีเหลืออยู่ในสต็อค
    // public int countProductInStock() {
    //     int count = 0;
    //     for (Product prod : products) {
    //         if (prod.getQuantity() > 0)
    //             count += 1;
    //     }
    //     return count;
    // }

    // // นับจํานวนในสต็อคของสินค้าทั้งหมด
    // public int countProductQuantity() {
    //     int count = 0;
    //     for (Product prod : products) {
    //         count += prod.getQuantity();
    //     }
    //     return count;
    // }
}
