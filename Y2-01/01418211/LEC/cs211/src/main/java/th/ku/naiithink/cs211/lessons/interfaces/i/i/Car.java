package th.ku.naiithink.cs211.lessons.interfaces.i.i;

public class Car
        implements Comparable<Car>,
                   Measurable<Double> {

    private String license;

    private double kiloDriven; // ระยะทางการขับ

    public Car(String license, double kiloDriven) {
        this.license = license;
        this.kiloDriven = kiloDriven;
    }

    public String getLicense() {
        return license;
    }

    public double getKiloDriven() {
        return kiloDriven;
    }

    @Override
    public String toString() {
        return "Car [kiloDriven=" + kiloDriven + ", license=" + license + "]";
    }

    @Override
    public int compareTo(Car other) {
        if (this.kiloDriven > other.kiloDriven)
            return 1;
        else if (this.kiloDriven < other.kiloDriven)
            return -1;
        return 0;
    }

    @Override
    public Double measure() {
        return kiloDriven;
    }
}
