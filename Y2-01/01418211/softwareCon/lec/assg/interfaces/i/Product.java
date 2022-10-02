package softwareCon.lec.assg.interfaces.i;

public class Product
        implements Measurable {

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
        return this.price - other.price;
    }

    @Override
    public <T> T measure() {
        return price;
    }
}
