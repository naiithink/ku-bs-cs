package th.ku.naiithink.cs211.lessons.interfaces.ii.i;

public class CarComparator
        implements MeasurableComparator<Car> {

    @Override
    public int compare(Car c1, Car c2) {
        return c1.getKiloDriven() - c2.getKiloDriven() > 0 ? 1
                                                           : c1.getKiloDriven() == c2.getKiloDriven() ? 0
                                                                                                      : -1;
    }

    @Override
    public double getNaturalValueOf(Car c) {
        return c.getKiloDriven();
    }
}
