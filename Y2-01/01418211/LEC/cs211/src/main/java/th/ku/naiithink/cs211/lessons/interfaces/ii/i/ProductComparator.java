package th.ku.naiithink.cs211.lessons.interfaces.ii.i;

public class ProductComparator
        implements MeasurableComparator<Product> {

    @Override
    public int compare(Product p1, Product p2) {
        return p1.getPrice() - p2.getPrice() > 0 ? 1
                                                 : p1.getPrice() == p2.getPrice() ? 0
                                                                                  : -1;
    }

    @Override
    public double getNaturalValueOf(Product p) {
        return p.getPrice();
    }
}
