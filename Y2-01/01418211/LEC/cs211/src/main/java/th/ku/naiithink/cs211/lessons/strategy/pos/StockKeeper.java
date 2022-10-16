package th.ku.naiithink.cs211.lessons.strategy.pos;

public class StockKeeper {

    private static final CountingStrategy<Product> countAllProduct = products -> products.size();

    private static final CountingStrategy<Product> countProductInStock = products -> {
        return (int) products.stream()
                             .mapToInt(product -> product.getQuantity())
                             .filter(quantity -> quantity > 0)
                             .count();
    };

    private static final CountingStrategy<Product> countProductQuantity = products -> products.stream()
                                                                                              .mapToInt(product -> product.getQuantity())
                                                                                              .sum();

    public static void main(String[] args) {
        Store store = new Store();
        store.addProduct("Big Java", 300, 5);
        store.addProduct("Da Vinci Code", 120, 0);
        store.addProduct("Python 101", 200, 10);

        System.out.println("All products: " + store.countProduct(countAllProduct));
        System.out.println("All in-stock: " + store.countProduct(countProductInStock));
        System.out.println("All of them: " + store.countProduct(countProductQuantity));
    }
}
