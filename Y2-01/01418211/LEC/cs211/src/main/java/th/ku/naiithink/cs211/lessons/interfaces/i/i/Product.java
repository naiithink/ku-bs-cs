package th.ku.naiithink.cs211.lessons.interfaces.i.i;

public class Product
        implements Comparable<Product>,
                   Measurable<Double> {

    private String name;

    private double price; // ราคา

    public Product(String name, double price) {
        this.name = name;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }

    @Override
    public String toString() {
        return "Product [name=" + name + ", price=" + price + "]";
    }

    @Override
    public int compareTo(Product other) {
        if (this.price > other.price)
            return 1;
        else if (this.price < other.price)
            return -1;
        return 0;
    }

    @Override
    public Double measure() {
        return price;
    }
}
